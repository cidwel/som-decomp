"""Rip the pictures of a boss of the C2 engine by letting the game draw them: the boss fight of boss_fight.py (own arena, game spawner, whole frame)
plus the NMI handler $C0:C0A8 (VRAM / CGRAM / OAM uploads) on a CPU that captures the PPU writes. Output goes to a directory chosen by the caller,
never into the repository.
usage: rip_boss.py sheet SHEET.png RIPDIR[,RIPDIR] [OUT.json]       compare the rips with a public sprite sheet you provide
       rip_boss.py ROM STATE BOSS_ID OUTDIR SEQ[,SEQ...] [hero=X,Y] [home=X,Y] [frames=N] [seed=N] [tag=NAME]
  SEQ = death: a lethal hit after 30 frames, then FRAMES frames of the death sequence (boss and every other engine object)
  home: the boss is put back at X,Y at the start of every forced sequence
  shadow=T,T: sprite tiles of the ground shadow (drawn every other frame); they are written as a separate picture set (`ground_shadow`)
  SEQ: a state-sequence pointer of the boss record (hex, bank C2), e.g. D0A2. Every chooser call is answered with the next sequence of the list
       (the chooser entry is skipped, so the game starts exactly that sequence); after the list is used up the real chooser runs again.
  The frames from the start of each forced sequence until the next chooser or action call are recorded.
Files: OUTDIR/<tag>_<seq>.json and <tag>_<seq>_<nn>.png (RGBA, colour 0 transparent, one size per sequence, `origin` = the object's ground point),
OUTDIR/<tag>_<seq>_slot<k>_<nn>.png for the other engine objects drawn at the same time (shadow, projectiles, spawned objects).
Per frame: picture index, state, animation id, position, height ($66), flip bit ($98 bit 6), attack / hurt boxes, sounds, hero contacts.
library: RipFight(rom, state, boss, ...) (a boss_fight.Fight whose CPU also emulates the PPU writes), .grab(slot)"""
import sys, os, json, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import romio, lich_sim, cpu65816, boss_fight, rip_hero_anims as RH, gfx_decode as G

HZ = 60.0988
SIZES = [(8, 16), (8, 32), (8, 64), (16, 32), (16, 64), (32, 64), (16, 32), (16, 32)]


class OwnCpu(RH.PpuCpu):
    """PpuCpu that tags every OAM shadow entry with the object being drawn: the drawing code keeps the object offset (slot * 0x200 from $7E:E000) in $0014."""
    def wr8(s, a, v):
        RH.PpuCpu.wr8(s, a, v)
        a &= 0xFFFFFF; o = a & 0xFFFF
        if a >> 16 in (0x7E, 0x00) and 0x800 <= o < 0xA00 and o & 3 == 1:
            s.owner[(o - 0x800) >> 2] = s.wram[0x14] | s.wram[0x15] << 8

    def ppu(s, o, v):
        if 0x2180 <= o <= 0x2183: cpu65816.CPU.hwwrite(s, o, v); return      # WRAM port (the map loader clears work areas through it)
        RH.PpuCpu.ppu(s, o, v)


class RipFight(boss_fight.Fight):
    def __init__(self, rom, state, boss, **kw):
        old = lich_sim.cpu.CPU
        lich_sim.cpu.CPU = OwnCpu
        try:
            super().__init__(rom, state, boss, **kw)
        finally:
            lich_sim.cpu.CPU = old
        self.g = RH.Game.__new__(RH.Game); self.g.c = self.c

    def frame(self):
        self.c.owner.clear()                      # only entries written in this frame are attributed
        super().frame()
        w = self.c.wram; f4 = w[0xF4]
        self.g.nmi()                              # uploads and OAM DMA; $F4 is kept as event_vm.World counts it
        w[0xF4] = f4

    def objsel(self):
        v = self.c.wram[0x91]
        return ((v & 7) << 13), (((v >> 3) & 3) + 1) << 12, SIZES[v >> 5]

    def grab(self, k=0, origin=(128, 176), size=(256, 256), split_tiles=()):
        """Pieces drawn for engine slot k in the last frame, relative to the object's ground point on the screen, and the picture.
        Pieces whose tile is in split_tiles (the ground shadow, drawn every other frame) are returned apart: (ents, img, pals, split_ents, split_img)."""
        c = self.c; b = self.base + 0x200 * k; rel = b - 0xE000
        ox = boss_fight.sext16((self.w16(b + 0x2B) - self.w16(0xA8)) & 0xFFFF)       # world position minus camera (= $20/$22 while the object is visible;
        oy = boss_fight.sext16((self.w16(b + 0x32) - self.w16(0xAA)) & 0xFFFF)       # spawned effects park $22 at 0x7FF while hidden)
        base, gap, (small, large) = self.objsel()
        ents = []
        for e in G.oam_entries(c.oam):
            if c.owner.get(e['i']) != rel: continue
            S = large if e['large'] else small
            y = e['y'] - 256 if e['y'] + S > 256 and e['y'] >= 224 else e['y']
            if e['y'] >= 224 and e['y'] + S <= 256: continue
            ents.append(dict(i=e['i'], dx=e['x'] - ox, dy=y - oy, tile=e['tile'], pal=e['pal'], prio=e['prio'], hflip=e['hflip'], vflip=e['vflip'], large=e['large']))
        def pic(es):
            draw = [dict(i=e['i'], x=origin[0] + e['dx'], y=origin[1] + e['dy'], tile=e['tile'], pal=e['pal'], prio=e['prio'], hflip=e['hflip'], vflip=e['vflip'], large=e['large']) for e in es]
            for d in draw:
                if d['y'] < 0: d['y'] += 256             # render() treats y >= 224 as wrapped
            return G.render(draw, c.vram, c.cgram, base, gap, small, large, size)
        sp = [e for e in ents if e['tile'] in split_tiles]; ents = [e for e in ents if e['tile'] not in split_tiles]
        pals = {r: ['%04X' % (c.cgram[256 + 32 * r + 2 * q] | c.cgram[256 + 32 * r + 2 * q + 1] << 8) for q in range(16)] for r in sorted({e['pal'] for e in ents + sp})}
        return ents, pic(ents), pals, sp, (pic(sp) if sp else None)


def key(ents):
    return tuple((e['dx'], e['dy'], e['tile'], e['pal'], e['hflip'], e['vflip'], e['large']) for e in ents)


def export(frames, outdir, name, meta, slots=()):
    """frames: list of dicts with 'ents', 'img', ... for slot 0 and 'others' {k: (ents, img)}. Writes distinct pictures cropped to the union box."""
    os.makedirs(outdir, exist_ok=True)
    def write_set(get, prefix):
        runs = []; idx = []
        pics = {}
        for fr in frames:
            g = get(fr)
            if g is None: idx.append(None); continue
            ents, img = g
            k = (key(ents), bytes(img.px))          # the same pieces under another palette (death flash) are a different picture
            if not ents: idx.append(None); continue
            if k not in pics: pics[k] = (len(pics), img, ents)
            idx.append(pics[k][0])
        boxes = [p[1].bbox() for p in pics.values() if p[1].bbox()]
        if not boxes: return None
        x0, y0, x1, y1 = min(b[0] for b in boxes), min(b[1] for b in boxes), max(b[2] for b in boxes), max(b[3] for b in boxes)
        files = []
        for k, (j, img, ents) in sorted(pics.items(), key=lambda t: t[1][0]):
            fn = '%s_%02d.png' % (prefix, j); G.write_png(os.path.join(outdir, fn), img.crop(x0, y0, x1, y1))
            files.append(dict(file=fn, pieces=[{q: e[q] for q in ('dx', 'dy', 'tile', 'pal', 'prio', 'hflip', 'vflip', 'large')} for e in ents]))
        return dict(png_size=[x1 - x0, y1 - y0], origin=[128 - x0, 176 - y0], pictures=files, per_frame_picture=idx)
    main = write_set(lambda fr: (fr['ents'], fr['img']), name)
    others = {}
    for k in slots:
        r = write_set(lambda fr: fr['others'].get(k), '%s_slot%d' % (name, k) if k else '%s_shadow' % name)
        if r: others['slot%d' % k if k else 'ground_shadow'] = r
    pf = dict(state=[fr['st'] for fr in frames], shadow_drawn=[fr.get('shadow', 0) for fr in frames], anim=[fr['anim'] for fr in frames], x=[fr['x'] for fr in frames], y=[fr['y'] for fr in frames],
              height=[fr['height'] for fr in frames], flip=[fr['flip'] for fr in frames], attack_box=[fr['atk'] for fr in frames],
              hurt_box=[fr['hurt'] for fr in frames], hurt_box2=[fr['hurt2'] for fr in frames], sounds=[fr['sounds'] for fr in frames],
              contacts=[fr['contacts'] for fr in frames])
    d = dict(meta, frames=len(frames), seconds=round(len(frames) / HZ, 4), frame_rate_hz=HZ, boss=main, other_objects=others,
             palettes=frames[0]['pals'] if frames else {}, per_frame=pf)
    json.dump(d, open(os.path.join(outdir, name + '.json'), 'w'), indent=1)
    return d


def rip_sequences(rom, state, boss, outdir, seqs, hero=None, frames=900, seed=1, tag='seq', home=None, split_tiles=()):
    f = RipFight(rom, state, boss, seed=seed, hero=[hero] if hero else None)
    c = f.c; base = f.base
    queue = list(seqs); cur = dict(seq=None)
    rec = []; out = {}
    calls = []

    def chooser(cp):
        if cp.X != base: return False
        calls.append(f.f)
        if queue:
            s = queue.pop(0); cur['seq'] = s; cp.A = s
            f.c.wr16(0x7E0000 + base + 0xAD, 0)               # action counter restarted: the forced state is not cut by the action threshold
            if home: f.c.wr16(0x7E0000 + base + 0x2B, home[0]); f.c.wr16(0x7E0000 + base + 0x32, home[1])
            cp.PC = (cp.pull16() + 1) & 0xFFFF            # RTS: the chooser returns the forced sequence
            return True
        cur['seq'] = None
        return False
    c.hooks[0xC20000 | f.h['chooser']] = chooser
    act = f.h['action']

    def action(cp):
        if cp.X != base: return False
        calls.append(f.f)
        if queue or cur['seq'] is not None:
            cp.C = 1; cp.PC = (cp.pull16() + 1) & 0xFFFF; return True        # "no action": the chooser runs (and serves the next forced sequence)
        return False
    c.hooks[0xC20000 | act] = action
    slots_seen = set()
    nsnd = 0; ncon = 0
    active = None
    for i in range(frames):
        n_calls = len(calls)
        f.frame()
        if len(calls) > n_calls:                      # a decision was made in this frame: close the running record
            if active is not None and rec: out[(active, rec[0]['flip'], rec[0]['st'])] = rec
            active = cur['seq'] if cur['seq'] is not None else None
            rec = []
            if active is None and not queue: break
        ents, img, pals, sh, shimg = f.grab(0, split_tiles=split_tiles)
        others = {}
        for k in range(1, 9):
            if f.c.wram[base + 0x200 * k] or k in slots_seen:
                e2, im2 = f.grab(k)[:2]
                if e2: others[k] = (e2, im2); slots_seen.add(k)
        snd = [list(e[1:]) for e in []]
        new_snd = [(ev['arg1'], ev['cmd']) for ev in f.events[nsnd:] if ev['kind'] == 'sound']; nsnd = len(f.events)
        new_con = [(h['hero'], h['row']) for h in f.hit_events[ncon:]]; ncon = len(f.hit_events)
        w = f.c.wram
        if active is not None:
            if sh: others[0] = (sh, shimg)
            rec.append(dict(ents=ents, img=img, pals=pals, others=others, shadow=1 if sh else 0, st=w[base + 0x7A], anim=f.w16(base + 0x9A), x=f.w16(base + 0x2B), y=f.w16(base + 0x32),
                            height=f.w16(base + 0x66), flip=1 if f.w16(base + 0x98) & 0x40 else 0, atk=f.box(0xC0), hurt=f.box(0xC8), hurt2=f.box(0xCC),
                            sounds=new_snd, contacts=new_con))
    if active is not None and rec: out[(active, rec[0]['flip'], rec[0]['st'])] = rec
    res = {}
    for (s, fl, st0), frs in out.items():
        name = '%s_%04X_%s' % (tag, s, 'flip' if fl else 'noflip')
        d = export(frs, outdir, name, dict(boss=boss, sequence='C2:%04X' % s, hero=hero, seed=seed, split_tiles=list(split_tiles)), slots=[0] + sorted(slots_seen))
        res[name] = dict(frames=d['frames'], pictures=len(d['boss']['pictures']) if d['boss'] else 0, states=sorted(set(d['per_frame']['state'])),
                         anims=sorted(set(d['per_frame']['anim'])), other=list(d['other_objects']))
        print(name, res[name], flush=True)
    return res


def rip_death(rom, state, boss, outdir, hero=None, frames=800, seed=1, tag='death', split_tiles=(), warm=30):
    """Lethal hit: after `warm` frames the boss gets pending damage HP + 10 (obj+$1F1) and the party-hit flag (obj+$34 bit 0); frames are recorded
    until `frames` frames have passed. The boss and every other engine object are ripped."""
    f = RipFight(rom, state, boss, seed=seed, hero=[hero] if hero else None)
    base = f.base
    for _ in range(warm): f.frame()
    f.c.wr16(0x7E0000 + base + 0x1F1, f.w16(base + 0x182) + 10); f.c.wram[base + 0x34] |= 1
    rec = []; nsnd = len(f.events); slots_seen = set()
    for i in range(frames):
        f.frame()
        ents, img, pals, sh, shimg = f.grab(0, split_tiles=split_tiles)
        others = {}
        for k in range(1, 9):
            e2, im2 = f.grab(k)[:2]
            if e2: others[k] = (e2, im2); slots_seen.add(k)
        if sh: others[0] = (sh, shimg)
        new_snd = [(ev['arg1'], ev['cmd']) for ev in f.events[nsnd:] if ev['kind'] == 'sound']; nsnd = len(f.events)
        w = f.c.wram
        rec.append(dict(ents=ents, img=img, pals=pals, others=others, shadow=1 if sh else 0, st=w[base + 0x7A], anim=f.w16(base + 0x9A), x=f.w16(base + 0x2B), y=f.w16(base + 0x32),
                        height=f.w16(base + 0x66), flip=1 if f.w16(base + 0x98) & 0x40 else 0, atk=f.box(0xC0), hurt=f.box(0xC8), hurt2=f.box(0xCC), sounds=new_snd, contacts=[]))
    d = export(rec, outdir, tag, dict(boss=boss, kind='death', hero=hero, seed=seed, lethal_hit_after_frames=warm,
                                      object_positions='per_frame x/y are the boss; the other objects are drawn relative to their own ground point'),
               slots=[0] + sorted(slots_seen))
    print(tag, d['frames'], 'boss pictures', len(d['boss']['pictures']) if d['boss'] else 0, 'other', list(d['other_objects']))
    return d


def check_sheet(sheet_path, dirs, out=None):
    """Look every ripped picture (boss and other objects; ground shadows and pictures under 40 pixels skipped) up in a public sprite sheet:
    exact (5-bit colours, as is or mirrored / flipped) or only under a consistent recolouring (flash palettes)."""
    import compare_sheet as CS, glob
    sheet = CS.load_sheet(sheet_path); res = {}; seen = {}
    tot = collections.Counter()
    for d in dirs:
        for jp in sorted(glob.glob(os.path.join(d, '*.json'))):
            if jp.endswith('index.json'): continue
            j = json.load(open(jp)); sets = [('boss', j['boss'])] + [(k, v) for k, v in j['other_objects'].items() if k != 'ground_shadow']
            for nm, st in sets:
                if not st: continue
                for p in st['pictures']:
                    pix, w, h = CS.frame_pixels(os.path.join(d, p['file']), {sheet[3]})     # pixels of the sheet's background colour cannot anchor a match
                    if len(pix) < 40: tot['small'] += 1; continue
                    k = tuple(pix)
                    if k not in seen:
                        ex = CS.find(sheet, pix, w, h)[0]
                        seen[k] = 'exact' if ex else ('recoloured' if CS.find_recoloured(sheet, pix, w, h) else 'not_found')
                    r = seen[k]; tot[r] += 1
                    res.setdefault(os.path.basename(jp)[:-5] + ':' + nm, collections.Counter())[r] += 1
    unique = collections.Counter(seen.values())
    o = dict(sheet=os.path.basename(sheet_path), pictures=dict(tot), distinct_pictures=dict(unique), per_set={k: dict(v) for k, v in sorted(res.items())})
    print(json.dumps(dict(pictures=o['pictures'], distinct=o['distinct_pictures'])))
    if out: json.dump(o, open(out, 'w'), indent=1)
    return o


def main():
    if sys.argv[1] == 'sheet':
        check_sheet(sys.argv[2], sys.argv[3].split(','), sys.argv[4] if len(sys.argv) > 4 else None); return
    rom = romio.rom_from_argv()
    a = sys.argv[1:]
    opts = dict(a.split('=', 1) for a in a if '=' in a); pos = [x for x in a if '=' not in x]
    state, boss, outdir = pos[0], int(pos[1], 16), pos[2]
    seqs = [] if pos[3] == 'death' else [int(s, 16) for s in pos[3].split(',')]
    hero = tuple(int(v) for v in opts['hero'].split(',')) if 'hero' in opts else None
    home = tuple(int(v) for v in opts['home'].split(',')) if 'home' in opts else None
    split = tuple(int(v, 0) for v in opts['shadow'].split(',')) if 'shadow' in opts else ()
    if pos[3] == 'death':
        rip_death(rom, state, boss, outdir, hero, int(opts.get('frames', 800)), int(opts.get('seed', 1)), opts.get('tag', 'death'), split); return
    r = rip_sequences(rom, state, boss, outdir, seqs, hero, int(opts.get('frames', 900)), int(opts.get('seed', 1)), opts.get('tag', 'seq'), home, split)
    idx = os.path.join(outdir, 'index.json')
    old = json.load(open(idx)) if os.path.exists(idx) else {}
    old.update(r); json.dump(old, open(idx, 'w'), indent=1)


if __name__ == '__main__':
    main()
