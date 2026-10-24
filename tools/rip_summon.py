"""Rip what the game draws while a hero casts a spell: for every video frame of the cast the caster body pieces (hero list 1, `$7E:E090`), the effect pieces of the
same hero (list 2, `$7E:E0D0`: the spark, the spirit, the spell effect pieces) and the sprites of other objects are rendered separately into transparent PNGs; the frame data
(state bytes, animation frame index, sound requests, MP, the target's HP) goes to JSON. Everything is written to a directory chosen by the caller, never into the repository.
usage: rip_summon.py ROM STATE OUTDIR [--hero boy|girl|sprite] [--spells 0x0C,0x03|all] [--dirs down,up,right,left] [--level N] [--weapon-row 0] [--baseline GLOVE_RIPDIR] [--label NAME] [--targets N] [--target-dx N] [--ally-slot N] [--ally-dx N] [--ally-dy N] [--target-dy N] [--max 700] [--quiet 45] [--hurt]
The state must hold the three heroes (zs3-like); the caster is the hero slot given by --hero (default girl: the boy of the usual saves has no MP), the other heroes are switched
off. Hostile spells (row byte 8 bit 7) get a passive monster at (0, target-dy) from the hero, the other spells target the caster. The cast is started the way the ring menu ends
(`summon_sim.Sim.cast`), so the whole sequence of the real code runs: `$C1:88C7` sets the pose, the hero's animation script and the effect scripts do the rest.
Output: OUTDIR/<hero>/s<ID>_<dir>/frames.json plus PNGs `c<nnn>.png` (caster), `f<nnn>.png` (effect), `h<nnn>.png` (caster and effect together, in OAM order), `w<nnn>.png` (weapon pieces, with --baseline), `t<nnn>.png` (effect pieces on the target), `o<nnn>.png` (other objects). Pictures are cropped to their bounding box;
`origin` is the hero foot point (+0x20/+0x22) inside an uncropped 256x224 screen, a picture has `x`, `y` = its top-left corner relative to the foot point."""
import sys, os, json, hashlib
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import romio, summon_sim as SS, gfx_decode as G

HZ = SS.HZ
HEROES = ('boy', 'girl', 'sprite')
HUD_TILES = (0x1E8, 0x1EA, 0x1EC)
DIGIT_TILES = (200, 202, 204)
OBJ_BASE, NAME_GAP = 0x6000, 0x1000


def crop_png(img, path, cache, foot):
    """Write the cropped picture (deduplicated by content) and return (file, x, y) with x, y relative to the foot point; None when the layer is empty."""
    box = img.bbox()
    if box is None: return None
    c = img.crop(*box)
    key = path[1] + hashlib.sha1(bytes(c.px) + bytes((c.w & 255, c.w >> 8, c.h & 255, c.h >> 8))).hexdigest()
    if key not in cache:
        name = '%s%03d.png' % (path[1], len([k for k in cache if k.startswith(path[1])]))
        G.write_png(os.path.join(path[0], name), c); cache[key] = (name, c.w, c.h)
    name, w, h = cache[key]
    return dict(file=name, x=box[0] - foot[0], y=box[1] - foot[1], w=w, h=h)


def classify(sim, ents, hero_base, ally_bases=(), ally_own=frozenset()):
    """Split the visible OAM entries into caster / effect / other / HUD by the object that wrote them; the effect pieces drawn through the second list of a
    hero that is a target of the cast (`ally_bases`) count as effect pieces on the target."""
    cas, fx, oth, tgt = [], [], [], []
    for e in ents:
        if e['y'] >= 224 and e['y'] + 16 <= 256: continue
        if e['y'] >= 190 and e['tile'] in HUD_TILES: continue
        ow = sim.c.owner.get(e['i'])
        if ow and ow[0] == hero_base and ow[1] in ('90', 'D0'):
            if ow[1] == '90': cas.append(e)
            elif e['tile'] == 0: continue                      # the ground shadow (tile 0, palette 1)
            else: fx.append(e)
        elif ow and ow[1] == 'D0' and ow[0] in ally_bases:                             # effect pieces drawn through the second list of a hero target
            if e['tile'] != 0 and e['tile'] not in DIGIT_TILES and (ow[0], e['tile'], e['x'] - sim.env.obj(ow[0] >> 9).w(0x20), e['y'] - sim.env.obj(ow[0] >> 9).w(0x22)) not in ally_own: tgt.append(e)
        elif ow and ow[1] == 'D0' and 0x600 <= ow[0] < 0x1000:                       # effect pieces drawn through a monster's second list (hit effects on the target)
            if e['tile'] != 0 and e['tile'] not in DIGIT_TILES: tgt.append(e)
        elif ow and ow[1] in ('90', 'D0') and (0x600 <= ow[0] < 0x1000 or ow[0] in (0, 0x200, 0x400)): continue      # the monster bodies and the other heroes
        elif ow and ow[1] in ('90', 'D0') and ow[0] != hero_base and ow[0] < 0x400 and e['tile'] == 0: continue
        else: oth.append(e)
    return cas, fx, oth, tgt


def render(sim, ents):
    return G.render(ents, sim.c.vram, sim.c.cgram, OBJ_BASE, NAME_GAP, 16, 32)


def sprite_rows(cgram):
    return {r: [cgram[256 + 32 * r + 2 * k] | cgram[256 + 32 * r + 2 * k + 1] << 8 for k in range(16)] for r in range(8)}


def rip_cast(rom, state, slot, spell, facing, outdir, level=None, weapon_row=0, target_dy=None, max_frames=700, hostile=None, extra=None, baseline=None, target_dx=0, targets=None, ally_slot=None, ally_offset=(40, 0), quiet_frames=45, residue=None, hurt=False):
    """Rip one cast into `outdir`; with `outdir` None only the pieces a hero target still draws through its second list at the end are returned (the
    pieces that are its own and not part of the effect, removed from the target layer of the real rip)."""
    probe = outdir is None
    if ally_slot is not None and residue is None and not probe:
        residue = rip_cast(rom, state, slot, spell, facing, None, level, weapon_row, target_dy, max_frames, hostile, None, None, target_dx, targets, ally_slot, ally_offset, quiet_frames, None, hurt)
    row = rom[0x102AD0 + spell * 64:0x102AD0 + spell * 64 + 64]
    if hostile is None: hostile = bool(row[8] & 0x80)
    sim = SS.Sim(rom, state, slot, keep=tuple(k for k in range(3) if k != slot) if ally_slot is not None or (targets or 1) > 1 and not hostile else ())
    for _ in range(20): sim.frame()
    w = sim.w; B = sim.base - 0xE000; hero_base = sim.base - 0xE000
    if weapon_row is not None: sim.equip(weapon_row)
    sim.face(facing)
    if w[B + 0xE186] < 50: w[B + 0xE186] = w[B + 0xE187] = 99
    if target_dy is None: target_dy = -70 if sim.screen_xy()[1] >= 110 else 70      # the target must be on the screen (valid-target test of $D0:DA60)
    if ally_slot is not None:
        ally = sim.env.obj(ally_slot); me = sim.env.obj(slot)
        ally.sw(2, me.w(2) + ally_offset[0]); ally.sw(4, me.w(4) + ally_offset[1])
    ntg = targets or 1
    mons = [sim.spawn_monster(target_dx + (0, -50, 50)[i], target_dy, slot=3 + i) for i in range(ntg)] if hostile else []
    mon = mons[0] if mons else None
    for _ in range(3): sim.frame()
    if not probe: os.makedirs(outdir, exist_ok=True)
    cache = {}
    base_frames = json.load(open(os.path.join(baseline, 'frames.json')))['frames'] if baseline else None
    f0 = sim.f; n0 = len(sim.sounds); mp0 = w[B + 0xE186]
    if hostile: cast_targets = [3 + i for i in range(ntg)]
    elif ally_slot is not None: cast_targets = [ally_slot]
    else: cast_targets = [slot] + [k for k in range(3) if k != slot][:ntg - 1]
    ally_bases = tuple(0x200 * t for t in cast_targets if t < 3 and t != slot)
    ally_own = set()                                       # the pieces a hero target draws through its second list on its own (tile and place about its foot)
    for _ in range(5 if ally_bases else 0):
        sim.frame()
        for e in G.oam_entries(sim.c.oam):
            ow = sim.c.owner.get(e['i'])
            if ow and ow[1] == 'D0' and ow[0] in ally_bases: o = sim.env.obj(ow[0] >> 9); ally_own.add((ow[0], e['tile'], e['x'] - o.w(0x20), e['y'] - o.w(0x22)))
    ally_own = frozenset(ally_own | (residue or set()))
    if hurt:                                                                                 # hero targets at half HP, so that a heal shows when it lands
        for t in cast_targets:
            if t < 3: o = sim.env.obj(t); o.sw(0x182, o.w(0x184) // 2)
    f0 = sim.f; n0 = len(sim.sounds)
    sim.cast(spell, cast_targets, level=level)
    target_objs = [sim.env.obj(t) for t in cast_targets]
    frames = []; apply = None; quiet = 0; idle_at = None; last_tb = None; seen = []
    foot = (w[B + 0xE020] | w[B + 0xE021] << 8, w[B + 0xE022] | w[B + 0xE023] << 8)
    for k in range(max_frames):
        sim.c.regs.clear(); sim.c.hdma = 0
        sim.frame()
        ents = G.oam_entries(sim.c.oam)
        cas, fx, oth, tgt = classify(sim, ents, hero_base, ally_bases, ally_own)
        fp = (w[B + 0xE020] | w[B + 0xE021] << 8, w[B + 0xE022] | w[B + 0xE023] << 8)
        rec = dict(k=k, st60=w[B + 0xE060], st1C=w[B + 0xE01C], anim=w[B + 0xE011], fi=(w[B + 0xE026] | w[B + 0xE027] << 8) // 2, flags=w[B + 0xE028],
                   script=w[B + 0xE016] | w[B + 0xE017] << 8, mp=w[B + 0xE186], z=w[B + 0xE045], wx=w[B + 0xE002] | w[B + 0xE003] << 8, wy=w[B + 0xE004] | w[B + 0xE005] << 8,
                   foot=list(fp), hp=w[B + 0xE182] | w[B + 0xE183] << 8)
        if mon: rec['mon_hp'] = mon.w(0x182); rec['mon_xy'] = [mon.w(2), mon.w(4)]
        rec['tfoot'] = [[o.w(0x20), o.w(0x22)] for o in target_objs]                 # screen foot point of every target of the cast
        rec['thp'] = [o.w(0x182) for o in target_objs]
        rec['tstat'] = [o.w(0x190) for o in target_objs]
        tb = [bytes(w[o.base + 0x180:o.base + 0x200]).hex() for o in target_objs]                  # combat bytes of the targets, written when they change
        if tb != last_tb: rec['tbytes'] = tb; last_tb = tb
        if apply is None and w[B + 0xE186] != mp0: apply = k
        if probe:
            seen.append({(sim.c.owner[e['i']][0], e['tile'], e['x'] - sim.env.obj(sim.c.owner[e['i']][0] >> 9).w(0x20), e['y'] - sim.env.obj(sim.c.owner[e['i']][0] >> 9).w(0x22)) for e in tgt})
            quiet = quiet + 1 if rec['st1C'] == 0 and rec['st60'] == 0 and k > 20 and not oth and not tgt else 0
            if k == max_frames - 1 or quiet >= quiet_frames:
                return set.intersection(*seen[-60:])                 # still drawn, unchanged, over the last 60 frames
            continue
        rows = sprite_rows(sim.c.cgram)
        hero_all = cas + fx
        if base_frames is not None:
            bk = k if k < len(base_frames) else len(base_frames) - 1
            known = {(p['dx'], p['dy'], p['hflip'], p['vflip']) for p in base_frames[bk]['pieces_fx']}
            wpn = [e for e in fx if (e['x'] - fp[0], e['y'] - fp[1], e['hflip'], e['vflip']) not in known]
            fx = [e for e in fx if e not in wpn]
            cas_ids = [e['i'] for e in cas]; rec['weapon_oam'] = [e['i'] for e in wpn]; rec['body_oam'] = cas_ids
            rec['weapon'] = crop_png(render(sim, wpn), (outdir, 'w'), cache, fp)
        rec['pal'] = {r: ['%04X' % v for v in rows[r]] for r in range(8) if any(e['pal'] == r for e in cas + fx + oth + tgt)}
        rec['caster'] = crop_png(render(sim, cas), (outdir, 'c'), cache, fp)
        rec['fx'] = crop_png(render(sim, fx), (outdir, 'f'), cache, fp)
        rec['hero'] = crop_png(render(sim, hero_all), (outdir, 'h'), cache, fp)
        rec['other'] = crop_png(render(sim, oth), (outdir, 'o'), cache, fp)
        rec['target'] = crop_png(render(sim, tgt), (outdir, 't'), cache, fp)
        if len(cast_targets) > 1:                                                             # the pieces of every target on their own
            rec['targets'] = [crop_png(render(sim, [e for e in tgt if (sim.c.owner.get(e['i']) or (-1,))[0] == 0x200 * t]), (outdir, 't'), cache, fp) for t in cast_targets]
        rec['pieces_tgt'] = [dict(dx=e['x'] - fp[0], dy=e['y'] - fp[1], tile=e['tile'], pal=e['pal'], hflip=e['hflip'], vflip=e['vflip'], own=(sim.c.owner.get(e['i']) or (-1,))[0] >> 9) for e in tgt]
        rec['pieces_oth'] = [dict(dx=e['x'] - fp[0], dy=e['y'] - fp[1], tile=e['tile'], pal=e['pal'], hflip=e['hflip'], vflip=e['vflip']) for e in oth]
        rec['pieces_fx'] = [dict(dx=e['x'] - fp[0], dy=e['y'] - fp[1], tile=e['tile'], pal=e['pal'], hflip=e['hflip'], vflip=e['vflip']) for e in fx]
        rec['pieces_cas'] = [dict(dx=e['x'] - fp[0], dy=e['y'] - fp[1], tile=e['tile'], pal=e['pal'], hflip=e['hflip'], vflip=e['vflip']) for e in cas]
        rec['regs'] = {hex(a): v for a, v in sim.c.regs.items() if a not in (0x2102, 0x2103, 0x2104, 0x2115, 0x2116, 0x2117, 0x2118, 0x2119, 0x2121, 0x2122)}
        rec['hdma'] = sim.c.hdma
        frames.append(rec)
        idle = rec['st1C'] == 0 and rec['st60'] == 0 and k > 20
        quiet = quiet + 1 if (idle and not rec['other'] and not rec['target']) else 0
        if idle and idle_at is None: idle_at = k
        if quiet >= quiet_frames: break
    snd = [dict(frame=x[0] - f0, id=x[3], param=x[4], pan=x[5]) for x in sim.sounds[n0:] if x[2] == 2]
    meta = dict(weapon_row=weapon_row, idle_frame=idle_at, hero=HEROES[slot], spell=spell, facing=facing, hostile=hostile, foot=list(foot), total_frames=len(frames), seconds=round(len(frames) / HZ, 4), apply_frame=apply,
                sounds=snd, spell_row_hex=row.hex(), level_forced=level, element_index=SS.Sim.element_index(spell))
    if extra: meta.update(extra)
    json.dump(dict(meta=meta, frames=frames), open(os.path.join(outdir, 'frames.json'), 'w'), indent=0)
    return meta


def main():
    rom = romio.rom_from_argv(); state, outdir = sys.argv[1], sys.argv[2]; a = sys.argv[3:]
    opt = lambda k, d: a[a.index(k) + 1] if k in a else d
    hero = opt('--hero', 'girl'); slot = HEROES.index(hero)
    sp = opt('--spells', 'all'); spells = list(range(0x2A)) if sp == 'all' else [int(x, 0) for x in sp.split(',')]
    dirs = opt('--dirs', 'down').split(',')
    level = int(opt('--level', '-1')); level = None if level < 0 else level
    label = opt('--label', hero)
    base_root = opt('--baseline', None)
    ally = opt('--ally-slot', None)
    for s in spells:
        for d in dirs:
            baseline = os.path.join(base_root, hero, 's%02X_%s' % (s, d)) if base_root else None
            m = rip_cast(rom, state, slot, s, d, os.path.join(outdir, label, 's%02X_%s' % (s, d)), level, int(opt('--weapon-row', '0')), int(opt('--target-dy', '0')) or None,
                         int(opt('--max', '700')), baseline=baseline, target_dx=int(opt('--target-dx', '0')), targets=int(opt('--targets', '1')), ally_slot=int(ally) if ally else None, ally_offset=(int(opt('--ally-dx', '40')), int(opt('--ally-dy', '0'))), quiet_frames=int(opt('--quiet', '45')), hurt='--hurt' in a)
            print('%s spell %02X %s: %d frames, apply %s, %d sounds' % (label, s, d, m['total_frames'], m['apply_frame'], len(m['sounds'])), flush=True)


if __name__ == '__main__':
    main()
