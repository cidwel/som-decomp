"""Mantis Ant (boss id 0x57, record 0 at $C2:D080): model of its decisions and the measurements behind docs/mantis-ant.md and data/mantis_ant.json.
usage:
  mantis_ant.py ROM static                                   record, state sequences, state scripts, decision tables (no execution)
  mantis_ant.py ROM STATE verify [N] [SEED]                  chooser ($C2:3D5A) and action ($C2:3D8C) of the real code against the model, N random worlds
  mantis_ant.py ROM STATE run NAME X,Y FRAMES SEED [EVA,DEF] [OUT.json]
                                                             one fight on map 260 with the heroes pinned at X,Y (boss_fight.Fight), per-state records and per-frame log
  mantis_ant.py ROM STATE hurt OUT.json                      hit reactions: the hit flag injected in each state, and real hero weapon hits (party AI on)
  mantis_ant.py ROM STATE death OUT.json                     the death sequence after a lethal hit
  mantis_ant.py ROM timeline RUN.json ...                    state lengths of the runs against the tick model (predicted_ticks)
  mantis_ant.py ROM build OUT.json runs=A.json,B.json [verify=V.json] [hurt=H.json] [inject=I.json] [death=D.json] [rip=DIR] [ripdeath=DIR]
                                                             data/mantis_ant.json from the static decode, the run files and the rip directories
STATE: a ZSNES v143 save state with the three heroes on a map (the map-246 state of the other boss documents works): the party is sent into
map 260 through transition 141 and the game spawns the boss itself.
Model functions (no ROM needed): C2Rng, rand_n, dir8, dist_class, nearest_hero, choose, act."""
import sys, os, json, struct, random, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import romio, statescript

HZ = 60.0988
BOSS = 0x57
REC = 0xD080                       # record 0 in bank C2
DC = 0x1C0000                      # file offset of bank DC

# sequences (pointer -> state ids) and decision tables, as read by `static`
SEQ = {0xD09A: [0x00], 0xD09C: [0x03], 0xD09E: [0x00], 0xD0A0: [0x04], 0xD0A2: [0x05], 0xD0A4: [0x06], 0xD0A6: [0x0E, 0x0C, 0x0F], 0xD0AA: [0x0D],
       0xD0AC: [0x0E, 0x11, 0x0F], 0xD0B0: [0x0E, 0x12, 0x0F], 0xD0B4: [0x07], 0xD0B6: [0x0A], 0xD0B8: [0x0B], 0xD0BA: [0x07, 0x10], 0xD0BD: [0x08],
       0xD0BF: [0x13], 0xD0C1: [0x14], 0xD0C3: [0x15], 0xD0C5: [0x16], 0xD0C7: [0x17]}
WALK = [0xD0A2, 0xD0A2, 0xD0A4, 0xD0A0, 0xD0A0, 0xD0AC, 0xD0A6, 0xD0B0]      # $DC:E000 by direction code
CLOSE = [0xD0B6, 0xD0B6, 0xD0B4, 0xD0B8, 0xD0B8, 0xD0B4, 0xD0B4, 0xD0B4]     # $DC:E010 by direction code
DIRS = ['right', 'down-right', 'down', 'down-left', 'left', 'up-left', 'up', 'up-right']


# ------------------------------------------------------------------------------------------------ model
class C2Rng:
    """$C2:302C: 55-byte table at $0306, indexes $033D and $033E both advance (mod 55) before each draw; t[i0] ^= t[i1] is the result."""
    def __init__(self, table, i0, i1):
        self.t = list(table); self.i0 = i0; self.i1 = i1; self.n = 0

    def byte(self):
        self.i0 = (self.i0 + 1) % 55; self.i1 = (self.i1 + 1) % 55
        v = self.t[self.i0] ^ self.t[self.i1]; self.t[self.i0] = v; self.n += 1
        return v


def rand_n(rng, n):
    """$C2:300B with A = n: one byte r; n == 0 returns r, otherwise (r * (n + 1)) >> 8, a value 0..n."""
    r = rng.byte()
    return r if n == 0 else (r * (n + 1)) >> 8


def dir8(dx, dy):
    """$C2:2E50 (via $C2:0941): direction code from the boss to the target, dx = target x - boss x, dy = target y - boss y (16-bit words).
    0 right, 1 down-right, 2 down, 3 down-left, 4 left, 5 up-left, 6 up, 7 up-right."""
    dx &= 0xFFFF; dy &= 0xFFFF
    q = (2 if dy & 0x8000 else 0) + (1 if dx & 0x8000 else 0)
    if q >= 2: q ^= 1
    ax = (-dx) & 0xFFFF if dx & 0x8000 else dx
    ay = (-dy) & 0xFFFF if dy & 0x8000 else dy
    if (ay >> 1) >= ax: c = 0                  # mostly vertical
    elif (ax >> 1) < ay: c = 1                 # diagonal
    else: c = 2                                # mostly horizontal
    if not q & 1: c = 2 - c
    code = q * 2 + c
    return 0 if code == 8 else code


def dist_class(d):
    """$C2:08BC: Manhattan distance d -> (d >> 4) - 1 clamped to 0..4 (0: d < 32, 1: 32-47, 2: 48-63, 3: 64-79, 4: d >= 80)."""
    v = (d >> 4) - 1
    return 0 if v < 0 else 4 if v >= 4 else v


def manhattan(bx, by, hx, hy):
    return (abs(bx - hx) & 0xFFFF) + (abs(by - hy) & 0xFFFF)


def nearest_hero(bx, by, heroes):
    """$C2:3224: heroes = [(active, dead, x, y)] for slots 0-2; the first hero with the smallest Manhattan distance among the active (obj+0 == 1)
    and living (obj+$190 bit 15 clear) ones; 0 when none qualifies."""
    best, who = 0x7FFF, 0
    for i, (act, dead, x, y) in enumerate(heroes):
        if act != 1 or dead: continue
        d = (abs(bx - x) + abs(by - y)) & 0xFFFF
        if d < best: best, who = d, i
    return who


def choose(bx, by, heroes, rng):
    """Chooser $C2:3D5A (mode 1). Returns (sequence pointer, target slot, direction code)."""
    t = nearest_hero(bx, by, heroes); hx, hy = heroes[t][2], heroes[t][3]
    d = dir8(hx - bx, hy - by)
    if dist_class(manhattan(bx, by, hx, hy)) >= 2: return WALK[d], t, d
    if rand_n(rng, 2) != 0: return WALK[d], t, d
    return (0xD09E if rand_n(rng, 2) == 0 else 0xD0AA), t, d


def act(bx, by, heroes, rng):
    """Action routine of record 0, entry $C2:3D98 for obj+$42 = 0 (the Mantis Ant). Returns (sequence pointer or None = no action, target, direction)."""
    t = nearest_hero(bx, by, heroes); hx, hy = heroes[t][2], heroes[t][3]
    d = dir8(hx - bx, hy - by)
    if d == 6: return None, t, d
    k = dist_class(manhattan(bx, by, hx, hy))
    if k >= 4: return (0xD0BD if rand_n(rng, 2) == 0 else 0xD0BA), t, d
    if k == 3: return 0xD0BF, t, d
    return CLOSE[d], t, d


def p_rand2(v):
    """Probability that rand_n(2) returns v when the byte is uniform: 0 -> 86/256, 1 and 2 -> 85/256."""
    return (86 if v == 0 else 85) / 256.0


# ------------------------------------------------------------------------------------------------ static decode
def static(rom):
    u16 = lambda a: struct.unpack_from('<H', rom, 0x20000 + a)[0]
    rec = [u16(REC + 2 * i) for i in range(11)]
    out = dict(record_address='C2:%04X' % REC, flags='0x%04X' % rec[0], init='C2:%04X' % rec[2], chooser='C2:%04X' % rec[3], action='C2:%04X' % rec[4],
               hurt_handler=rec[5], first_sequence='C2:%04X' % rec[6], hurt_sequence='C2:%04X' % rec[7], state_table='C2:%04X' % rec[8])
    seqs = {}
    p = REC + 0x1A
    while p < rec[8]:
        s = []; a = p
        while rom[0x20000 + p] != 0xFF: s.append(rom[0x20000 + p]); p += 1
        p += 1; seqs['C2:%04X' % a] = s
    out['sequences'] = seqs
    states = {}
    for i in range(0x18):
        a = u16(rec[8] + 2 * i)
        states['%02X' % i] = dict(address='C2:%04X' % a, script=statescript.decode(rom, a).split('\n'))
    out['states'] = states
    tab = lambda a, n: [struct.unpack_from('<H', rom, DC + a + 2 * i)[0] for i in range(n)]
    out['tables'] = {'DC:E000 walk by direction': ['C2:%04X' % v for v in tab(0xE000, 8)], 'DC:E010 close attack by direction': ['C2:%04X' % v for v in tab(0xE010, 8)],
                     'DC:E028 projectile start velocity (x, y) by direction': [[sext(v) for v in tab(0xE028 + 4 * i, 2)] for i in range(8)],
                     'DC:E048 projectile homing velocity (x, y) by direction': [[sext(v) for v in tab(0xE048 + 4 * i, 2)] for i in range(8)]}
    return out


def sext(v): return v - 65536 if v & 0x8000 else v


# ------------------------------------------------------------------------------------------------ verification against the real routines
def verify(rom, state, n=20000, seed=1):
    import boss_fight
    f = boss_fight.Fight(rom, state, BOSS, seed=1, frame_log=False)
    for _ in range(20): f.frame()
    c = f.c; base = f.base
    regs = {}

    def grab(cp):
        if cp.X == base: regs.update(D=cp.D, DB=cp.DB)
        return False
    c.hooks[0xC23D5A] = grab
    while 'D' not in regs: f.frame()
    del c.hooks[0xC23D5A]
    snap = bytes(c.wram)
    rnd = random.Random(seed)
    stats = collections.Counter(); mism = []
    seen_ch = collections.Counter(); seen_ac = collections.Counter()

    def call(addr):
        c.M = 0; c.XF = 0; c.D = regs['D']; c.DB = regs['DB']; c.X = base; c.S = 0x1F00
        c.wr16(0x7E0000 + regs['D'] + 0x87, base)      # $87 (current object) lives in the engine's direct page ($0200)
        c.push16(0xFFFD); c.PB = addr >> 16; c.PC = addr & 0xFFFF
        k = 0
        while not (c.PB == addr >> 16 and c.PC == 0xFFFE):
            c.step(); k += 1
            if k > 200000: raise RuntimeError('timeout')
        return c.A & 0xFFFF, c.C

    for i in range(n):
        c.wram[:] = snap
        w = c.wram
        bx, by = rnd.randint(40, 440), rnd.randint(40, 440)
        if rnd.random() < 0.5:
            heroes = [(1, 0, bx + rnd.randint(-100, 100), by + rnd.randint(-100, 100)) for _ in range(3)]
        else:
            heroes = [(rnd.choice((0, 1, 1, 1)), rnd.random() < 0.2, rnd.randint(0, 480), rnd.randint(0, 480)) for _ in range(3)]
        c.wr16(0x7E0000 + base + 0x2B, bx); c.wr16(0x7E0000 + base + 0x32, by)
        for h, (a, dead, x, y) in enumerate(heroes):
            hb = 0xE000 + 0x200 * h
            w[hb] = a; c.wr16(0x7E0000 + hb + 2, x & 0xFFFF); c.wr16(0x7E0000 + hb + 4, y & 0xFFFF)
            w[hb + 0x191] = (w[hb + 0x191] | 0x80) if dead else (w[hb + 0x191] & 0x7F)
        for k in range(55): w[0x306 + k] = rnd.randrange(256)
        w[0x33D] = rnd.randrange(55); w[0x33E] = rnd.randrange(55)
        table, i0, i1 = bytes(w[0x306:0x306 + 55]), w[0x33D], w[0x33E]
        heroes_m = [(a, dead, x, y) for a, dead, x, y in heroes]
        which = 'chooser' if i % 2 == 0 else 'action'
        if which == 'chooser':
            a, _ = call(0xC23D5A)
            rng = C2Rng(table, i0, i1); m, t, d = choose(bx, by, heroes_m, rng)
            real = (a, w[base + 0xA9], w[base + 0xAB]); model = (m, t, d)
            seen_ch[SEQ[m][0] if len(SEQ[m]) == 1 else tuple(SEQ[m])] += 1
        else:
            a, carry = call(0xC23D8C)
            rng = C2Rng(table, i0, i1); m, t, d = act(bx, by, heroes_m, rng)
            real = (None if carry else a, w[base + 0xA9], w[base + 0xAB]); model = (m, t, d)
            seen_ac[('none' if m is None else tuple(SEQ[m]))] += 1
        rreal = (w[0x33D], w[0x33E], bytes(w[0x306:0x306 + 55]))
        rmod = (rng.i0, rng.i1, bytes(rng.t))
        ok = real == model and rreal == rmod
        stats[(which, ok)] += 1
        if not ok and len(mism) < 20: mism.append(dict(which=which, boss=(bx, by), heroes=heroes, real=str(real), model=str(model), rng_ok=rreal == rmod))
    res = dict(trials=n, calls={'%s %s' % (k[0], 'agree' if k[1] else 'differ'): v for k, v in sorted(stats.items())}, mismatches=mism,
               chooser_results={str(k): v for k, v in seen_ch.items()}, action_results={str(k): v for k, v in seen_ac.items()})
    return res


# ------------------------------------------------------------------------------------------------ fight runs
FLOOR = [(x, y) for x in range(120, 330, 10) for y in range(120, 330, 10)]   # points of the arena floor of map 260 used for the relocated heroes


def fight_run(rom, state, name, pos, frames, seed, hero_def=None, move_every=0, out=None):
    """One fight on map 260. pos = (x, y) for the three pinned heroes, or None with move_every > 0: the heroes jump to a seed-dependent floor point
    every move_every frames (every distance class and direction occurs)."""
    import boss_fight
    rnd = random.Random(seed * 7919 + 13)
    hero = [pos] if pos else [rnd.choice(FLOOR)]
    f = boss_fight.Fight(rom, state, BOSS, seed=seed, hero=hero, hero_def=hero_def)
    for i in range(frames):
        if move_every and i and i % move_every == 0:
            p = rnd.choice(FLOOR); f.pins = [p, p, p]
        f.frame()
    f._finish()
    res = dict(name=name, seed=seed, frames=frames, pos=pos, move_every=move_every, hero_def=hero_def, records=f.records, per_frame=f.per_frame,
               hits=f.hero_hits, contacts=f.hit_events, spawns=f.spawns, spells=f.spells, rows=f.rows,
               sounds=[(e['t'] - f.t_scene, e['arg1'], e['cmd']) for e in f.events if e['kind'] == 'sound'])
    if out: json.dump(res, open(out, 'w'))
    return res


def natural_fight(rom, state, seed, frames, refill=True, out=None, start_hp=None):
    """The leader (hero 0) stands below the boss facing up and presses B every 70 frames; weapon hits on; heroes immortal. refill: the boss HP is set back to its maximum when it drops
    below 60 so that the fight goes on (hurt statistics); refill=False runs until the boss is gone (death sequence)."""
    import boss_fight
    f = boss_fight.Fight(rom, state, BOSS, seed=seed, hero=[(400, 400)], hits=True)
    w = f.c.wram; b = f.base
    if start_hp: f.c.wr16(0x7E0000 + b + 0x182, start_hp)
    hp0 = f.w16(b + 0x184); dmg = []; last = f.w16(b + 0x182)
    exp0 = [w[0xE000 + 0x200 * i + 0x18D] | w[0xE000 + 0x200 * i + 0x18E] << 8 | w[0xE000 + 0x200 * i + 0x18F] << 16 for i in range(3)]
    snap0 = bytes(w)
    dead_at = gone_at = None; after = []
    for i in range(frames):
        bx, by = f.w16(b + 0x2B), f.w16(b + 0x32)
        f.pins = [(bx, by + 22), (40, 40), (40, 60)]          # the leader stands below the boss and swings (B) every 70 frames; the others stay away
        w[0xE010] = 0                                         # leader faces up
        w[0xE198] = 6; w[0xE1E6] = 0                          # leader attack 6 and no $CFFC bonus: a few HP per hit, like an early-game hero
        f.force_pad = 0x8000 if i % 70 == 0 else 0
        f.frame()
        hp = f.w16(b + 0x182)
        if hp < last: dmg.append(dict(f=f.f, damage=last - hp, state=w[b + 0x7A], mode=f.w16(b + 0x82)))
        last = hp
        if refill and hp < 60: f.c.wr16(0x7E0000 + b + 0x182, hp0); last = hp0
        if not refill:
            if dead_at is None and w[b + 0x191] & 0x80: dead_at = f.f
            if dead_at is not None and gone_at is None and w[b] == 0 and f.w16(b + 0x98) == 0: gone_at = f.f
            if gone_at is not None and f.f > gone_at + 600: break
    exp1 = [w[0xE000 + 0x200 * i + 0x18D] | w[0xE000 + 0x200 * i + 0x18E] << 8 | w[0xE000 + 0x200 * i + 0x18F] << 16 for i in range(3)]
    f._finish()
    diff = [(a, snap0[a], w[a]) for a in range(0xCC00, 0xD000) if snap0[a] != w[a]]
    res = dict(seed=seed, frames=f.f, records=f.records, boss_damage=dmg, per_frame=f.per_frame if not refill else None, dead_at=dead_at, gone_at=gone_at,
               exp_before=exp0, exp_after=exp1, wram_diff_CC00_D000=diff, contacts=f.hit_events, spells=f.spells, spawns=f.spawns,
               sounds=[(e['t'] - f.t_scene, e['arg1'], e['cmd']) for e in f.events if e['kind'] == 'sound'],
               vm=[dict(t=o['t'] - f.t_scene, addr=o['addr'], bank=o['bank'], op=o['op']) for o in f.vm_ops][:400],
               events_misc=[e for e in f.events if e['kind'] in ('misc', 'map_load')][-40:])
    if out: json.dump(res, open(out, 'w'))
    return res


def inject_hurt(rom, state, seed, out=None):
    """The hit flag (obj+$34 bit 0, what a party hit sets) injected once in the first tick of every state the boss enters within 3,000 frames,
    on a copy of the fight; logs what follows (state, mode, frames)."""
    import boss_fight, copy
    f = boss_fight.Fight(rom, state, BOSS, seed=seed, hero=[(264, 298)], frame_log=False)
    b = f.base; w = f.c.wram; res = []; done = set()
    for i in range(3000):
        f.frame()
        st = w[b + 0x7A]
        if st not in done and f.w16(b + 0x96) == 1 and f.f % 5 == 1:
            done.add(st)
            g = copy.deepcopy(f); g.c.wram[b + 0x34] |= 1; t0 = g.f; seq = []; last = None
            for _ in range(400):
                g.frame(); k = (g.c.wram[b + 0x7A], g.w16(b + 0x82))
                if k != last: seq.append((g.f - t0, '%02X' % k[0], k[1])); last = k
                if len(seq) >= 5: break
            res.append(dict(state='%02X' % st, mode=f.w16(b + 0x82), following=seq)); print(res[-1], flush=True)
    if out: json.dump(res, open(out, 'w'), indent=1)
    return res


# ------------------------------------------------------------------------------------------------ state length model
# full length in ticks of every state when nothing cuts it (DURATION14 + 1, or the animation / callback that ends it), measured
LENGTH = {0x00: 13, 0x04: 13, 0x05: 13, 0x06: 13, 0x07: 11, 0x08: 10, 0x0A: 10, 0x0B: 10, 0x0C: 13, 0x0D: 25, 0x0E: 6, 0x0F: 6, 0x10: 4, 0x11: 13, 0x12: 13, 0x13: 37, 0x03: 21}
MODE1 = {0x00, 0x04, 0x05, 0x06, 0x0D, 0x0E, 0x0C, 0x11, 0x12, 0x0F}


def predicted_ticks(st, ad, thr=47):
    """Ticks a state lasts when it starts with action counter `ad`: a mode-1 state (chooser states and the jump sequence) is cut when $AD reaches the
    threshold (C2:368F): min(length, thr - ad + 1); action states run their full length. The jump flight (0C, 11, 12) ends at landing, not by the cut."""
    L = LENGTH[st]
    if st in MODE1 and st not in (0x0C, 0x11, 0x12): return max(1, min(L, thr - ad + 1))
    return L


def check_timeline(paths):
    """Compare predicted_ticks with every measured state record. A state picked again by the chooser is not restarted (C2:377A) and shows up as one
    longer record: those are counted apart when their length is the first segment plus whole further segments."""
    res = collections.Counter(); bad = []
    for pth in paths:
        R = json.load(open(pth))['records']
        for k, r in enumerate(R[:-1]):
            st = r['state']
            if st not in LENGTH: continue
            if R[k + 1]['state'] == 0x03 and st != 0x03: res['cut by a party hit (next state 03)'] += 1; continue
            if st == 0x13 and r['frames'] == 190: res['13: 38 ticks instead of 37 (not explained)'] += 1; continue
            p = predicted_ticks(st, r['ad'], r['thr'] or 47) * 5; fr = r['frames']
            if st == 0x03: res['hurt (length set by the damage number)'] += fr == 105; continue
            if fr == p: res['exact'] += 1
            elif st in MODE1 and fr > p and fr % 5 == 0: res['longer: re-picked by the chooser (same state continues)'] += 1
            else:
                res['different'] += 1
                if len(bad) < 30: bad.append(dict(run=os.path.basename(pth), f0=r['f0'], state='%02X' % st, ad=r['ad'], frames=fr, predicted=p))
    return dict(counts=dict(res), differences=bad)


# ------------------------------------------------------------------------------------------------ data/mantis_ant.json
STATE_INFO = {
    0x00: ('idle', 'chooser (close) / first state at spawn'), 0x03: ('hurt', 'party hit in a mode-1 state'), 0x04: ('walk left', 'chooser: direction 3 or 4'),
    0x05: ('walk right', 'chooser: direction 0 or 1'), 0x06: ('walk down', 'chooser: direction 2'), 0x07: ('claw swing down (two swings)', 'action: close, direction 2, 5, 7; first state of the projectile attack'),
    0x08: ('cast Gem Missile (spell 1)', 'action: far, rand(2) = 0'), 0x0A: ('claw swing right', 'action: close, direction 0 or 1'), 0x0B: ('claw swing left', 'action: close, direction 3 or 4'),
    0x0C: ('jump up', 'second state of the jump sequence C2:D0A6 (direction 6)'), 0x0D: ('pose (stands, 25 ticks)', 'chooser (close)'), 0x0E: ('crouch before a jump', 'first state of a jump sequence'),
    0x0F: ('landing', 'last state of a jump sequence'), 0x10: ('throw the homing projectile', 'second state of C2:D0BA (action: far, rand(2) != 0)'),
    0x11: ('jump up-left', 'jump sequence C2:D0AC (direction 5)'), 0x12: ('jump up-right', 'jump sequence C2:D0B0 (direction 7)'),
    0x13: ('summon the effect object type 3', 'action: distance class 3 (64-79 px)'),
}


def summarize_runs(paths):
    dur = collections.defaultdict(collections.Counter); kind = collections.defaultdict(collections.Counter); trans = collections.defaultdict(collections.Counter)
    snd = collections.defaultdict(collections.Counter); con = collections.defaultdict(collections.Counter); mv = collections.defaultdict(collections.Counter)
    n_frames = 0; first_action = []
    for pth in paths:
        j = json.load(open(pth)); R = j['records']; n_frames += j.get('frames', 0) or (R[-1]['f1'] if R else 0)
        fa = [r['f0'] for r in R if r['kind'] == 'action']
        if fa: first_action.append(fa[0])
        for i, r in enumerate(R[:-1]):
            st = '%02X' % r['state']
            dur[st][r['frames']] += 1; kind[st][r['kind']] += 1; trans[st]['%02X' % R[i + 1]['state']] += 1
            for x in r['sounds']:
                if x[2] not in (79, 80, 36): snd[st]['%d:%d' % (x[0] - r['f0'], x[2])] += 1
            for c in r.get('contacts', []): con[st]['%d:hero%d:row%s' % (c['f'] - r['f0'], c['hero'], c['row'])] += 1
            if r['frames'] == 65 or r['state'] in (0x11, 0x12, 0x0C): mv[st]['%+d,%+d' % (r['x1'] - r['x0'], r['y1'] - r['y0'])] += 1
    out = {}
    for st in sorted(dur):
        out[st] = dict(entries=sum(dur[st].values()), chosen_by=dict(kind[st]), frames=dict(sorted(dur[st].items())), next_state=dict(trans[st].most_common()),
                       boss_sounds_frame_id=dict(snd[st].most_common()), hero_contacts_frame_hero_row=dict(con[st].most_common()),
                       displacement=dict(mv[st].most_common(8)))
    return dict(runs=[os.path.basename(p) for p in paths], frames=n_frames, first_action_frame=first_action, states=out)


def rip_summary(ripdir):
    out = {}
    if not ripdir or not os.path.isdir(ripdir): return out
    for fn in sorted(os.listdir(ripdir)):
        if not fn.endswith('.json') or fn == 'index.json': continue
        d = json.load(open(os.path.join(ripdir, fn))); pf = d['per_frame']; b = d['boss'] or {}
        steps = []
        for i in range(d['frames']):
            k = (pf['state'][i], pf['anim'][i], (b.get('per_frame_picture') or [None] * d['frames'])[i], tuple(pf['attack_box'][i]), tuple(pf['hurt_box'][i]), tuple(pf['hurt_box2'][i]))
            if steps and steps[-1]['k'] == k: steps[-1]['frames'] += 1
            else: steps.append(dict(k=k, start=i, frames=1))
        tl = [dict(start_frame=s['start'], frames=s['frames'], state='%02X' % s['k'][0], anim='%02X' % s['k'][1], picture=s['k'][2], attack_box=list(s['k'][3]),
                   hurt_box=list(s['k'][4]), hurt_box2=list(s['k'][5])) for s in steps]
        x0, y0 = pf['x'][0], pf['y'][0]
        out[fn[:-5]] = dict(sequence=d.get('sequence', d.get('kind')), frames=d['frames'], seconds=d['seconds'], pictures=len(b.get('pictures', [])), png_size=b.get('png_size'),
                            origin=b.get('origin'), other_objects={k: len(v['pictures']) for k, v in d['other_objects'].items()}, timeline=tl,
                            displacement_per_frame=[[x - x0, y - y0] for x, y in zip(pf['x'], pf['y'])], height_per_frame=pf['height'],
                            sounds=[[i, s[0]] for i, ss in enumerate(pf['sounds']) for s in ss if s[0] not in (79, 80, 36)])
    return out


def build(rom, out, runs, verify_path=None, hurt_path=None, inject_path=None, death_path=None, ripdir=None, deathdir=None, sheet_path=None):
    st = static(rom)
    mon = json.load(open(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', 'data', 'monsters.json')))['records'][BOSS]
    pr = lambda v: round(v, 4)
    p0 = 86 / 256.0
    d = dict(source='tools/mantis_ant.py build (static decode of record 0 at C2:D080 and its tables, runs of the real game frame on map 260 via tools/boss_fight.py, rips via tools/rip_boss.py)',
             boss_id=BOSS, map=260, spawn=dict(map_object_record='map 260 object 0: tile (13, 14), flag 0x10 range 0-15, event word 0x4112', position=[208, 224], transition_into_map=141,
                                                loader_scripts=['C1:61CB', 'C1:61D3'], record_index=0, shared_with='boss id 0x63 (the action routine branches on obj+$42)'),
             time_base=dict(ticks_per_second=round(60.0988 / 5, 4), frames_per_tick=5, rule='flags 0x1C11: high byte & 3 == 0 -> the boss runs when $56 == 0 (one frame in five)',
                            action_threshold_ticks=47, threshold_rule='(100 - Agi) // 2 with Agi 5'),
             stats=mon, record=st)
    rows = json.load(open(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', 'data', 'boss_attacks.json')))
    rr = rows['rows']
    d['attack_rows'] = {str(i): rr[i] for i in (3, 68, 99) if i < len(rr)}
    d['chooser_model'] = dict(
        rule='target = first living active hero with the smallest |dx|+|dy| (C2:3224); dir = 8-direction code (C2:2E50); k = distance class (C2:08BC). '
             'k >= 2: walk table by dir. k < 2: rand(2) != 0 -> walk table; else rand(2) == 0 -> idle 00 (D09E), else pose 0D (D0AA). rand(n) = (r * (n + 1)) >> 8 with r one byte of the C2 RNG.',
        walk_table_by_direction={DIRS[i]: [('%02X' % x) for x in SEQ[WALK[i]]] for i in range(8)},
        close_probabilities=dict(walk=pr(170 / 256.0), idle_00=pr(p0 * p0), pose_0D=pr(p0 * 170 / 256.0)),
        direction_codes=DIRS, distance_classes=['d < 32', '32 <= d < 48', '48 <= d < 64', '64 <= d < 80', 'd >= 80'])
    d['action_model'] = dict(
        rule='runs when the action counter $AD reaches 47 at the end of a state (or cuts a mode-1 state). dir 6 (target straight above): no action, the chooser runs instead (a jump up). '
             'k >= 4: rand(2) == 0 -> 08 (Gem Missile) else 07 + 10 (swing, homing projectile); k == 3: 13 (effect object type 3); k < 3: claw table by dir.',
        close_table_by_direction={DIRS[i]: [('%02X' % x) for x in SEQ[CLOSE[i]]] for i in range(8)},
        far_probabilities=dict(spell_08=pr(p0), projectile_07_10=pr(1 - p0)))
    if verify_path: d['model_check'] = json.load(open(verify_path))
    d['measured'] = summarize_runs(runs)
    if hurt_path:
        h = json.load(open(hurt_path)); R = h['records']
        hd = collections.Counter(); after = collections.Counter(); before = collections.Counter()
        for i, r in enumerate(R[:-1]):
            if r['state'] == 3: hd[r['frames']] += 1; after['%02X' % R[i + 1]['state']] += 1; before['%02X' % R[i - 1]['state']] += 1
        d['hurt'] = dict(run=os.path.basename(hurt_path), boss_hits=len(h['boss_damage']), hurt_frames=dict(hd), state_before=dict(before), state_after=dict(after),
                         damage_values=dict(collections.Counter(x['damage'] for x in h['boss_damage'])))
        near = collections.Counter()
        for x in h['boss_damage']:
            for t, i, c in h['sounds']:
                if -2 <= t - x['f'] <= 2 and i != 0x24: near['%d:0x%02X' % (t - x['f'], i)] += 1
        d['hurt']['sounds_at_the_damage_frame'] = dict(near)
        d['hurt']['note'] = 'sound 0x94 (= obj+$1AF of the boss, its hit sound) is requested in the frame the pending damage is applied; 0x24 is the hero swing'
    if inject_path: d['hurt_injection'] = json.load(open(inject_path))
    if death_path:
        j = json.load(open(death_path)); da = j['dead_at']
        d['death'] = dict(run=os.path.basename(death_path), hp_zero_frame=da, exp_gain=[b - a for a, b in zip(j['exp_before'], j['exp_after'])],
                          wram_changes_CC00_D000=[['%04X' % a, b, c] for a, b, c in j['wram_diff_CC00_D000']],
                          sounds_after_hp_zero=[[t - da, i, c] for t, i, c in j['sounds'] if da is not None and t >= da],
                          event_vm_first_step=(j['vm'][0]['t'] - da) if j['vm'] and da is not None else None,
                          vm_steps=[[v['t'] - da, '%02X:%04X' % (v['bank'], v['addr']), v['op']] for v in j['vm'][:60]] if da is not None else [])
    d['rips'] = rip_summary(ripdir)
    if deathdir: d['rips'].update(rip_summary(deathdir))
    json.dump(d, open(out, 'w'), indent=1)
    open(out, 'a').write('\n')
    return d


# ------------------------------------------------------------------------------------------------ cli
def main():
    rom = romio.rom_from_argv()
    a = sys.argv[1:]
    if a[0] == 'timeline':
        print(json.dumps(check_timeline(a[1:]), indent=1)); return
    if a[0] == 'build':
        kv = dict(x.split('=', 1) for x in a[2:] if '=' in x)
        build(rom, a[1], kv['runs'].split(','), kv.get('verify'), kv.get('hurt'), kv.get('inject'), kv.get('death'), kv.get('rip'), kv.get('ripdeath'))
        return
    if a[0] == 'static':
        print(json.dumps(static(rom), indent=1)); return
    state, cmd = a[0], a[1]
    if cmd == 'verify':
        n = int(a[2]) if len(a) > 2 else 20000; sd = int(a[3]) if len(a) > 3 else 1
        r = verify(rom, state, n, sd)
        print(json.dumps(r, indent=1))
        if len(a) > 4: json.dump(r, open(a[4], 'w'), indent=1)
    elif cmd == 'natural':
        r = natural_fight(rom, state, int(a[2]), int(a[3]), a[4] == 'refill', a[5], int(a[4][4:]) if a[4].startswith('kill') and a[4][4:] else None)
        print('frames', r['frames'], 'dead', r['dead_at'], 'gone', r['gone_at'], 'hits on boss', len(r['boss_damage']))
    elif cmd == 'inject':
        inject_hurt(rom, state, int(a[2]), a[3])
    elif cmd == 'run':
        name, pos, frames, sd = a[2], a[3], int(a[4]), int(a[5])
        hd = tuple(int(v) for v in a[6].split(',')) if len(a) > 6 and a[6] != '-' else None
        out = a[7] if len(a) > 7 else None
        mv = 0; p = None
        if pos.startswith('move'): mv = int(pos[4:])
        else: p = tuple(int(v) for v in pos.split(','))
        r = fight_run(rom, state, name, p, frames, sd, hd, mv, out)
        print(name, 'states', len(r['records']), 'contacts', len(r['contacts']))


if __name__ == '__main__':
    main()
