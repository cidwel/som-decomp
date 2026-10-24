"""Summary data of the spell casts: graphics / palette loads of every spirit (trace) and the per-spell timelines merged from a `rip_summon.py` output directory (merge).
usage: summon_report.py sounds ROM STATE OUT.json HERO [TARGETS]          every sound request of every spell, four directions (until 250 frames after the hero is free)
       summon_report.py levels ROM STATE OUT.json LEVEL                 every spell at one magic level (hero free, MP paid, phases, sounds, $2131/$2132 writes)
       summon_report.py release ROM STATE OUT.json SPELL[,SPELL...] [survey|ally|dense [FACES]]   hero free / MP-paid frames over a grid of target positions (and the four facings)
       summon_report.py trace ROM STATE OUT.json        run one cast per spirit with hooks on the graphics loader $C1:C599 and the palette loader $C1:859B
       summon_report.py merge RIPDIR TRACE.json OUT.json  RIPDIR = OUTDIR of rip_summon.py (hero/s<ID>_<dir>/frames.json); writes the numbers of data/summon_cast.json
The merge needs no ROM: it only reads what the ripper recorded (frame data and the PNG sizes). Numbers only; no pictures and no ROM bytes are written."""
import sys, os, json, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import romio, summon_sim as SS, gfx_decode as G

HZ = SS.HZ
SPIRITS = ['gnome', 'undine', 'salamando', 'sylphid', 'luna', 'dryad', 'shade', 'lumina']      # element index (+0x177) order
SPELL_NAMES_HINT = None


def trace(rom, state, out):
    """For one spell of each spirit: every call of the tile loader $C1:C599 (bank, destination, source offset, tile count) and of the palette loader $C1:859B with the frame."""
    res = {}
    for sp in (0x00, 0x06, 0x0C, 0x12, 0x18, 0x1E, 0x24, 0x27, 0x03):
        sim = SS.Sim(rom, state, 1)
        for _ in range(20): sim.frame()
        w, c = sim.w, sim.c; log = []
        def h1(cp): log.append(dict(kind='tiles', frame=sim.f - f0[0], bank='%02X' % (cp.A & 0xFF), dest='%04X' % cp.X, src='%04X' % cp.Y, count=w[8] | w[9] << 8, dest_offset='%04X' % (w[0] | w[1] << 8))); return False
        def h2(cp): log.append(dict(kind='palette', frame=sim.f - f0[0], index='%02X' % (cp.A & 0xFF))); return False
        f0 = [0]
        for a in (0xC1C599, 0x01C599): c.hooks[a] = h1
        for a in (0xC1859B, 0x01859B): c.hooks[a] = h2
        hostile = bool(rom[0x102AD0 + sp * 64 + 8] & 0x80)
        if hostile: sim.spawn_monster(0, -70 if sim.screen_xy()[1] >= 110 else 70)
        for _ in range(3): sim.frame()
        f0[0] = sim.f; log.clear()
        sim.cast(sp, [3] if hostile else [1])
        for _ in range(200): sim.frame()
        res['%02X' % sp] = dict(element_index=SS.Sim.element_index(sp), loads=log)
    banner = {}
    for sp in range(0x2A):
        sim = SS.Sim(rom, state, 1)
        for _ in range(20): sim.frame()
        hostile = bool(rom[0x102AD0 + sp * 64 + 8] & 0x80)
        if hostile: sim.spawn_monster(0, -70 if sim.screen_xy()[1] >= 110 else 70)
        for _ in range(3): sim.frame()
        hd = {}; _wr = sim.c.wr8; f0 = sim.f
        def wr(a, v, _wr=_wr):
            if (a & 0xFFFF) == 0x420C and ((a >> 16) & 0x7F) < 0x40: hd[sim.f - f0] = v & 0xFF
            _wr(a, v)
        sim.c.wr8 = wr
        sim.cast(sp, [3] if hostile else [1]); ev = collections.defaultdict(list)
        for k in range(600):
            sim.c.dma_src = []; sim.frame()
            for (src, n, va) in sim.c.dma_src:
                if va == 0x5820 and n == 1280: ev['map'].append(k)
                elif va == 0x4880: ev['glyphs'].append(k)
                elif va == 0x4F00 and n == 512: ev['text'].append(k)
            if k > 20 and not sim.w[sim.base - 0xE000 + 0xE01C] and not sim.w[sim.base - 0xE000 + 0xE060] and (k > 140 or not hd.get(k)): break
        on = [f for f in sorted(hd) if hd[f]]
        m = ev['map']
        banner[str(sp)] = dict(open=[f for f in m if f < 20], close=[f for f in m if f >= 20], text_upload=ev['text'][:2], glyph_upload=ev['glyphs'], hdma_on=[on[0], on[-1]] if on else None)
    res['banner_window'] = banner
    json.dump(res, open(out, 'w'), indent=1)


def release(rom, state, out, spells, survey=False, ally=False, dense=False, faces=None):
    """Frame in which the caster is free (and the frame MP is paid) for a hostile spell against a monster at (dx, dy) from the caster, per facing. `survey` uses 13 positions and
    one facing for any spell; otherwise a 6 x 5 grid for the four facings, or with `dense` a 10-pixel grid (21 x 17 positions, the caster's own square left out)."""
    xs = [-100, -60, -20, 20, 60, 100]; ys = [-100, -60, -20, 20, 50]
    if dense: xs = list(range(-100, 101, 10)); ys = list(range(-100, 61, 10))
    pos = [(0, -40), (0, -70), (0, -100), (0, 50), (0, 80), (40, 0), (80, 0), (-40, 0), (-80, 0), (60, -60), (-60, -60), (50, 50), (100, -30)] if survey else [(x, y) for y in ys for x in xs if abs(x) >= 20 or abs(y) >= 20]
    res = {}
    for sp in spells:
        hostile = bool(rom[0x102AD0 + sp * 64 + 8] & 0x80)
        res[str(sp)] = {}
        for face in (['down'] if survey else faces or ['down', 'up', 'right', 'left']):
            rows = []
            for dx, dy in (pos if hostile or ally else [(0, 0)]):
                sim = SS.Sim(rom, state, 1, keep=(0,) if ally else ())
                for _ in range(20): sim.frame()
                w = sim.w; b = sim.base - 0xE000
                sim.face(face)
                if hostile: sim.spawn_monster(dx, dy)
                if ally:
                    me = sim.env.obj(1); other = sim.env.obj(0); other.sw(2, me.w(2) + dx); other.sw(4, me.w(4) + dy)
                for _ in range(3): sim.frame()
                mp0 = w[b + 0xE186]; sim.cast(sp, [3] if hostile else [0] if ally else [1]); ap = idle = None
                for k in range(800):
                    sim.frame()
                    if ap is None and w[b + 0xE186] != mp0: ap = k
                    if k > 20 and not w[b + 0xE01C] and not w[b + 0xE060]: idle = k; break
                rows.append([dx, dy, ap, idle])
            res[str(sp)][face] = rows
        print('spell %02X done' % sp, flush=True)
    json.dump(res, open(out, 'w'))


def sounds(rom, state, out, hero, targets=1, faces=('down', 'up', 'right', 'left')):
    """Every sound request of every spell cast by `hero` (slot) in the four directions, the way rip_summon.py starts the cast, recorded until 250 frames after the hero is free
    (effects outlive the caster). out = {spell: {direction: [[frame, id, param, pan], ...]}}."""
    slot = ('boy', 'girl', 'sprite').index(hero); res = {}
    for sp in range(0x2A):
        hostile = bool(rom[0x102AD0 + sp * 64 + 8] & 0x80)
        res[str(sp)] = {}
        for face in faces:
            sim = SS.Sim(rom, state, slot, keep=tuple(k for k in range(3) if k != slot) if targets > 1 and not hostile else ())
            for _ in range(20): sim.frame()
            w = sim.w; b = sim.base - 0xE000
            sim.equip(0); sim.face(face)
            if w[b + 0xE186] < 50: w[b + 0xE186] = w[b + 0xE187] = 99
            if hostile:
                for i in range(targets): sim.spawn_monster((0, -50, 50)[i], -70 if sim.screen_xy()[1] >= 110 else 70, slot=3 + i)
            for _ in range(3): sim.frame()
            n0 = len(sim.sounds); f0 = sim.f
            sim.cast(sp, [3 + i for i in range(targets)] if hostile else [slot] + [k for k in range(3) if k != slot][:targets - 1])
            idle = None
            for k in range(1200):
                sim.frame()
                if idle is None and k > 20 and not w[b + 0xE01C] and not w[b + 0xE060]: idle = k
                if idle is not None and k >= idle + 250: break
            res[str(sp)][face] = [[x[0] - f0, x[3], x[4], x[5]] for x in sim.sounds[n0:] if x[2] == 2]
        print(hero, '%02X' % sp, flush=True)
    json.dump(res, open(out, 'w'))


def levels(rom, state, out, level):
    """Timeline of every spell cast at magic level `level` (+0x171 forced after the cast request): hero free, MP paid, phases, sound requests. A cast that stops in a blocking
    screen-effect wait (`$C1:2FE4`, needs the alternative NMI handler, which the harness does not run) is recorded with `stuck` = the frame."""
    res = {}
    for sp in range(0x2A):
        hostile = bool(rom[0x102AD0 + sp * 64 + 8] & 0x80)
        sim = SS.Sim(rom, state, 1)
        for _ in range(20): sim.frame()
        w = sim.w; b = sim.base - 0xE000
        if hostile: sim.spawn_monster(0, -70)
        for _ in range(3): sim.frame()
        n0 = len(sim.sounds); f0 = sim.f; mp0 = w[b + 0xE186]
        sim.cast(sp, [3] if hostile else [1], level=level)
        ap = None; ph = []; prev = None; entry = None; idle = None; cm = []
        try:
            for k in range(1200):
                sim.c.regs.clear()
                sim.frame(limit=3_000_000)
                writes = {hex(a): v for a, v in sim.c.regs.items() if a in (0x2131, 0x2132)}
                if writes: cm.append([k, writes.get('0x2131'), writes.get('0x2132')])
                if ap is None and w[b + 0xE186] != mp0: ap = k
                p = w[b + 0xE060]
                if p != prev: ph.append([k, p]); prev = p
                if idle is None and k > 20 and not w[b + 0xE01C] and not w[b + 0xE060]: idle = k
                if idle is not None and k >= idle + 250: break           # sounds of effects that outlive the caster
            entry = dict(idle=idle, apply=ap, phases=ph, color_math=cm, sounds=[[x[0] - f0, x[3], x[4], x[5]] for x in sim.sounds[n0:] if x[2] == 2])
        except RuntimeError:
            entry = dict(stuck=k, phases=ph)
        res[str(sp)] = entry
        print(level, '%02X' % sp, entry.get('idle'), entry.get('apply'), entry.get('stuck'), flush=True)
    json.dump(res, open(out, 'w'))


def flip(img):
    out = G.Image(img.w, img.h)
    for y in range(img.h):
        for x in range(img.w):
            o = 4 * (y * img.w + x); p = 4 * (y * img.w + img.w - 1 - x)
            out.px[p:p + 4] = img.px[o:o + 4]
    return out


def mirror_check(d_right, d_left, layer='caster'):
    """Fraction of frames whose picture in `left` is the mirror image of the one in `right` (picture, position about the foot point)."""
    fr_r = json.load(open(os.path.join(d_right, 'frames.json')))['frames']; fr_l = json.load(open(os.path.join(d_left, 'frames.json')))['frames']
    n = same = 0
    for a, b in zip(fr_r, fr_l):
        pa, pb = a[layer], b[layer]
        n += 1
        if pa is None or pb is None:
            same += pa is None and pb is None; continue
        if pb['x'] != -(pa['x'] + pa['w']) or pb['y'] != pa['y'] or pa['w'] != pb['w'] or pa['h'] != pb['h']: continue
        ia = G.read_png(os.path.join(d_right, pa['file'])); ib = G.read_png(os.path.join(d_left, pb['file']))
        same += bytes(flip(ia).px) == bytes(ib.px)
    return same, n


def color_math(frames):
    """Carry-forward timeline of the colour-math registers: [frame, $2131 (CGADSUB), $2132 (COLDATA)] at every change."""
    cur = [None, None]; out = []
    for r in frames:
        regs = r['regs']; ch = False
        if '0x2131' in regs and regs['0x2131'] != cur[0]: cur[0] = regs['0x2131']; ch = True
        if '0x2132' in regs and regs['0x2132'] != cur[1]: cur[1] = regs['0x2132']; ch = True
        if ch: out.append([r['k'], cur[0], cur[1]])
    return out


def runs(frames, key):
    out = []
    for r in frames:
        k = key(r)
        if out and out[-1][0] == k: out[-1][1] += 1
        else: out.append([k, 1])
    return out


def merge(ripdir, trace_path, out):
    tr = json.load(open(trace_path)) if trace_path and os.path.exists(trace_path) else {}
    spells = {}
    heroes = [h for h in ('boy', 'girl', 'sprite') if os.path.isdir(os.path.join(ripdir, h))]
    for sp in range(0x2A):
        ref = None; per = {}
        for h in heroes:
            for d in ('down', 'up', 'right', 'left'):
                p = os.path.join(ripdir, h, 's%02X_%s' % (sp, d), 'frames.json')
                if not os.path.exists(p): continue
                j = json.load(open(p)); m = j['meta']; per['%s/%s' % (h, d)] = dict(total=m['total_frames'], idle=m['idle_frame'], apply=m['apply_frame'])
                if h == 'girl' and d == 'down': ref = j
        if ref is None: continue
        m = ref['meta']; fr = ref['frames']
        phases = [[r['k'], r['st60']] for i, r in enumerate(fr) if i == 0 or r['st60'] != fr[i - 1]['st60']]
        eff = next((r['k'] for r in fr if r['k'] > 60 and r['st60'] != 0x80), None)
        caster = [[k[0], k[1], k[2], n] for k, n in runs(fr, lambda r: (r['anim'], r['fi'], r['flags']))]
        spells[str(sp)] = dict(
            id=sp, spirit=SPIRITS[m['element_index']], element_index=m['element_index'], hostile=m['hostile'],
            effect_start=eff, total_frames=m['total_frames'], idle_frame=m['idle_frame'], apply_frame=m['apply_frame'], seconds=m['seconds'],
            phases=phases, sounds=[[s['frame'], s['id'], s['param'], s['pan']] for s in m['sounds']], color_math=color_math(fr),
            caster_runs=caster, spread={k: v for k, v in per.items()})
    json.dump(dict(hz=HZ, spirits=SPIRITS, trace=tr, spells=spells), open(out, 'w'), separators=(',', ':'))
    print('wrote', out, len(spells), 'spells')


if __name__ == '__main__':
    if sys.argv[1] == 'sounds':
        sys.argv.pop(1); rom = romio.rom_from_argv(); sounds(rom, sys.argv[1], sys.argv[2], sys.argv[3], int(sys.argv[4]) if len(sys.argv) > 4 else 1, ('down',) if len(sys.argv) > 4 and int(sys.argv[4]) > 1 else ('down', 'up', 'right', 'left'))
    elif sys.argv[1] == 'levels':
        sys.argv.pop(1); rom = romio.rom_from_argv(); levels(rom, sys.argv[1], sys.argv[2], int(sys.argv[3]))
    elif sys.argv[1] == 'release':
        sys.argv.pop(1); rom = romio.rom_from_argv()
        mode = sys.argv[4] if len(sys.argv) > 4 else ''
        release(rom, sys.argv[1], sys.argv[2], [int(x, 0) for x in sys.argv[3].split(',')], mode == 'survey', mode == 'ally', mode == 'dense', sys.argv[5].split(',') if len(sys.argv) > 5 else None)
    elif sys.argv[1] == 'trace':
        sys.argv.pop(1); rom = romio.rom_from_argv(); trace(rom, sys.argv[1], sys.argv[2])
    elif sys.argv[1] == 'merge':
        merge(sys.argv[2], sys.argv[3], sys.argv[4])
    else:
        sys.exit(__doc__)
