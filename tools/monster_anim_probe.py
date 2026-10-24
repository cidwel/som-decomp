"""Probes for docs/monster-animation-use.md: which animation ids and engine states an ordinary monster (object ids 0x00-0x1F) gets from statuses, hit reactions and AI commands.
usage:
  monster_anim_probe.py ROM STATE status ID MASK_HEX FRAMES [--ai] [--level N]   apply a status word through the real $C8:E301 and print every change of
                                                                                (object id, facing, animation, state, script pc, palette row 5, piece palettes, command bytes)
  monster_anim_probe.py ROM STATE hit ID dmg|heal|mp|miss VALUE FRAMES           pending HP damage / HP heal / MP damage into +0x1F1 / +0x1F3 / +0x1F5, or a missed hit ($C0:4E6B)
  monster_anim_probe.py ROM scan [OUT.json]                                       static walk of the AI scripts of ids 0x00-0x1F: ordinary animations asked by the hop / turn ops,
                                                                                  attack animations asked by pose (E2) and cast (E9, EA) ops, E0 args, spawn (ED) / morph (EF) args,
                                                                                  and the swing chooser rows (D1:05C0 + id * 0x20)
Without --ai the monster AI step is off (only the engine reacts); with --ai the real script runs and only the hero AI is off.
The monster is created in slot 3 by the game's spawner (tools/rip_monster_anims.py, tools/ai_sim.py); frames are video frames (60.0988 Hz)."""
import sys, os, json, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import romio, aidis


def new_rip(rom, state, mid, ai):
    import rip_monster_anims as M
    r = M.Rip(rom, state, mid)
    if ai:
        def hero_only(cp):
            if cp.X < 0x600:
                cp.PC = (cp.pull16() + 1) & 0xFFFF; return True
            return False
        r.c.hooks[0xC12552] = hero_only
        for _ in range(30): r.frame()
    return r


def apply_status(r, mask, level=0):
    """$C8:E301 with the pending status word $9A (value $96 = 0: duration 20), as the combat tick calls it."""
    c, o = r.c, r.o; x = o.base - 0xE000
    c.wram[0x39A] = mask & 255; c.wram[0x39B] = mask >> 8
    c.wram[0x396] = 0; c.wram[0x397] = 0; c.wram[0x39D] = level
    c.wram[0x385] = x & 255; c.wram[0x386] = x >> 8
    d0 = c.D; r.s.env.call(0xC8E301, X=x, m=1, x=0, D=0x300); c.D = d0


def trace(r, n):
    o, c = r.o, r.c; prev = None; start = 0; out = []
    for i in range(n):
        r.frame(); fr = r.grab()
        pals = tuple(sorted({e['pal'] for e in fr['entries']}))
        row5 = bytes(c.cgram[256 + 32 * 5:256 + 32 * 6]).hex()[:16]
        st = (o.b(0x180), o.b(0x10), o.b(0x11), o.b(0x1C), o.w(0x144), row5, pals, len(fr['entries']), tuple(o.b(0x140 + k) for k in range(4)), o.w(0x190))
        if st != prev:
            out.append((i,) + st); prev = st
    return out


FMT = 'f%4d id %02x face %02x anim %02x state %02x pc %04x row5 %s pal %s pieces %d cmd %02x %02x %02x %02x status %04x'


def cmd_status(rom, state, a):
    mid, mask, n = int(a[0], 0), int(a[1], 16), int(a[2])
    lvl = int(a[a.index('--level') + 1]) if '--level' in a else 0
    r = new_rip(rom, state, mid, '--ai' in a); r.load(r.snap)
    if '--ai' in a:
        for _ in range(30): r.frame()
    apply_status(r, mask, lvl)
    print('after $C8:E301: status %04x object id %02x appearance index +0x1E3 %02x refresh flags +0x1FA %02x' % (r.o.w(0x190), r.o.b(0x180), r.o.b(0x1E3), r.o.b(0x1FA)))
    for e in trace(r, n): print(FMT % (e[0], e[1], e[2], e[3], e[4], e[5], e[6], e[7], e[8], *e[9], e[10]))


def cmd_hit(rom, state, a):
    mid, mode, val, n = int(a[0], 0), a[1], int(a[2]), int(a[3])
    r = new_rip(rom, state, mid, '--ai' in a); r.load(r.snap); o, c = r.o, r.c
    mx = o.w(0x184); o.sw(0x182, mx)
    if mode == 'dmg': o.sw(0x1F1, val)
    elif mode == 'heal': o.sw(0x182, max(1, mx - 20)); o.sw(0x1F3, val)
    elif mode == 'mp': o.sw(0x1F5, val)
    elif mode == 'miss':
        x = o.base - 0xE000; c.wram[0x385] = x & 255; c.wram[0x386] = x >> 8
        d0 = c.D; r.s.env.call(0xC04E6B, X=x, m=1, x=0, D=0x300); c.D = d0
    p0 = (o.w(2), o.w(4)); prev = None
    for i in range(n):
        r.frame()
        st = (o.b(0x11), o.b(0x1C), o.b(0x60), o.w(0x16), o.w(2) - p0[0], o.w(4) - p0[1], o.w(0x182), o.b(0x1B4), bytes(c.cgram[256 + 128:256 + 160]).hex()[:12])
        if st != prev:
            print('f%4d anim %02x state %02x +0x60 %02x script %04x displacement (%d,%d) hp %d stun %02x palette row 4 %s' % ((i,) + st)); prev = st


def walk(rom, mid):
    base = aidis.BASE; e = 0x100000 + mid * 16
    entry = rom[e + 9] | rom[e + 10] << 8
    seen = set(); st = [entry]; ops = collections.defaultdict(set)
    while st:
        pc = st.pop()
        while pc not in seen and pc < 0x8000:
            seen.add(pc); op = rom[base + pc]
            ln, t, tg, ft = aidis.decode(rom, pc)
            if '???' in t: break
            if op >= 0xBE or op == 0xE0: ops[op].add(tuple(rom[base + pc + 1:base + pc + ln]))
            if tg is not None: st.append(tg)
            if not ft: break
            pc += ln
    return ops


def cmd_scan(rom, a):
    out = {}
    for mid in range(0x20):
        ops = walk(rom, mid); o = set(); p = set(); c = collections.defaultdict(set); other = {}
        for op, args in ops.items():
            for x in args:
                if op == 0xE0: o.add(x[1])
                elif op in (0xE3, 0xE4, 0xE6, 0xFD, 0xFE, 0xBE, 0xBF): o.add(x[0])
                elif op == 0xE2: p.add(x[0])
                elif op in (0xE9, 0xEA): c[x[0]].add(x[1])
                elif op in (0xED, 0xEF): other.setdefault('%02X' % op, []).append(list(x))
        base = ((0xD1 - 0xC0) << 16) | (0x05C0 + mid * 0x20)
        rows = [rom[base:base + 16], rom[base + 16:base + 32]]
        out[mid] = dict(ordinary_animations=sorted(o), pose_40_attack_animations=sorted(p), cast_44_attack_animations={str(k): sorted(v) for k, v in sorted(c.items())},
                        swing_02_animations=dict(normal=sorted(set(rows[0])), variant_bit7_of_1E4=sorted(set(rows[1]))), spawn_or_morph_args=other,
                        uses_swing=bool(ops.get(0xE8) or ops.get(0xDF) or ops.get(0xFA)))
        print('%02X ordinary %s pose %s cast %s swing %s' % (mid, sorted(o), sorted(p), {k: sorted(v) for k, v in sorted(c.items())}, out[mid]['swing_02_animations']['normal']))
    if a: json.dump(out, open(a[0], 'w'), indent=1)


def main():
    rom = romio.rom_from_argv(); args = sys.argv[1:]
    if args[0] == 'scan': cmd_scan(rom, args[1:]); return
    state, cmd, a = args[0], args[1], args[2:]
    {'status': cmd_status, 'hit': cmd_hit}[cmd](rom, state, a)


if __name__ == '__main__':
    main()
