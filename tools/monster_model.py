"""Check the Python model of the AI bytecode machine (tools/ai_vm.py) against the real handlers, step by step, in randomised worlds.
usage: monster_model.py ROM STATE [ID[,ID|LO-HI...]|all] [N_STEPS] [--slot S] [--seed K] [--quiet]      (default ids 0,3,0x0D; default 6000 steps per id)
For every id the monster is created by the game's spawner in slot S (default 3) and the real AI step ($C1:2552) is called N times. Before each step the
world is randomised and written into the object records of slots 0-5: the monster (position, jump height, facing, HP, weapon gauge, MP, status word,
the byte fields that its script reads), the three heroes (positions on screen, off screen, in each distance band, near the 255 / 223 limits, active flag, status
word with valid and invalid bits, level, HP and the fields the script tests) and the two other monster slots (active, monster id, position, status, HP).
The values the script compares are taken from the script itself (constants +-1), so that every branch of every compare is reached. Every few steps the
machine state itself is replaced (script pointer on a random reachable instruction, return stack, the four variables, saved position, targets) so that
instructions that a short run never reaches are executed too. The RNG routine $C1:26FB is replaced by a list of random bytes that the model consumes in the
same order. After the step the model and the game must agree on: command bytes, script pointer, call stack, variables, targets, saved position, the number of
random bytes drawn and every byte of the object records of slots 0-5 that either of them changed. Output: steps compared, mismatches, instruction
coverage of the script, distribution of the first command written.
library: Session(rom, state, mid, seed, slot).step() -> dict with the world written, the machine state before, the real outputs, the model outputs, ok"""
import sys, os, random, collections, math
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import romio, ai_sim, ai_vm, aidis

OBJ = 0xE000
GOOD_BITS = [0x0004, 0x0008, 0x0010, 0x0080, 0x0100, 0x0200, 0x1000, 0x2000, 0x4000, 0x0001, 0x0002, 0x0800]
BAD_BITS = [0x0020, 0x0040, 0x0400, 0x8000]


LAST_ID = 0x53          # last ordinary monster whose script ai_vm.py models and the checks cover


def parse_ids(arg):
    """'all' = 0x00-LAST_ID; else a comma list of ids and ranges, e.g. '0,3,0x20-0x53'"""
    if arg == 'all': return list(range(LAST_ID + 1))
    out = []
    for part in arg.split(','):
        if '-' in part:
            lo, hi = (int(x, 0) for x in part.split('-'))
            out += range(lo, hi + 1)
        else: out.append(int(part, 0))
    return out


def entry_of(rom, mid): return rom[0x100000 + mid * 16 + 9] | rom[0x100000 + mid * 16 + 10] << 8


def static_reach(rom, pc0):
    seen = set(); st = [pc0]
    while st:
        p = st.pop()
        while p not in seen:
            ln, t, tg, ft = aidis.decode(rom, p)
            seen.add(p)
            if tg is not None: st.append(tg)
            if not ft: break
            p += ln
    return seen


def script_probes(rom, entry):
    """Constants the script compares: {('self'|'tgt'|'tgt2'|slot, offset): {'consts': set, 'masks': set, 'word': bool}}, plus the MP thresholds of the
    cast ops and the list of reachable pcs."""
    probes = collections.defaultdict(lambda: dict(consts=set(), masks=set(), word=False))
    mp = set(); calls = []
    reach = sorted(static_reach(rom, entry))
    names = {0x80: 'self', 0x81: 'tgt', 0x82: 'tgt2'}
    for p in reach:
        op = rom[aidis.BASE + p]; a = [rom[aidis.BASE + p + 1 + i] for i in range(5)]
        if op in (0x2D, 0x2E, 0x2F, 0x30, 0xBA, 0xBB, 0xBC, 0xBD, 0xDA, 0xDB, 0xDC):
            who = names.get(a[0], a[0]); off = a[1] + 0x180
            e = probes[(who, off)]
            if op in (0xBA, 0xBB, 0xBC, 0xBD):
                e['word'] = True; v = a[2] | a[3] << 8
            else: v = a[2]
            if op in (0x2D, 0x2E, 0xBA, 0xBB): e['masks'].add(v)
            else: e['consts'].add(v)
        if op in (0xE9, 0xEA): mp.add(rom[0x102ADF + a[1] * 0x40])
        if op == 0xFF: calls.append(p)
    return probes, sorted(mp), reach, calls


class Session:
    def __init__(self, rom, state, mid, seed=1, slot=3, cpu_class=None):
        self.rom, self.mid, self.slot = rom, mid, slot
        self.rnd = random.Random(seed * 1000 + mid)
        self.sim = s = ai_sim.Sim(rom, state, mid, (20, 25), only_hero0=False, slot=slot, cpu_class=cpu_class)
        self.env, self.c, self.o = s.env, s.c, s.o
        self.entry = entry_of(rom, mid)
        self.probes, self.mp_thr, self.reach, self.calls = script_probes(rom, self.entry)
        self.cond = [p for p in self.reach if aidis.decode(rom, p)[2] is not None and rom[aidis.BASE + p] not in (0x01, 0xFF)]
        self.hp_full = self.o.w(0x182) or 1          # NPC kinds have no HP
        self.vm = None
        self.forced = []
        self.k = 0
        c = self.c
        def rng_hook(cp):
            v = self.forced.pop(0) if self.forced else 0
            self.rng_used += 1
            cp.A = (cp.A & 0xFF00) | v
            cp.PC = (cp.pull16() + 1) & 0xFFFF; return True
        self.rng_used = 0
        self.engine = []
        def engine_hook(name):
            def f(cp):
                self.engine.append((name, cp.X))
                cp.PC = (cp.pull16() + 1) & 0xFFFF; cp.PB = cp.pull8(); return True
            return f
        c.hooks[0xC0001B] = engine_hook('cast')        # $C0:001B start of a cast / special attack, $C0:003C object graphic refresh: engine routines, not part of the machine
        c.hooks[0xC0003C] = engine_hook('flash')
        c.hooks[0xC126FB] = rng_hook
        c.hooks[0xC12552] = lambda cp: False
        self.visited = set()
        self.branches = set()
        self.left = 0
        self.reset()

    # ---- state ---------------------------------------------------------------------------------------------------------------------------
    def reset(self):
        if self.vm: self.visited |= self.vm.visited; self.branches |= self.vm.branches
        self.vm = ai_vm.VM(self.rom, self.entry)
        self.state = dict(pc=self.entry, stack=[], var=[0, 0, 0, 0], saved=(0xFFFF, 0xFFFF), tgt=0xFF, tgt2=0xFF, mem=[0] * 16)
        self.apply_state()
        self.left = 0
        self.injected = False

    def apply_state(self):
        st, vm, o = self.state, self.vm, self.o
        vm.pc, vm.stack, vm.var, vm.saved, vm.tgt, vm.tgt2 = st['pc'], list(st['stack']), list(st['var']), tuple(st['saved']), st['tgt'], st['tgt2']
        vm.mem = list(st['mem'])
        for i, p in enumerate(vm.stack): vm.mem[i] = p
        st['mem'] = list(vm.mem)

    def unseen_branches(self):
        seen = self.branches | self.vm.branches
        return [(p, t) for p in self.cond for t in (True, False) if (p, t) not in seen]

    def inject_state(self, focus=None):
        rnd = self.rnd
        ret = [p + 3 for p in self.calls]
        depth = rnd.choice([0, 0, 0, 1, 1, 2, 3, 14]) if ret else 0
        unseen = [p for p in self.reach if p not in self.visited and p not in self.vm.visited]
        pc = rnd.choice(unseen) if unseen and rnd.random() < 0.8 else rnd.choice(self.reach)
        if focus is not None: pc = focus
        self.state = dict(pc=pc, stack=[rnd.choice(ret) for _ in range(depth)], var=[rnd.choice([0, 0, 1, 2, 3, 7, 15, rnd.randrange(16)]) for _ in range(4)],
                          saved=rnd.choice([(0xFFFF, 0xFFFF), (rnd.randrange(256), rnd.randrange(224))]), tgt=rnd.choice([0xFF, 0, 1, 2]),
                          tgt2=rnd.choice([0xFF, 0xFF, 0, 1, 2, 3, 4, 5, self.slot]), mem=[rnd.choice(ret) if ret and rnd.random() < 0.5 else 0 for _ in range(16)])
        self.apply_state()
        self.injected = True

    # ---- world ---------------------------------------------------------------------------------------------------------------------------
    def pick(self, key, word=False):
        """a value for a field the script compares: constants +-1, masks, or random"""
        rnd = self.rnd
        e = self.probes.get(key)
        hi = 0xFFFF if word else 0xFF
        if e is None: return rnd.choice([0, 0, rnd.randint(0, hi)])
        cands = {0, 1}
        for c in e['consts']: cands |= {max(0, c - 1), c, min(hi, c + 1)}
        for m in e['masks']:
            bits = [b for b in range(16 if word else 8) if m >> b & 1]
            cands.add(m); cands.add(m ^ (1 << bits[0]) if bits else 0)
            if bits: cands.add(1 << rnd.choice(bits))
        r = rnd.random()
        if r < 0.75: return rnd.choice(sorted(cands))
        return rnd.randint(0, hi) if not word or rnd.random() < 0.5 else rnd.randint(0, 0x300)

    def status_word(self, key):
        rnd = self.rnd
        r = rnd.random()
        if r < 0.55: v = 0
        elif r < 0.93:
            v = 0
            for b in GOOD_BITS:
                if rnd.random() < 0.25: v |= b
            if key in self.probes: v |= self.pick(key, True) if rnd.random() < 0.5 else 0
            v &= ~0x8460
        else: v = rnd.choice(BAD_BITS) | (rnd.choice(GOOD_BITS) if rnd.random() < 0.3 else 0)
        return v & 0xFFFF

    def draw_persistent(self):
        rnd = self.rnd
        self.heroes = []
        for i in range(3):
            self.heroes.append(self.draw_other(i, hero=True))
        self.mons = {}
        for s in (3, 4, 5):
            if s != self.slot: self.mons[s] = self.draw_other(s, hero=False)
        self.me_spec = dict(hp=rnd.choice(sorted({v for k, e in self.probes.items() if k[0] == 'self' and k[1] == 0x182 for c in e['consts'] for v in (c - 1, c, c + 1)}
                                                | {self.hp_full, 1, rnd.randint(1, self.hp_full)})),
                            gauge=self.pick(('self', 0x1ED)) if rnd.random() < 0.7 else rnd.choice([0, 0, 3, 99]),
                            facing=rnd.choice([0, 1, 2, 0x82]), mp=rnd.choice(sorted(set(self.mp_thr) | {c - 1 for c in self.mp_thr if c} | {0, 99, rnd.randrange(100)})),
                            st=0 if rnd.random() < 0.85 else rnd.choice([0x80, 0x10, 0x0100, 0x80 | 0x10, 0x0400]),
                            b60=rnd.choice([0, 0, 0xE0, rnd.randrange(256)]), b191=rnd.choice([0, 0, 0, 0x20, 0x21, 1]),
                            extras={k[1]: (self.pick(k, self.probes[k]['word']), 2 if self.probes[k]['word'] else 1) for k in self.probes if k[0] == 'self' and k[1] not in (0x182, 0x1ED, 0x1AC, 0x1AD)},
                            fl=[rnd.randrange(256) for _ in range(5)], c0=rnd.randrange(256))
        self.left = rnd.randint(5, 30)

    def draw_other(self, slot, hero):
        rnd = self.rnd
        band = rnd.choice([8, 14, 20, 30, 33, 40, 47, 52, 62, 70, 90, 100, 140, 400])
        ang = rnd.uniform(0, 360)
        dx = int(round(band * math.cos(math.radians(ang)))); dy = int(round(band * math.sin(math.radians(ang))))
        r = rnd.random()
        if r < 0.25:                                    # axis-aligned lane cases
            if rnd.random() < 0.5: dx = rnd.randint(-40, 40)
            else: dy = rnd.randint(-40, 40)
        elif r < 0.29: dx = rnd.choice([200, -200, 255]); dy = rnd.choice([160, -90, 100])
        elif r < 0.50:                                  # exact edges of the distance classes: dx^2 + dy^2 = threshold - 1, threshold, threshold + 1
            t = rnd.choice([0x100, 0x400, 0x900, 0x1000, 0x2400]) + rnd.choice([-1, 0, 1, 0])
            dx = rnd.randint(0, int(math.isqrt(t)))
            dy = math.isqrt(max(0, t - dx * dx)) + rnd.choice([0, 0, 1, -1])
            dx, dy = dx * rnd.choice([1, -1]), dy * rnd.choice([1, -1])
            if rnd.random() < 0.5: dx, dy = dy, dx
        st = self.status_word(('tgt', 0x190)) if True else 0
        if hero: active = 1 if (slot == 0 or rnd.random() < 0.6) else 0
        else: active = 1 if rnd.random() < 0.55 else rnd.choice([0, 0, 2])
        ex = {}
        for k in self.probes:
            if k[0] in ('tgt', 'tgt2', slot) and k[1] not in (0x190, 0x191, 0x181, 0x182, 0x1AC, 0x1AD):
                ex[k[1]] = self.pick(k, self.probes[k]['word'] and False)
        lvl_key = ('tgt', 0x181)
        return dict(dx=dx, dy=dy, st=st, active=active, ex=ex, h=0 if hero or rnd.random() < 0.6 else rnd.randint(1, 15),
                    level=self.pick(lvl_key) if lvl_key in self.probes else rnd.randrange(80),
                    hp=self.pick(('tgt2', 0x182), True) if ('tgt2', 0x182) in self.probes and rnd.random() < 0.8 else rnd.randint(0, 300),
                    mid=rnd.choice([0, 3, 0x10, 0x1F, 0x7F]) if rnd.random() < 0.85 else rnd.choice([0x80, 0x83, 0xFF]),
                    tgt_word={k[1]: self.pick(k, True) for k in self.probes if k[0] in ('tgt', 'tgt2') and self.probes[k]['word'] and k[1] not in (0x190, 0x182)})

    def build_spec(self):
        """Fields written into the object records before the step: {slot: {offset: value}}"""
        rnd = self.rnd
        if self.left <= 0: self.draw_persistent()
        self.left -= 1
        ms = self.me_spec
        if rnd.random() < 0.15: ms['gauge'] = self.pick(('self', 0x1ED)) if rnd.random() < 0.7 else rnd.choice([0, 0, 3, 99])
        if rnd.random() < 0.05: ms['hp'] = rnd.choice([self.hp_full, 1, rnd.randint(1, self.hp_full)])
        if rnd.random() < 0.3: ms['facing'] = rnd.choice([0, 1, 2, 0x82])
        vm = self.vm
        mx, my = 128 + rnd.randint(-30, 30), 112 + rnd.randint(-30, 30)
        mh = rnd.randint(1, 15) if rnd.random() < 0.1 else 0
        if rnd.random() < 0.12:                         # at the edges of the on-screen box tested by op 5F
            mx = rnd.choice([6, 7, 8, 9, 10, 245, 246, 247, 248, 249, 250, 255, 256])
            if rnd.random() < 0.5: my = (rnd.choice([6, 7, 8, 9, 10, 214, 215, 216, 217, 218, 223, 224]) + mh) & 0xFFFF
        if vm.saved[0] != 0xFFFF and rnd.random() < 0.5: mx, my = vm.saved[0], (vm.saved[1] + mh) & 0xFFFF
        spec = {s: {} for s in range(6)}
        def put(slot, off, v, width=1):
            for i in range(width): spec[slot][off + i] = (v >> (8 * i)) & 0xFF
        me_ey = (my - mh) & 0xFFFF
        sl = self.slot
        for off in (0x140, 0x141, 0x142, 0x143, 0x14C, 0x14D, 0x14E): put(sl, off, 0)
        put(sl, 0, 1); put(sl, 0x20, mx, 2); put(sl, 0x22, my, 2); put(sl, 0x45, mh); put(sl, 0x10, ms['facing']); put(sl, 0x180, self.mid)
        put(sl, 0x182, ms['hp'], 2); put(sl, 0x1ED, ms['gauge']); put(sl, 0x186, ms['mp']); put(sl, 0x190, ms['st'], 2); put(sl, 0x60, ms['b60'])
        put(sl, 0x191, ms['b191'] | (ms['st'] >> 8)); put(sl, 0x6, 0); put(sl, 0x7, 0); put(sl, 0x1C0, ms['c0'])
        for i, off in enumerate((0x1E3, 0x1E4, 0x1E8, 0x1E9, 0x19B)): put(sl, off, ms['fl'][i])
        for off, (v, width) in ms['extras'].items(): put(sl, off, v, width)          # word fields (BA-BD on self) get both bytes
        for i in range(3):
            self.fill_other(spec, i, self.heroes[i], mx, me_ey, True)
        for s, d in self.mons.items():
            self.fill_other(spec, s, d, mx, me_ey, False)
        return spec

    def fill_other(self, spec, slot, d, mx, mey, hero):
        rnd = self.rnd
        jx = rnd.randint(-3, 3) if rnd.random() < 0.5 else 0
        jy = rnd.randint(-3, 3) if rnd.random() < 0.5 else 0
        x, ey = mx + d['dx'] + jx, mey + d['dy'] + jy
        r = rnd.random()
        if r < 0.01: x = rnd.choice([255, 256, 300, 0xFFF0])
        elif r < 0.02: ey = rnd.choice([223, 224, 230, 0xFFF0])
        h = d['h']
        y = (ey + h) & 0xFFFF
        def put(off, v, width=1):
            for i in range(width): spec[slot][off + i] = (v >> (8 * i)) & 0xFF
        put(0, d['active']); put(0x20, x & 0xFFFF, 2); put(0x22, y, 2); put(0x45, h); put(0x190, d['st'], 2); put(0x181, d['level']); put(0x182, d['hp'], 2)
        put(0x180, 0 if hero else d['mid'])
        for off, v in d['ex'].items(): put(off, v)
        for off, v in d['tgt_word'].items(): put(off, v, 2)

    # ---- one step ------------------------------------------------------------------------------------------------------------------------
    def rec(self, slot): return bytearray(self.c.wram[OBJ + 0x200 * slot:OBJ + 0x200 * slot + 0x200])

    def step(self):
        rnd, c, o = self.rnd, self.c, self.o
        k = self.k
        if k % 150 == 0 and k: self.reset()
        elif k and rnd.random() < (0.25 if len(self.visited | self.vm.visited) < len(self.reach) else 0.08): self.inject_state()
        elif k and rnd.random() < 0.3 and self.unseen_branches():
            self.inject_state(focus=rnd.choice(self.unseen_branches())[0])          # aim at a conditional op one outcome of which has not been seen yet
            self.left = 0
        spec = self.build_spec()
        rng = [rnd.randrange(256) for _ in range(256)]
        state_in = dict(pc=self.vm.pc, stack=list(self.vm.stack), mem=list(self.vm.mem), var=list(self.vm.var), saved=self.vm.saved, tgt=self.vm.tgt, tgt2=self.vm.tgt2)
        for s in range(6):
            base = OBJ + 0x200 * s
            c.wram[base:base + 0x200] = bytes(0x200)          # records are rebuilt from zero every step: nothing but the specified fields exists
            for off, v in spec[s].items(): c.wram[base + off] = v
        rec = bytearray(0x200)
        self.vm.write_state(rec)
        base = OBJ + 0x200 * self.slot
        for off in list(range(0x144, 0x150)) + list(range(0x150, 0x170)) + [0x1AC, 0x1AD]: c.wram[base + off] = rec[off]
        before = [self.rec(s) for s in range(6)]
        # model world: zero records + the same spec + the machine state, so that nothing but the specified fields can be read
        recs = []
        for s in range(6):
            m = bytearray(0x200)
            for off, v in spec[s].items(): m[off] = v
            recs.append(m)
        self.vm.write_state(recs[self.slot])
        mbefore = [bytes(m) for m in recs]
        w = ai_vm.World(ai_vm.Actor(m=recs[self.slot]), [ai_vm.Actor(m=recs[i]) for i in range(3)],
                        mons={s: ai_vm.Actor(m=recs[s]) for s in (3, 4, 5) if s != self.slot}, slot=self.slot)
        self.forced[:] = rng; self.rng_used = 0; self.engine = []
        self.env.call(0xC12552, X=0x200 * self.slot, m=1, x=0, long=False, DB=0x7E, max_steps=3000000)
        after = [self.rec(s) for s in range(6)]
        real = dict(cmd=list(after[self.slot][0x140:0x144]), pc=o.w(0x144), stack=[o.w(0x150 + 2 * i) for i in range(o.b(0x14F))],
                    var=[o.b(0x146) & 15, o.b(0x146) >> 4, o.b(0x147) & 15, o.b(0x147) >> 4], saved=(o.w(0x148), o.w(0x14A)), tgt=o.b(0x1AC), tgt2=o.b(0x1AD),
                    draws=self.rng_used)
        real_changed = {s: {off: after[s][off] for off in range(0x200) if after[s][off] != before[s][off]} for s in range(6)}
        try:
            cmd, _ = self.vm.step(w, rng)
        except ai_vm.VMError as e:
            self.k += 1
            return dict(k=self.k - 1, error=str(e), badref=isinstance(e, ai_vm.VMBadRef), injected=self.injected, ok=False, state_in=state_in, spec=spec)
        vm = self.vm
        model = dict(cmd=[v or 0 for v in cmd], pc=vm.pc, stack=list(vm.stack), var=list(vm.var), saved=vm.saved, tgt=vm.tgt, tgt2=vm.tgt2, draws=vm.draws,
                     effects=list(vm.effects))
        model_changed = {s: {off: recs[s][off] for off in range(0x200) if recs[s][off] != mbefore[s][off]} for s in range(6)}
        diffs = [key for key in ('cmd', 'pc', 'stack', 'var', 'saved', 'tgt', 'tgt2', 'draws') if real[key] != model[key]]
        ignore = set()
        if [e[0] for e in self.engine] != [{'cast_all': 'cast'}.get(e[0], e[0]) for e in model['effects'] if e[0] in ('cast', 'cast_all', 'flash')]: diffs.append(('engine calls', self.engine, model['effects']))
        elif any(e[1] != OBJ + 0x200 * self.slot for e in self.engine): diffs.append(('engine call object', self.engine))
        for s in range(6):
            for off in set(real_changed[s]) | set(model_changed[s]):
                if (s, off) in ignore: continue
                if real_changed[s].get(off) != model_changed[s].get(off): diffs.append(('rec', s, off, real_changed[s].get(off), model_changed[s].get(off)))
        self.k += 1
        self.state = dict(pc=real['pc'], stack=list(real['stack']), var=list(real['var']), saved=real['saved'], tgt=real['tgt'], tgt2=real['tgt2'],
                          mem=[o.w(0x150 + 2 * i) for i in range(16)])
        self.apply_state()          # on a mismatch the model continues from the state of the game
        return dict(k=self.k - 1, ok=not diffs, diffs=diffs, state_in=state_in, spec=spec, rng=rng[:max(real['draws'], model['draws'])], real=real, model=model,
                    real_changed=real_changed, model_changed=model_changed, rec_in={s: {o: v for o, v in enumerate(mbefore[s]) if v} for s in range(6)}, yielded=_, first=(real['cmd'][0], real['cmd'][1] if real['cmd'][0] == 0xC1 else None))


def compare(rom, state, mid, n, seed=1, slot=3, quiet=False):
    s = Session(rom, state, mid, seed, slot)
    bad = 0; first = collections.Counter(); done = 0; effects = collections.Counter(); errors = 0; skipped = 0
    for _ in range(n):
        r = s.step()
        if 'error' in r:
            if r['badref'] and r['injected']: skipped += 1
            else:
                errors += 1
                if errors <= 3: print('model error at step %d: %s' % (r['k'], r['error']))
                if errors <= 3: print('   state', r['state_in'])
            s.reset()          # restart the machine so that the run continues
            continue
        done += 1
        first[r['first']] += 1
        for e in r['model']['effects']: effects[e[0]] += 1
        if not r['ok']:
            bad += 1
            if bad <= 5 and not quiet:
                print('MISMATCH step %d' % r['k'], r['diffs'][:6])
                print('  state_in', r['state_in']); print('  real', r['real']); print('  model', r['model'])
    visited = s.visited | s.vm.visited
    branches = s.branches | s.vm.branches
    unseen = sorted((p, t) for p in s.cond for t in (True, False) if (p, t) not in branches)
    return done, bad, errors, first, visited, s.reach, effects, skipped, len(s.cond), unseen


def main():
    args = sys.argv[1:]
    opts = {}
    for k in ('--slot', '--seed'):
        if k in args:
            i = args.index(k); opts[k] = int(args[i + 1]); del args[i:i + 2]
    quiet = '--quiet' in args
    args = [a for a in args if not a.startswith('--')]
    rom = romio.load(args[0]); state = args[1]
    ids = parse_ids(args[2]) if len(args) > 2 else [0, 3, 0x0D]
    n = int(args[3]) if len(args) > 3 else 6000
    for mid in ids:
        done, bad, errors, first, visited, reach, effects, skipped, ncond, unseen = compare(rom, state, mid, n, opts.get('--seed', 1), opts.get('--slot', 3), quiet)
        reach = set(reach)
        print('id %d: %d AI steps compared, %d mismatches, %d model errors (+%d steps skipped: injected state dereferences an empty target)' % (mid, done, bad, errors, skipped))
        print('   script instructions executed by the model: %d of %d reachable (missing: %s)' % (len(visited & reach), len(reach), ' '.join('%04X' % p for p in sorted(reach - visited))))
        print('   conditional ops: %d, branch outcomes not seen: %s' % (ncond, ' '.join('%04X:%s' % (p, 'jump' if t else 'fall') for p, t in unseen) or 'none'))
        print('   effects:', dict(effects))
        print('   first command byte / animation of each step:', dict(sorted(first.items(), key=lambda kv: str(kv[0]))))
        sys.stdout.flush()


if __name__ == '__main__':
    main()
