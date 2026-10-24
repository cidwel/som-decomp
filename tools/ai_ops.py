"""Run the real AI bytecode handlers ($C1:251A -> table $C1:2257) on synthetic scripts and print what each opcode does.
usage: ai_ops.py ROM STATE [--new | --new20 | --fuzz [all|OP,OP,... [N]] [--slot S]]      (--fuzz: every op modelled in ai_vm.py, one handler at a time, N random cases each, compared with the model; --new: only the opcodes added for docs/monster-3.md and docs/monster-13.md: 34, 6A, 73, BE, BF, DC; --new20: the ops added by ids 0x20-0x53: 75, EE, 85, EA)
Each case patches a few script bytes into an in-memory copy of the ROM (script base 0x104F15, never written to disk), builds a monster in slot 3
with the game's spawner, runs one handler and prints: return value (FF = continue with the next op, 00 = yield until the next tick),
script-pointer advance, and the object fields that changed. Lengths of conditional ops include the 1- or 2-byte jump offset.
Distances use the on-screen coordinates (obj+0x20, obj+0x22 - obj+0x45) of the monster and of hero 0."""
import sys, os, random, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import romio, ai_sim, aidis

BASE = ai_sim.SCRIPT_BASE
P = 0x7000      # scratch script address (patched copy only)


class Bench:
    def __init__(self, rom, state):
        self.rom = bytearray(rom)
        self.sim = ai_sim.Sim(self.rom, state, 0, (20, 25))
        self.env = self.sim.env; self.c = self.sim.c; self.o = self.sim.o
        self.h = self.env.obj(0)
        self.rnd = random.Random(1)

    def place(self, dx=None, dy=0, mx=128, my=112):
        o, h = self.o, self.h
        o.sw(0x20, mx); o.sw(0x22, my)
        if dx is not None:
            h.sw(0x20, (mx + dx) & 0xFFFF); h.sw(0x22, (my + dy) & 0xFFFF)

    def reseed(self):
        c = self.c
        c.wram[0x3F0] = self.rnd.randrange(15)
        for i in range(0x3F1, 0x400): c.wram[i] = self.rnd.randrange(256)

    def snap(self):
        o = self.o
        return {k: o.b(k) for k in list(range(0x140, 0x160)) + [0x1AC, 0x1AD, 0x1ED, 0x19B]}

    def run(self, code, pc=P, reseed=True, **fields):
        for i, b in enumerate(code): self.rom[BASE + pc + i] = b
        o = self.o
        o.sw(0x144, pc); o.sb(0x14F, 0)
        for k, v in fields.items():
            if k == 'tgt': o.sb(0x1AC, v)
            elif k == 'var': o.sb(0x147, v << 4)
            elif k == 'hp': o.sw(0x182, v)
            elif k == 'gauge': o.sb(0x1ED, v)
            elif k == 'depth': o.sb(0x14F, 1); o.sw(0x150, v)
            elif k == 'saved': o.sw(0x148, v[0]); o.sw(0x14A, v[1])
        if reseed: self.reseed()
        before = self.snap()
        self.env.call(0xC1251A, Y=o.base, m=1, x=0, long=False, DB=0x7E)
        a = self.c.A & 0xFF
        after = self.snap()
        diff = {hex(k): '%02X' % after[k] for k in after if after[k] != before[k] and k not in (0x144, 0x145)}
        return dict(A=a, pc=o.w(0x144), adv=o.w(0x144) - pc, diff=diff, depth=o.b(0x14F))


def show(name, r):
    print('%-44s A=%02X adv=%+d depth=%d %s' % (name, r['A'], r['adv'], r['depth'], r['diff']))


def new_ops(b):
    """Exhaustive checks of the opcodes the Chobin Hood (id 3) and Polter Chair (id 0x0D) scripts use beyond the Rabite's 33:
    34 (target within 16 px), 6A / 73 (target in a vertical / horizontal lane), BE / BF (cardinal turn toward / away), DC (set byte).
    Each model is compared with the real handler over every case listed; the result is printed as 'cases / mismatches'."""
    h, o = b.h, b.o
    h.sw(0x190, 0)
    print('--- 34: jump unless the current target is valid and within 16 px (distance class 1)')
    bad = n = 0
    for d in range(0, 40):
        b.place(d); r = b.run(bytes([0x34, 0x85]), tgt=0); n += 1
        bad += (r['adv'] == 2) != (d <= 16)
    b.place(10); r = b.run(bytes([0x34, 0x85]), tgt=0xFF); n += 1; bad += r['adv'] == 2
    print('34: %d cases, %d mismatches (d <= 16 falls through; no target jumps)' % (n, bad))
    print('--- 6A / 73: dx, dy = hero - monster on screen (dy uses obj+0x22 - obj+0x45)')
    for op in (0x6A, 0x73):
        bad = n = 0
        for oth in range(-60, 61):
            for v in range(-30, 31):
                dx, dy = (v, oth) if op == 0x6A else (oth, v)
                if not (0 <= 128 + dx < 256 and 0 <= 112 + dy < 224): continue
                b.place(dx, dy); r = b.run(bytes([op, 0x85]), tgt=0); n += 1
                pred = (abs(dx) <= 15 and abs(dx) < abs(dy)) if op == 0x6A else (abs(dy) <= 15 and abs(dy) <= abs(dx))
                bad += (r['adv'] == 2) != pred
        print('%02X: %d cases, %d mismatches (falls through iff %s)' % (op, n, bad, '|dx| <= 15 and |dx| < |dy|' if op == 0x6A else '|dy| <= 15 and |dy| <= |dx|'))
        b.place(30, 0); r = b.run(bytes([op, 0x85]), tgt=0xFF); print('%02X with no target: %s' % (op, 'jump' if r['adv'] != 2 else 'fall'))
    print('--- BE / BF: command C1 with a cardinal code, animation arg1, flag arg2 (no-op when there is no valid target)')
    for op in (0xBE, 0xBF):
        bad = n = 0
        for dx in range(-60, 61, 3):
            for dy in range(-60, 61, 3):
                if dx == 0 and dy == 0: continue
                if not (0 <= 128 + dx < 256 and 0 <= 112 + dy < 224): continue
                b.place(dx, dy); b.o.sb(0x140, 0); b.o.sb(0x141, 0)
                r = b.run(bytes([op, 3, 5]), tgt=0); n += 1
                toward = (1 if dx >= 0 else 2) if abs(dx) >= abs(dy) else (4 if dy > 0 else 8)
                want = toward if op == 0xBE else {1: 2, 2: 1, 4: 8, 8: 4}[toward]
                ok = b.o.b(0x140) == 0xC1 and b.o.b(0x141) == want and b.o.b(0x142) == 3 and b.o.b(0x143) == 5 and r['A'] == 0 and r['adv'] == 3
                bad += not ok
        print('%02X: %d cases, %d mismatches (code = %s; |dx| >= |dy| is horizontal)' % (op, n, bad, 'toward' if op == 0xBE else 'away'))
        b.place(30, 0); b.o.sb(0x140, 0); r = b.run(bytes([op, 3, 5]), tgt=0xFF); print('%02X with no target: A=%02X adv=%d cmd=%02X' % (op, r['A'], r['adv'], b.o.b(0x140)))
    print('--- DC a b v: byte(object a, offset b + 0x180) = v, continue')
    b.place(40)
    r = b.run(bytes([0xDC, 0x80, 0x6D, 0x00]), gauge=50); show('DC 80 6D 00 (self+0x1ED = 0)', r); print('self+0x1ED =', b.o.b(0x1ED))
    r = b.run(bytes([0xDC, 0x80, 0x6D, 0x07]), gauge=50); show('DC 80 6D 07', r); print('self+0x1ED =', b.o.b(0x1ED))
    h.sb(0x1ED, 50); r = b.run(bytes([0xDC, 0x00, 0x6D, 0x09]), gauge=50); print('DC 00 6D 09 sets hero 0 +0x1ED =', h.b(0x1ED), ' (object ref 0 = slot 0)')



def new_ops_20(b):
    """The ops the scripts of ids 0x20-0x53 add: 75 (target above), EE (command 04), 85 (undefined: error handler) and EA (cast on a whole side,
    with its two quirks: the target loops test slot 0 / slot 3 three times, and the MP test lets a cast through with too little MP)."""
    h, o, env = b.h, b.o, b.env
    h.sw(0x190, 0)
    bad = n = 0
    for dx in range(-40, 41, 2):
        for dy in range(-40, 41, 2):
            if dx == 0 and dy == 0: continue
            b.place(dx, dy); r = b.run(bytes([0x75, 0x85]), tgt=0); n += 1
            bad += (r['adv'] == 2) != (dy < 0 and abs(dy) > abs(dx))
    print('75: %d cases, %d mismatches (falls through iff the target is above and |dy| > |dx|)' % (n, bad))
    o.sb(0x140, 0); r = b.run(bytes([0xEE])); show('EE (command 04)', r); print('   cmd byte', '%02X' % o.b(0x140))
    r = b.run(bytes([0x85]), depth=0x1234); show('85 (undefined: error handler, restart)', r)
    def setup(ha, ma, tgt2, mp=99, b60=0, st=0):
        for i in range(3):
            x = env.obj(i); x.sb(0, ha[i]); x.sw(0x20, 100 + 10 * i); x.sw(0x22, 100); x.sw(0x190, 0); x.sb(0x45, 0)
        for i, sl in enumerate((4, 5)):
            x = env.obj(sl); x.sb(0, ma[i]); x.sw(0x20, 60); x.sw(0x22, 60); x.sw(0x190, 0); x.sb(0x180, 5); x.sb(0x45, 0)
        o.sb(0x186, mp); o.sb(0x1AD, tgt2); o.sw(0x190, st); o.sb(0x60, b60)
    print('EA 04 1A (attack 0x1A costs %d MP); the monster is slot 3' % b.rom[0x102ADF + 0x1A * 0x40])
    for ha, ma, t2, mp, b60, st in (((1, 1, 1), (1, 1), 0, 99, 0, 0), ((0, 1, 1), (1, 1), 0, 99, 0, 0), ((1, 0, 0), (0, 0), 1, 99, 0, 0), ((1, 1, 1), (1, 1), 4, 99, 0, 0),
                                    ((1, 1, 1), (1, 1), 0, 0, 0, 0), ((1, 1, 1), (1, 1), 0, 0, 0xE0, 0), ((1, 1, 1), (1, 1), 0, 0, 0, 0x80), ((1, 1, 1), (1, 1), 0, 99, 0xE0, 0x80)):
        setup(ha, ma, t2, mp, b60, st)
        for k in range(0x176, 0x17B): o.sb(k, 0xEE)
        b.run(bytes([0xEA, 0x04, 0x1A]))
        print('  heroes active %s, slots 4/5 active %s, tgt2 %02X, MP %2d, +0x60 %02X, status %02X -> cmd %02X, +0x176..0x17A %s'
              % (ha, ma, t2, mp, b60, st, o.b(0x140), ' '.join('%02X' % o.b(k) for k in range(0x176, 0x17B))))

MODELLED = sorted(set(list(range(0x00, 0x31)) + [0x31, 0x34, 0x46, 0x49, 0x4C, 0x4E, 0x51, 0x53, 0x54, 0x56, 0x58, 0x5A, 0x5D, 0x5F, 0x60, 0x66, 0x68, 0x6A, 0x6F, 0x71, 0x73, 0x77, 0x79, 0x7B,
                      0x75, 0x85, 0xEA, 0xEE, 0x9D, 0x9E, 0x9F, 0xA5, 0xB1, 0xB4, 0xB7, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF, 0xC0, 0xC1, 0xC4, 0xD8, 0xDA, 0xDB, 0xDC, 0xE0, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8,
                      0xE9, 0xED, 0xEF, 0xFC, 0xFD, 0xFE, 0xFF]))


def fuzz(rom, state, ops, n, seed=1, slot=3):
    """One handler at a time: for every op in ops, n cases with random arguments (object refs 0-2 / 0x80-0x82, offsets, values, jump offset) in random worlds
    (positions in all distance bands and at the screen edges, statuses, random bytes in the fields 0x180-0x1FF of every record, random variables and targets).
    The real handler ($C1:251A at a patched script address) and ai_vm.VM.op are run on the same world; compared: return value (FF continue / 00 yield),
    script pointer, call stack, variables, targets, saved position, random bytes drawn, command bytes and every byte of the records of slots 0-5."""
    import monster_model, ai_vm, export_ai_vm
    rom = bytearray(rom)
    s = monster_model.Session(rom, state, 0, seed, slot)
    rnd = s.rnd
    c, o, vm = s.c, s.o, s.vm
    out = {}
    for op in ops:
        bad = tot = skip = 0
        for _ in range(n):
            s.left = 0
            spec = s.build_spec()
            nargs = export_ai_vm.nargs_of(op)
            refs = [0x80, 0x81, 0x82, 0, 1, 2]
            args = [rnd.choice(refs) if (i == 0 and op in (0x2D, 0x2E, 0x2F, 0x30, 0xBA, 0xBB, 0xBC, 0xBD, 0xDA, 0xDB, 0xDC, 0x5F, 0x60)) else rnd.choice([rnd.randrange(256), rnd.randrange(16), 0, 0xFF])
                    for i in range(nargs)]
            if op in (0x2D, 0x2E, 0x2F, 0x30, 0xBA, 0xBB, 0xBC, 0xBD, 0xDA, 0xDB, 0xDC): args[1] = rnd.choice([0x02, 0x10, 0x01, 0x6D, 0x1D, 0x3D, 0x0C, 0x2C, 0x2D, rnd.randrange(0x70)])
            if op in (0xE9, 0xEA): args[1] = rnd.randrange(0x40)
            code = bytes([op] + args + [rnd.choice([0x85, 0x88, 0xC3])])
            if op == 0xFF: code = bytes([0xFF, 0x71, 0x00])
            if op in (0x01,): code = bytes([0x01, 0x85])
            for i, x in enumerate(code): rom[BASE + P + i] = x
            for sl in range(6):
                for off in range(0x180, 0x200):
                    if off not in spec[sl] and rnd.random() < 0.5: spec[sl][off] = rnd.choice([0, 0, 1, rnd.randrange(256)])
            for sl in range(6): spec[sl].pop(0x1AC, None); spec[sl].pop(0x1AD, None)
            if op in (0x2D, 0x2E, 0x2F, 0x30, 0xBA, 0xBB, 0xBC, 0xBD) and rnd.random() < 0.5:        # make the compared field equal / close to the constant
                sl = rnd.choice([0, 1, 2]); spec[sl][0x180 + args[1]] = (args[2] + rnd.choice([-1, 0, 1])) & 0xFF
            if op in (0x2D, 0x2E, 0x2F, 0x30, 0xBA, 0xBB, 0xBC, 0xBD): spec[slot][0x180 + args[1]] = (args[2] + rnd.choice([-1, 0, 1])) & 0xFF
            state_in = dict(pc=P, stack=[rnd.choice([0x100, 0x200]) for _ in range(rnd.choice([0, 0, 1, 3, 14, 15]))], var=[rnd.randrange(16) for _ in range(4)],
                            saved=rnd.choice([(0xFFFF, 0xFFFF), (spec[slot][0x20] | spec[slot][0x21] << 8, spec[slot][0x22] | spec[slot][0x23] << 8), (5, 5)]),
                            tgt=rnd.choice([0xFF, 0, 1, 2, 0, 1]), tgt2=rnd.choice([0xFF, 0, 1, 2, 3, 4, 5]), mem=[rnd.randrange(0x10000) for _ in range(16)])
            for sl in range(6):
                base = 0xE000 + 0x200 * sl
                c.wram[base:base + 0x200] = bytes(0x200)
                for off, v in spec[sl].items(): c.wram[base + off] = v
            s.state = state_in; s.apply_state()
            rec = bytearray(0x200); vm.write_state(rec)
            for off in list(range(0x144, 0x150)) + list(range(0x150, 0x170)) + [0x1AC, 0x1AD]: c.wram[o.base + off] = rec[off]
            before = [s.rec(sl) for sl in range(6)]
            recs = [bytearray(r) for r in before]
            w = ai_vm.World(ai_vm.Actor(m=recs[slot]), [ai_vm.Actor(m=recs[i]) for i in range(3)], mons={k: ai_vm.Actor(m=recs[k]) for k in (3, 4, 5) if k != slot}, slot=slot)
            rngb = [rnd.randrange(256) for _ in range(64)]
            s.forced[:] = rngb; s.rng_used = 0; s.engine = []
            s.env.call(0xC1251A, Y=o.base, m=1, x=0, long=False, DB=0x7E)
            a = c.A & 0xFF
            after = [s.rec(sl) for sl in range(6)]
            vm.draws = 0; vm.effects = []
            cmd = [0, None, None, None]
            try:
                r = vm.op(w, rngb, cmd)
            except ai_vm.VMError:
                skip += 1; continue
            for i, v in enumerate(cmd):
                if v is not None: recs[slot][0x140 + i] = v
            vm.write_state(recs[slot])
            tot += 1
            ok = (a == 0xFF) == (r is None) and vm.draws == s.rng_used
            for sl in range(6):
                ch_r = {k: after[sl][k] for k in range(0x200) if after[sl][k] != before[sl][k]}
                ch_m = {k: recs[sl][k] for k in range(0x200) if recs[sl][k] != before[sl][k]}
                ok = ok and ch_r == ch_m
            if not ok:
                bad += 1
                if bad <= 2: print('  MISMATCH op %02X args %s: real A=%02X pc=%04X, model %s pc=%04X' % (op, args, a, o.w(0x144), r, vm.pc))
            vm.visited.clear()
        out[op] = (tot, bad, skip)
        print('%02X %-18s %5d cases, %d mismatches (%d skipped: empty target dereferenced)' % (op, aidis.INFO[op][0] if op in aidis.INFO else '?', tot, bad, skip)); sys.stdout.flush()
    return out


def main():
    rom = romio.rom_from_argv(); state = sys.argv[1]
    if '--fuzz' in sys.argv:
        argv = list(sys.argv); sl = 3
        if '--slot' in argv:
            i = argv.index('--slot'); sl = int(argv[i + 1]); del argv[i:i + 2]
        sel = [x for x in argv[2:] if not x.startswith('--')]
        ops = [int(x, 16) for x in sel[0].split(',')] if sel and sel[0] != 'all' else MODELLED
        fuzz(rom, state, ops, int(sel[1]) if len(sel) > 1 else 300, slot=sl); return
    b = Bench(rom, state)
    b.env.obj(0).sw(0x190, 0)
    if '--new' in sys.argv:
        new_ops(b); return
    if '--new20' in sys.argv:
        new_ops_20(b); return
    print('--- control flow')
    r = b.run(bytes([0x01, 0x85])); show('01 JMP +5 (1-byte offset 0x85)', r)
    r = b.run(bytes([0x01, 0x00, 0x20])); show('01 JMP 2-byte offset 0x0020', r)
    r = b.run(bytes([0x01, 0xC1])); show('01 JMP -63 (0xC1)', r)
    r = b.run(bytes([0xFF, 0x00, 0x90])); show('FF CALL 0090 (stack push)', r)
    print('stack word at 0x150:', hex(b.o.w(0x150)), 'new pc', hex(r['pc']))
    r = b.run(bytes([0x00]), depth=0x1234); show('00 RET at depth 1 (pops 0x1234)', r)
    print('new pc', hex(r['pc']))
    print('--- variable ops (nibble variable 3 = obj+0x147 high nibble)')
    for v in (0, 1, 3):
        r = b.run(bytes([0x05, 0x85]), var=v); show('05 IF var3!=0 jump (var3=%d)' % v, r)
    for v in (0, 1):
        r = b.run(bytes([0x09, 0x85]), var=v); show('09 IF var3==0 jump (var3=%d)' % v, r)
    for v in (1, 2):
        r = b.run(bytes([0x0D, 0x01, 0x85]), var=v); show('0D 01 IF var3!=1 jump (var3=%d)' % v, r)
    for n in (2, 3, 4, 5, 7):
        cnt = collections.Counter()
        for _ in range(4000):
            b.run(bytes([0x2C, n]));  cnt[b.o.b(0x147) >> 4] += 1
        print('2C %02d  var3 = rand 0..%d: %s' % (n, n, dict(sorted(cnt.items()))))
    print('--- compare ops on object fields (argument 1 = object ref: 0x80 self, 0x81 current target slot; argument 2 = byte offset)')
    b.o.sw(0x182, 20)
    for hp in (9, 10):
        b.o.sw(0x182, hp)
        r = b.run(bytes([0xBD, 0x80, 0x02, 0x09, 0x00, 0x85])); show('BD 80 02 0009 (word self+0x182 > 9 jumps) hp=%d' % hp, r)
    b.o.sw(0x182, 20)
    for g in (0, 5):
        r = b.run(bytes([0x30, 0x80, 0x6D, 0x00, 0x85]), gauge=g); show('30 80 6D 00 (byte self+0x1ED > 0 jumps) 1ED=%d' % g, r)
    for t in (3, 0xFF):
        r = b.run(bytes([0x2F, 0x80, 0x2C, 0xFF, 0x85]), tgt=t); show('2F 80 2C FF (byte self+0x1AC < 0xFF jumps) 1AC=%02X' % t, r)
    print('--- target classes (distance d between monster and hero 0 on screen)')
    for d in (10, 16, 17, 32, 33, 48, 49, 64, 65, 96, 97):
        row = []
        for op in (0x31, 0x49, 0x4E, 0x53, 0x58):
            b.place(d); r = b.run(bytes([op, 0x85])); row.append('%02X:%s' % (op, 'jump' if r['adv'] != 2 else 'fall'))
        sel = []
        for op in (0xA5, 0xB1, 0xB4, 0xB7, 0x5D):
            b.place(d); r = b.run(bytes([op])); sel.append('%02X->1AC=%02X' % (op, b.o.b(0x1AC)))
        print('d=%3d  IF(no hero within 16/32/48/64/any)=%s  select=%s' % (d, ' '.join(row), ' '.join(sel)))
    print('--- class vs current target (op 4C/51/56 jump unless target valid and within 32/48/64)')
    for d in (30, 33, 47, 50, 63, 66):
        row = []
        for op in (0x4C, 0x51, 0x56):
            b.place(d); b.o.sb(0x1AC, 0); r = b.run(bytes([op, 0x85]), tgt=0); row.append('%02X:%s' % (op, 'jump' if r['adv'] != 2 else 'fall'))
        print('d=%3d %s' % (d, ' '.join(row)))
    b.place(30); r = b.run(bytes([0x4C, 0x85]), tgt=0xFF); show('4C with no target', r)
    print('--- position memory (9F stores, 9D jumps when unchanged)')
    b.place(40)
    r = b.run(bytes([0x9F])); show('9F store screen position', r)
    print('saved:', b.o.w(0x148), b.o.w(0x14A))
    r = b.run(bytes([0x9D, 0x85]), reseed=False); show('9D after 9F (unchanged -> jump)', r)
    b.o.sw(0x20, 131)
    r = b.run(bytes([0x9D, 0x85]), reseed=False); show('9D after moving x by 3 (-> fall through)', r)
    print('--- command ops (cmd bytes obj+0x140..0x143)')
    b.place(40)
    r = b.run(bytes([0xE0, 0x09, 0x04, 0x00])); show('E0 09 04 00', r)
    r = b.run(bytes([0xE2, 0x05])); show('E2 05', r)
    r = b.run(bytes([0xE4, 0x02, 0x00]), tgt=0); show('E4 02 00 target at +40,0', r)
    r = b.run(bytes([0xFD, 0x02, 0x00]), tgt=0); show('FD 02 00 target at +40,0', r)
    r = b.run(bytes([0xE6, 0x02, 0x00]), tgt=0); show('E6 02 00 target at +40,0', r)
    r = b.run(bytes([0xFE, 0x02, 0x00]), tgt=0); show('FE 02 00 target at +40,0', r)
    r = b.run(bytes([0xE4, 0x02, 0x00]), tgt=0xFF); show('E4 02 00 with no target', r)
    r = b.run(bytes([0xE8]), gauge=0); show('E8 gauge 0', r)
    r = b.run(bytes([0xE8]), gauge=7); show('E8 gauge 7', r)
    b.o.sb(0x10, 1); b.o.sb(0x6, 0); b.o.sb(0x7, 0)
    r = b.run(bytes([0xE3, 0x00, 0x00])); show('E3 00 00 facing 1, no velocity', r)
    b.o.sb(0x10, 0)
    r = b.run(bytes([0xE3, 0x00, 0x00])); show('E3 00 00 facing 0, no velocity', r)
    new_ops(b)


if __name__ == '__main__':
    main()
