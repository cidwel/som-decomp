"""The AI of the computer-controlled heroes: the AI bytecode script at entry 0x58EA (object ids 0x80-0x82, the same machine $C1:2552 as the monsters).
usage: hero_ai.py ROM STATE [N_STEPS=4000] [--seed K] [--slot S]       compare tools/ai_vm.py with the real AI step in randomised worlds
       hero_ai.py ROM STATE list                                       print the script
       hero_ai.py ROM STATE vectors OUT.json [N=300]                    real-ROM steps for testing a port (sparse records in and out)
Each step writes a random world into zeroed object records (the AI hero in slot S = 1 by default, the other two heroes, three monster slots with
monster or non-monster ids, positions on and off screen and in every distance class, status words with blocking bits, weapon type +0x1E4, weapon
gauge +0x1ED, charge stage +0x19B, flag +0x14C), the party settings $CC73 + slot (behaviour 0-3) and $CC7D + slot (charge level 0-8), the
controller bindings $D9-$DB, and a machine state (pc on any reachable instruction, call stack, variables, targets), runs the real step
$C1:2552 and the model on the same world and the same random bytes ($C1:26FB is replaced by a list), and compares command bytes, pc, stack, variables,
targets, saved position, random bytes drawn and every byte of the six records that either side changed.
Findings: docs/hero-ai.md."""
import sys, os, random, collections, math
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import romio, combat_env as ce, ai_vm, aidis

ENTRY = 0x58EA
OBJ = 0xE000


def reach(rom):
    seen = set(); st = [ENTRY]
    while st:
        p = st.pop()
        while p not in seen:
            ln, t, tg, ft = aidis.decode(rom, p)
            seen.add(p)
            if tg is not None: st.append(tg)
            if not ft: break
            p += ln
    return sorted(seen)


def listing(rom):
    for p in reach(rom):
        ln, t, tg, ft = aidis.decode(rom, p)
        print('%04X  %s' % (p, t))


class Bench:
    def __init__(self, rom, state, slot=1, seed=1):
        self.rom, self.slot = rom, slot
        self.env = e = ce.Env(rom, state); self.c = c = e.c
        self.rnd = random.Random(seed)
        self.forced = []; self.used = 0
        def rng_hook(cp):
            v = self.forced.pop(0) if self.forced else 0
            self.used += 1
            cp.A = (cp.A & 0xFF00) | v
            cp.PC = (cp.pull16() + 1) & 0xFFFF; return True
        c.hooks[0xC126FB] = rng_hook
        self.reach = reach(rom)
        self.cond = [p for p in self.reach if aidis.decode(rom, p)[2] is not None and rom[aidis.BASE + p] not in (0x01, 0xFF)]
        self.calls = [p for p in self.reach if rom[aidis.BASE + p] == 0xFF]
        self.vm = ai_vm.VM(rom, ENTRY)
        self.visited = set(); self.branches = set()

    def world(self):
        r = self.rnd; s = self.slot
        me_x, me_y = 128 + r.randint(-40, 40), 112 + r.randint(-40, 40)
        recs = [bytearray(0x200) for _ in range(6)]
        def put(sl, off, v, n=1):
            for i in range(n): recs[sl][off + i] = (v >> (8 * i)) & 0xFF
        for sl in range(6):
            if sl == s:
                x, y, h = me_x, me_y, 0
            else:
                band = r.choice([6, 12, 16, 17, 24, 32, 33, 40, 48, 49, 56, 64, 65, 80, 96, 97, 120, 300])
                ang = r.uniform(0, 2 * math.pi)
                dx, dy = int(round(band * math.cos(ang))), int(round(band * math.sin(ang)))
                if r.random() < 0.3:
                    if r.random() < 0.5: dx = r.randint(-15, 15)
                    else: dy = r.randint(-15, 15)
                x, y = (me_x + dx) & 0xFFFF, (me_y + dy) & 0xFFFF
                if r.random() < 0.04: x = r.choice([255, 256, 300])
                h = r.choice([0, 0, 0, 3]) if sl >= 3 else 0
                y = (y + h) & 0xFFFF
            put(sl, 0, 1 if sl == s or r.random() < 0.8 else r.choice([0, 2]))
            put(sl, 0x20, x, 2); put(sl, 0x22, y, 2); put(sl, 0x45, h)
            put(sl, 0x180, (0x80 + sl if sl < 3 else (r.randrange(0x57) if r.random() < 0.85 else r.choice([0x80, 0x90, 0xEA]))))
            st = 0 if r.random() < 0.75 else r.choice([0x0020, 0x0040, 0x0400, 0x8000, 0x0004, 0x0010, 0x0080])
            put(sl, 0x190, st, 2)
            put(sl, 0x10, r.choice([0, 1, 2, 0x82]))
        put(s, 0x1E4, r.choice([0, 0, 1, 2, 3, 4, 5, 6, 7]))
        put(s, 0x1ED, r.choice([0, 0, 0, 1, 30]))
        put(s, 0x19B, r.randint(0, 8)); put(s, 0x14C, r.choice([0, 0, 1]))
        ram = {0xCC73 + (s & 3): r.randint(0, 3) | r.choice([0, 0, 0x80]) * 0, 0xCC7D + (s & 3): r.choice([0, 0, 1, 2, 4, 8])}
        others = [k for k in range(3) if k != s]
        b = r.choice([0, 1 << others[0], 1 << others[1], (1 << others[0]) | 1])
        pads = [b, r.choice([0, 0, 1 << others[1]]), 0]
        return recs, ram, pads

    def inject(self):
        r = self.rnd; vm = self.vm
        unseen = [p for p in self.reach if p not in self.visited]
        pc = r.choice(unseen) if unseen and r.random() < 0.7 else r.choice(self.reach)
        rets = [p + 3 for p in self.calls]
        vm.pc = pc; vm.stack = [r.choice(rets) for _ in range(r.choice([0, 1, 1, 2, 3]))]
        vm.var = [r.randrange(16) for _ in range(4)]
        vm.tgt = r.choice([0xFF, 3, 4, 5]); vm.tgt2 = r.choice([0xFF, 0xFF, 3])
        vm.saved = r.choice([(0xFFFF, 0xFFFF), (128, 112)])
        vm.mem = [0] * 16
        for i, p in enumerate(vm.stack): vm.mem[i] = p

    def step(self, capture=None):
        c, r, vm, s = self.c, self.rnd, self.vm, self.slot
        if r.random() < 0.3: self.inject()
        recs, ram, pads = self.world()
        vm.write_state(recs[s])
        for sl in range(6): c.wram[OBJ + 0x200 * sl:OBJ + 0x200 * sl + 0x200] = bytes(recs[sl])
        for k in range(0xCC70, 0xCC80): c.wram[k] = ram.get(k, 0)
        for k in range(3): c.wram[0xD9 + k] = pads[k]
        before = [bytes(rc) for rc in recs]
        rng = [r.randrange(256) for _ in range(64)]
        self.forced[:] = list(rng); self.used = 0
        state_in = (vm.pc, list(vm.stack), list(vm.var), vm.tgt, vm.tgt2)
        self.env.call(0xC12552, X=0x200 * s, m=1, x=0, long=False, DB=0x7E, max_steps=2000000)
        real = [bytes(c.wram[OBJ + 0x200 * sl:OBJ + 0x200 * sl + 0x200]) for sl in range(6)]
        if capture is not None:
            capture.append(dict(slot=s, ram={str(k): v for k, v in ram.items()}, pads=pads, rng=rng[:max(self.used, 1)],
                                recs=[{str(o): v for o, v in enumerate(b) if v} for b in before],
                                out={str(o): real[s][o] for o in range(0x140, 0x150) if real[s][o] != before[s][o] or 0x140 <= o < 0x144} | {str(o): real[s][o] for o in (0x1AC, 0x1AD)}))
        mrecs = [bytearray(b) for b in before]
        w = ai_vm.World(ai_vm.Actor(m=mrecs[s]), [ai_vm.Actor(m=mrecs[i]) for i in range(3)], mons={k: ai_vm.Actor(m=mrecs[k]) for k in (3, 4, 5)},
                        slot=s, ram=ram, pads=pads)
        w.heroes[s] = w.me
        try:
            cmd, _ = vm.step(w, rng)
        except ai_vm.VMError as ex:
            self.resync(real[s]); return ('error', str(ex), state_in)
        self.visited |= vm.visited; self.branches |= vm.branches
        diffs = []
        if vm.draws != self.used: diffs.append(('draws', vm.draws, self.used))
        for sl in range(6):
            for off in range(0x200):
                if bytes(mrecs[sl])[off] != real[sl][off] and not (sl == s and 0x150 <= off < 0x170):
                    diffs.append((sl, hex(off), mrecs[sl][off], real[sl][off]))
        self.resync(real[s])
        return ('ok' if not diffs else 'diff', diffs[:6], state_in)

    def resync(self, rec):
        vm = self.vm
        vm.pc = rec[0x144] | rec[0x145] << 8
        vm.stack = [rec[0x150 + 2 * i] | rec[0x151 + 2 * i] << 8 for i in range(rec[0x14F])]
        vm.mem = [rec[0x150 + 2 * i] | rec[0x151 + 2 * i] << 8 for i in range(16)]
        vm.var = [rec[0x146] & 15, rec[0x146] >> 4, rec[0x147] & 15, rec[0x147] >> 4]
        vm.saved = (rec[0x148] | rec[0x149] << 8, rec[0x14A] | rec[0x14B] << 8)
        vm.tgt, vm.tgt2 = rec[0x1AC], rec[0x1AD]


def main():
    args = sys.argv[1:]
    opts = {}
    for k in ('--seed', '--slot'):
        if k in args:
            i = args.index(k); opts[k] = int(args[i + 1]); del args[i:i + 2]
    rom = romio.load(args[0]); state = args[1]
    if len(args) > 2 and args[2] == 'list':
        listing(rom); return
    if len(args) > 2 and args[2] == 'vectors':
        import json
        b = Bench(rom, state, opts.get('--slot', 1), opts.get('--seed', 7)); cap = []
        for _ in range(int(args[4]) if len(args) > 4 else 300): b.step(cap)
        json.dump(dict(source='tools/hero_ai.py vectors: real AI steps of the hero script (entry 0x58EA) on random worlds; recs = non-zero bytes of the six records before the step, out = machine bytes of the hero after it', entry=ENTRY, cases=cap), open(args[3], 'w'), separators=(',', ':'))
        print(len(cap), 'cases'); return
    n = int(args[2]) if len(args) > 2 else 4000
    b = Bench(rom, state, opts.get('--slot', 1), opts.get('--seed', 1))
    res = collections.Counter(); shown = 0; cmds = collections.Counter()
    for _ in range(n):
        kind, d, st = b.step()
        res[kind] += 1
        cmds[b.c.wram[OBJ + 0x200 * b.slot + 0x140]] += 1
        if kind != 'ok' and shown < 6:
            shown += 1; print(kind, 'state', '%04X' % st[0], st[1:], d)
    unseen = sorted((p, t) for p in b.cond for t in (True, False) if (p, t) not in b.branches)
    print('steps', n, dict(res))
    print('instructions executed %d of %d; branch outcomes not seen: %d of %d' % (len(b.visited & set(b.reach)), len(b.reach), len(unseen), 2 * len(b.cond)))
    print('first command bytes:', {'%02X' % k: v for k, v in sorted(cmds.items())})


if __name__ == '__main__':
    main()
