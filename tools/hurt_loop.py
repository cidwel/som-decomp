"""Hit reactions as played: what a hit does to a hero and to a monster in the real frame loop ($C0:B08C), measured on a ZSNES save state.
usage: hurt_loop.py ROM STATE [section ...]      sections: hero lump status lethal monster sounds cast regen (default: all)
The monster is a passive dummy made by the game's spawner (same recipe as glove_sim.GloveSim); a hit is the bit 0 of the hero's hit mask E059 (attacker slot 3),
which the combat tick resolves with the real routines.  Results are in docs/hit-reactions.md."""
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import glove_sim as gs, romio

def sim_for(rom, state, hp=None, defense=20):
    s = gs.GloveSim(rom, state, slot=0, row=0, level=1, mon=(40, 0))
    h = s.h
    h.sw(0x1A5, defense); h.sb(0x1A4, 0); h.sw(0x1AA, 0)
    if hp is not None: h.sw(0x182, hp)
    return s

def run(s, hits=(10,), frames=300, watch=None):
    h = s.h; ev = []; last = None
    for f in range(frames):
        if f in hits: h.sb(0x59, h.b(0x59) | 1)
        s.frame()
        key = (h.w(0x182), h.b(0x1C), h.w(0x190), h.b(0x191))
        if key != last:
            ev.append((f, h.w(0x182), h.b(0x1C), h.w(0x190) | h.b(0x191) << 8, h.w(0x1F1), h.b(0x11)))
            last = key
    return ev

def hero(rom, state):
    print('== hero, one hit at frame 10 (frame, hp, E01C, status, pending E1F1, E011)')
    for e in run(sim_for(rom, state)): print('  ', e)
    s = sim_for(rom, state); h = s.h; z = []; y = []; pics = []
    for f in range(130):
        if f == 10: h.sb(0x59, 1)
        s.frame(); z.append(h.b(0x45)); y.append(h.w(4)); pics.append(h.b(0x26))
    print('   z over the hurt (frames 14..40):', z[14:40])
    print('   picture changes:', [(i, p) for i, p in enumerate(pics) if i == 0 or p != pics[i - 1]])

def lump(rom, state):
    print('== hero, hits at 10, 30, 60, 90: later hits wait in E1F1 and land together when the reaction ends')
    for e in run(sim_for(rom, state), hits=(10, 30, 60, 90)): print('  ', e)

def status(rom, state):
    print('== hero with one status: hit at frame 10 (status, hp before -> after, E01C after, status after)')
    for st in (0x0004, 0x0010, 0x0020, 0x0040, 0x0080, 0x0100, 0x0200, 0x0400, 0x0800, 0x1000, 0x2000, 0x4000):
        s = sim_for(rom, state); h = s.h
        h.sw(0x190, st); h.sw(0x1EE, st); h.sw(0x19E, st)
        for off in (0x1B2, 0x1B3, 0x1B5, 0x1B6): h.sb(off, 200)
        hp0 = h.w(0x182)
        for f in range(60):
            if f == 10: h.sb(0x59, 1)
            s.frame()
        print('   %04X: %d -> %d, E01C %02X, status %04X' % (st, hp0, h.w(0x182), h.b(0x1C), h.w(0x190) | h.b(0x191) << 8))

def lethal(rom, state):
    print('== hero with 5 HP, hit at frame 10: dying countdown E1B4 (frame, hp, E01C, status, E1B4)')
    s = sim_for(rom, state, hp=5); h = s.h; last = None
    for f in range(200):
        if f == 10: h.sb(0x59, 1)
        try: s.frame()
        except RuntimeError: break
        key = (h.w(0x182), h.b(0x1C), h.w(0x190), h.b(0x1B4) // 8)
        if key != last:
            print('  ', (f, h.w(0x182), h.b(0x1C), h.w(0x190), h.b(0x1B4))); last = key

def monster(rom, state):
    print('== passive monster hit by repeated glove swings (every 25 frames): pending damage E1F1 piles up during the hurt state')
    s = gs.GloveSim(rom, state, slot=0, row=0, level=1, mon=(24, 0)); h, m = s.h, s.m
    h.sb(0x10, 2); last = None
    for f in range(260):
        s.frame(0x8000 if f in range(5, 400, 25) else 0)
        key = (m.w(0x182), m.w(0x1F1))
        if key != last:
            print('  ', (f, 'mhp', m.w(0x182), 'pending', m.w(0x1F1))); last = key

def sounds(rom, state):
    import combat_env as ce
    print('== hit sound E1AF: heroes', [hex(ce.Env(rom, state).obj(i).b(0x1AF)) for i in range(3)])
    d = {}
    for mid in range(0x57):
        e = ce.Env(rom, state); e.call(0xC055EC, A=mid, X=0x600, m=1, x=0); d[mid] = e.obj(3).b(0x1AF)
    print('   monsters:', ' '.join('%02X:%02X' % kv for kv in d.items()))
    s = sim_for(rom, state)
    for f in range(40):
        if f == 10: s.h.sb(0x59, 1)
        s.frame()
    print('   sounds requested by a hero hit (frame, id, param, pan):', [(e[0], hex(e[2]), e[3], e[4]) for e in s.events if e[1] == 'sound'])

def regen(rom, state):
    s = sim_for(rom, state, hp=100); h = s.h
    for f in range(3600): s.frame()
    print('== 3600 frames without a hit: HP 100 ->', h.w(0x182), '(no regeneration)')

SECTIONS = dict(hero=hero, lump=lump, status=status, lethal=lethal, monster=monster, sounds=sounds, regen=regen)
if __name__ == '__main__':
    rom = romio.rom_from_argv(); state = sys.argv[1]
    for name in (sys.argv[2:] or SECTIONS): SECTIONS[name](rom, state)
