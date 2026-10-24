"""Run a boss of the C2 boss engine (object ids 0x57-0x7F) in its own arena with the game's whole frame, and log what it does.
The party of a ZSNES save state (three heroes, any map, no event running) is sent through a map transition into the boss map with the game's
own loader (event_vm.World), so the boss is created by the map-object spawner exactly as in the game, on the real map (tiles, collisions).
Each frame is one call of the main-loop body $C0:B08C (the C2 engine runs for $56 = 0, 1, 2); PPU, DMA to VRAM and the sound CPU are not emulated.

usage: boss_fight.py ROM STATE BOSS_ID FRAMES [seed=N] [hero=X,Y[;X,Y;X,Y]] [ai=1] [hits=1] [mortal=1] [trans=N] [flag=IDX:VAL]
       prints one line per state start of the boss (frame, seconds, state, handler that chose it, mode, $AD/$2D, position, rows, sounds)
library: Fight(rom, state, boss, ...).run(frames) -> list of state records; .per_frame (one dict per frame); .hero_hits; .sounds; .spells; .spawns

Heroes: by default the three heroes are pinned at `hero` (one position for all, or one per hero; default: where the loader put them), their AI step
is skipped (`$C1:2552` for hero slots), their weapon hits on the boss are off (`$C2:052E` reports no contact) and their HP is refilled every frame
(a hit is still recorded with its damage). ai=1 lets the party AI run, hits=1 lets the heroes' weapons hit the boss, mortal=1 stops the refill."""
import sys, os, json, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import romio, event_vm, map_tables

HZ = 60.0988
OBJ0 = 0xE600                     # C2 engine slot 0 (the boss); slot k at OBJ0 + 0x200 * k
HERO = 0xE000
RECORDS = 0x10BC34                # $D0:BC34: pointers to the 15 native object records (bank C2)


def boss_map(rom, boss):
    """(map id, object record) of the first map whose object list contains the boss id."""
    t = map_tables.Tables(rom)
    for m in range(map_tables.N_MAPS - 1):
        try:
            if t.header(m) is None: continue
            for o in t.objects(m):
                if o['id'] == boss: return m, o
        except Exception:
            continue
    return None, None


def transition_to(rom, m):
    t = map_tables.Tables(rom)
    for n in range(0x400):
        if t.transition(n)['map'] == m: return n
    return None


def sext8(v): return v - 256 if v & 0x80 else v
def sext16(v): return v - 65536 if v & 0x8000 else v


class Fight(event_vm.World):
    def __init__(self, rom, state, boss, seed=None, hero=None, ai=False, hits=False, mortal=False, trans=None, flags=None, frame_log=True, hero_def=None):
        super().__init__(rom, state, seed=seed)
        c = self.c; w = c.wram
        self.boss = boss
        self.map, self.record = boss_map(rom, boss)
        self.trans = trans if trans is not None else transition_to(rom, self.map)
        self.set_leader(0)
        if flags is None and self.record is not None:
            flags = {self.record['flag']: self.record['flag_min']}          # the event flag the map object record needs (lowest allowed value)
        self.load_map(self.trans, flags)
        self.base = None
        for k in range(9):
            b = OBJ0 + 0x200 * k
            if w[b] and w[b + 0x180] == boss: self.base = b; break
        if self.base is None: raise RuntimeError('boss 0x%02X not spawned on map %d' % (boss, self.map))
        b = self.base
        self.h = dict(init=self.w16(b + 0xB4), chooser=self.w16(b + 0xB6), action=self.w16(b + 0xB8), hurt=self.w16(b + 0xBA))
        self.mortal = mortal
        self.hero_def = hero_def          # (evade, defense) forced on the three heroes every frame, e.g. (0, 0) to see the raw damage of the boss rows
        self.hit_events = []              # rising edges of a hero's hit mask obj+$59 (set by the contact test when a boss attack box overlaps the hero)
        self.last59 = [0, 0, 0]
        self.pins = None
        if hero is not None:
            self.pins = [hero[min(i, len(hero) - 1)] for i in range(3)]
        elif not ai:
            self.pins = [(self.w16(HERO + 0x200 * i + 2), self.w16(HERO + 0x200 * i + 4)) for i in range(3)]
        self.place_heroes()

        def rtl(cp): cp.PC = (cp.pull16() + 1) & 0xFFFF; cp.PB = cp.pull8(); return True
        def rts(cp): cp.PC = (cp.pull16() + 1) & 0xFFFF; return True
        if hits:
            c.hooks.pop(0xC2052E, None)          # lich_sim.Sim switches the heroes' weapon contact ($C2:052E, a JSR) off by default
        if not ai:
            c.hooks[0xC12552] = lambda cp: rts(cp) if cp.X < 0x600 else False
        self.force_pad = 0                 # joypad bits ORed into $4218/$4219 (e.g. 0x8000 = B: the leader swings its weapon)
        hr = c.hwread

        def hwread(o):
            v = hr(o)
            if o == 0x4218: v |= self.force_pad & 0xFF
            elif o == 0x4219: v |= self.force_pad >> 8
            return v
        c.hwread = hwread
        self.handler = None
        self.cur = None
        self.records = []
        self.rows = []
        self.spells = []
        self.spawns = []
        self.hero_hits = []
        self.per_frame = []
        self.frame_log = frame_log
        for name, a in self.h.items():
            if a and name != 'init':
                c.hooks[0xC20000 | a] = self._mk_handler(name)
        c.hooks[0xC2377A] = self._state_start
        c.hooks[0xC0006C] = self._row
        c.hooks[0xC2396D] = self._spell
        c.hooks[0xC233BE] = self._spawn
        self.phases = []                  # phase-machine bosses: (frame, slot, handler $8E, phase $94, animation $9A, x, y, active) at every change
        self._last_ph = {}
        self.f = 0
        self.last_hp = [self.w16(HERO + 0x200 * i + 0x182) for i in range(3)]

    # ---- hooks
    def _mk_handler(self, name):
        def h(cp):
            if cp.X == self.base: self.handler = name
            return False
        return h

    def _state_start(self, cp):
        if cp.X != self.base: return False
        st = cp.A & 0xFF
        if st == self.c.wram[self.base + 0x7A]: return False
        self._finish()
        b = self.base
        self.cur = dict(state=st, f0=self.f, kind=self.handler or 'script', mode=self.w16(b + 0x82), ad=self.w16(b + 0xAD), thr=self.w16(b + 0x2D),
                        x0=self.w16(b + 0x2B), y0=self.w16(b + 0x32), dir=self.c.wram[b + 0xAB], target=self.c.wram[b + 0xA9],
                        dist=self.manhattan(), rows=[], spells=[], spawns=[], sounds=[], hits=[])
        self.handler = None
        return False

    def _finish(self):
        if self.cur is None: return
        b = self.base
        self.cur['f1'] = self.f; self.cur['frames'] = self.f - self.cur['f0']
        self.cur['x1'] = self.w16(b + 0x2B); self.cur['y1'] = self.w16(b + 0x32)
        self.records.append(self.cur); self.cur = None

    def _row(self, cp):
        if cp.X == self.base and self.cur is not None: self.cur['rows'].append(cp.A & 0xFFFF)
        self.rows.append((self.f, cp.X, cp.A & 0xFFFF))
        return False

    def _spell(self, cp):
        e = (self.f, cp.X, cp.A & 0xFFFF)
        self.spells.append(e)
        if cp.X == self.base and self.cur is not None: self.cur['spells'].append(cp.A & 0xFFFF)
        return False

    def _spawn(self, cp):
        e = (self.f, cp.X, cp.A & 0xFFFF)
        self.spawns.append(e)
        if cp.X == self.base and self.cur is not None: self.cur['spawns'].append(e[2])
        return False

    def _snd(self, cp):
        w = cp.wram
        s = (self.f, w[0x1E00], w[0x1E01], w[0x1E02], w[0x1E03])
        self.events.append(dict(t=self.t, kind='sound', cmd=s[1], arg1=s[2], arg2=s[3], arg3=s[4]))
        if self.cur is not None: self.cur['sounds'].append(s)
        cp.PC = (cp.pull16() + 1) & 0xFFFF; cp.PB = cp.pull8(); return True

    # ---- helpers
    def last_row(self):
        for f, x, r in reversed(self.rows):
            if x == self.base: return r
        return None

    def manhattan(self):
        w = self.c.wram; b = self.base; t = w[b + 0xA9]
        hb = HERO + 0x200 * t
        return abs(self.w16(b + 0x2B) - self.w16(hb + 2)) + abs(self.w16(b + 0x32) - self.w16(hb + 4))

    def place_heroes(self):
        if not self.pins: return
        c = self.c
        for i, (x, y) in enumerate(self.pins):
            hb = HERO + 0x200 * i
            c.wr16(0x7E0000 + hb + 2, x); c.wr16(0x7E0000 + hb + 4, y)

    def b8(self, off, k=0): return self.c.wram[self.base + 0x200 * k + off]
    def b16(self, off, k=0): return self.w16(self.base + 0x200 * k + off)

    def box(self, off, k=0):
        w = self.c.wram; b = self.base + 0x200 * k + off
        return (sext8(w[b]), sext8(w[b + 1]), w[b + 2], w[b + 3])

    def frame(self):
        w = self.c.wram
        if self.hero_def is not None:
            for i in range(3):
                hb = HERO + 0x200 * i; w[hb + 0x1A4] = self.hero_def[0]; self.c.wr16(0x7E0000 + hb + 0x1A5, self.hero_def[1])
        if self.pins:
            self.place_heroes()
            for i in range(3):
                hb = HERO + 0x200 * i; w[hb + 6] = 0; w[hb + 7] = 0
        super().frame()
        self.f += 1
        for i in range(3):
            hb = HERO + 0x200 * i
            m59 = w[hb + 0x59]
            if m59 and not self.last59[i]:
                e = dict(f=self.f, hero=i, mask=m59, state=self.b8(0x7A), age=self.b16(0x96), row=self.last_row(), pending=self.w16(hb + 0x1F1))
                self.hit_events.append(e)
                if self.cur is not None: self.cur.setdefault('contacts', []).append(e)
            self.last59[i] = m59
            hp = self.w16(hb + 0x182)
            if hp < self.last_hp[i]:
                e = dict(f=self.f, hero=i, damage=self.last_hp[i] - hp, state=self.b8(0x7A), row=self.rows[-1][2] if self.rows else None, status=self.w16(hb + 0x1B0))
                self.hero_hits.append(e)
                if self.cur is not None: self.cur['hits'].append(e)
            if not self.mortal and hp < self.w16(hb + 0x184):
                self.c.wr16(0x7E0000 + hb + 0x182, self.w16(hb + 0x184)); hp = self.w16(hb + 0x184)
            self.last_hp[i] = hp
        for k in range(9):
            bb = OBJ0 + 0x200 * k
            key = (w[bb], self.w16(bb + 0x8E), self.w16(bb + 0x94), self.w16(bb + 0x9A), w[bb + 0x180]) if (w[bb] or self.w16(bb + 0x98)) else None
            if key != self._last_ph.get(k):
                self._last_ph[k] = key
                if key: self.phases.append((self.f, k, key[1], key[2], key[3], self.w16(bb + 0x2B), self.w16(bb + 0x32), key[0], key[4]))
                else: self.phases.append((self.f, k, None, None, None, None, None, 0, None))
        if self.frame_log:
            b = self.base
            slots = []
            for k in range(1, 9):
                bb = OBJ0 + 0x200 * k
                if w[bb] or self.w16(bb + 0x98):
                    slots.append(dict(slot=k, active=w[bb], id=w[bb + 0x180], kind=self.w16(bb + 0xB4), flags=self.w16(bb + 0x98), handler=self.w16(bb + 0x8E), ph=self.w16(bb + 0x94), x=self.w16(bb + 0x2B), y=self.w16(bb + 0x32),
                                      anim=self.w16(bb + 0x9A), atk=self.box_abs(bb + 0xC0), hurt=self.box_abs(bb + 0xC8), hurt2=self.box_abs(bb + 0xCC)))
            self.per_frame.append(dict(f=self.f, st=w[b + 0x7A], mode=self.w16(b + 0x82), ad=self.w16(b + 0xAD), age=self.w16(b + 0x96), x=self.w16(b + 0x2B), y=self.w16(b + 0x32),
                                       height=self.w16(b + 0x66), vz=sext16(self.w16(b + 0xC6)) * 256 + w[b + 0xC5], a45=w[b + 0x45], f10=w[b + 0x10], anim=self.w16(b + 0x9A), a9e=self.w16(b + 0x9E), f98=self.w16(b + 0x98), f60=w[b + 0x60], hp=self.w16(b + 0x182),
                                       atk=self.box(0xC0), hurt=self.box(0xC8), hurt2=self.box(0xCC), on=w[b], others=slots,
                                       heroes=[(self.w16(HERO + 0x200 * i + 2), self.w16(HERO + 0x200 * i + 4), w[HERO + 0x200 * i + 0x60]) for i in range(3)]))

    def box_abs(self, a):
        w = self.c.wram
        return (sext8(w[a]), sext8(w[a + 1]), w[a + 2], w[a + 3])

    def run(self, frames):
        for _ in range(frames): self.frame()
        self._finish()
        return self.records


def run_json(rom, state, boss, frames, seed, out=None, pos=None, move_every=0, floor=None, hero_def=(0, 0), frame_log=True, **kw):
    """One fight; the heroes are pinned at pos, or jump to a seed-dependent point of `floor` (list of (x, y)) every move_every frames.
    Writes a JSON file with state records, phase changes, per-frame log, contacts, hits, spells, spawns, rows and sounds."""
    import random
    rnd = random.Random(seed * 7919 + 13)
    f = Fight(rom, state, boss, seed=seed, hero=[pos] if pos else ([rnd.choice(floor)] if floor else None), hero_def=hero_def, frame_log=frame_log, **kw)
    for i in range(frames):
        if move_every and floor and i and i % move_every == 0:
            p = rnd.choice(floor); f.pins = [p, p, p]
        f.frame()
    f._finish()
    res = dict(boss=boss, map=f.map, seed=seed, frames=frames, pos=pos, move_every=move_every, hero_def=hero_def, records=f.records, phases=f.phases,
               per_frame=f.per_frame, hits=f.hero_hits, contacts=f.hit_events, spawns=f.spawns, spells=f.spells, rows=f.rows,
               sounds=[(e['t'] - f.t_scene, e['arg1'], e['cmd']) for e in f.events if e['kind'] == 'sound'])
    if out: json.dump(res, open(out, 'w'))
    return res


def parse(argv):
    o = dict(seed=None, hero=None, ai=False, hits=False, mortal=False, trans=None, flags={})
    rest = []
    for a in argv:
        if '=' not in a: rest.append(a); continue
        k, v = a.split('=', 1)
        if k == 'seed': o['seed'] = int(v, 0)
        elif k == 'hero': o['hero'] = [tuple(int(t, 0) for t in p.split(',')) for p in v.split(';')]
        elif k in ('ai', 'hits', 'mortal'): o[k] = v == '1'
        elif k == 'trans': o['trans'] = int(v, 0)
        elif k == 'flag':
            i, val = v.split(':'); o['flags'][int(i, 16)] = int(val, 0)
    return rest, o


def main():
    rom = romio.rom_from_argv()
    rest, o = parse(sys.argv[1:])
    state, boss, frames = rest[0], int(rest[1], 16), int(rest[2])
    f = Fight(rom, state, boss, seed=o['seed'], hero=o['hero'], ai=o['ai'], hits=o['hits'], mortal=o['mortal'], trans=o['trans'], flags=o['flags'] or None, frame_log=False)
    print('boss 0x%02X map %d transition %d slot base %04X handlers %s heroes %s' % (boss, f.map, f.trans, f.base, {k: '%04X' % v for k, v in f.h.items()}, f.pins))
    for r in f.run(frames):
        print('f=%6d t=%7.2fs st=%02X %-7s mode=%d ad=%3d thr=%2d dir=%d dist=%3d frames=%4d pos (%d,%d)->(%d,%d) rows=%s spells=%s spawns=%s sounds=%s hits=%s' % (
            r['f0'], r['f0'] / HZ, r['state'], r['kind'], r['mode'], r['ad'], r['thr'], r['dir'], r['dist'], r['frames'], r['x0'], r['y0'], r['x1'], r['y1'],
            ['%02X' % x for x in r['rows']], ['%04X' % x for x in r['spells']], r['spawns'], [(s[0] - r['f0'], s[1], s[2], s[3]) for s in r['sounds']],
            [(h['hero'], h['damage']) for h in r['hits']]))


if __name__ == '__main__':
    main()
