#!/usr/bin/env python3
"""Ending 'The End' screen: which moon is drawn and why (docs/ending-moon-20261018.md).

usage: ending_moon.py ROM CORE FIELD_STATE OUTDIR [--random N]

Runs the real ROM in the snes9x libretro core: starts event 0x4FD from any in-field state, runs the
whole ending to the software restart, then reads the shadow OAM of the "The End" scene.  The model
`predict` re-implements the seed ring ($7E:C2D9), the ring advance ($C25B) and the bounded draw
($C288) of the original boot program and the draw sequence of the scene constructors; the script
compares it with the emulator for the given SRAM words.  Nothing from the ROM is stored.
"""
import pathlib, random, sys
sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent / 'companion'))
import retro

MOONS = {(27, 27, 27, 27): 'T0 full', (27, 40, 41, 42): 'T1 gibbous', (43, 43, 44, 45): 'T2 crescent'}


def seed_ring(x):
    s = 0x7524 if x == 0 else x
    while True:
        ring = []
        while len(ring) < 15:
            while True:
                b = s & 0x4001
                s = s >> 1 if b in (0, 0x4001) else (s | 0x8000) >> 1
                if s & 1:
                    break
            ring.append((s >> 1) & 0xFF)
        acc = 0
        for r in ring:
            acc |= r
        if acc == 0xFF:
            return ring


class Rng:
    def __init__(self, x):
        self.r, self.i = seed_ring(x), 0

    def adv(self):
        y = self.i
        self.i = i = 0 if y + 1 >= 15 else y + 1
        self.r[i] = v = (self.r[y] - self.r[i]) & 0xFF
        return v

    def draw(self, limit):
        limit = (limit & 0xFF) or 256
        if limit == 1:
            return 0
        mask = (1 << (limit - 1).bit_length()) - 1
        while True:
            v = self.adv() & mask
            if v < limit:
                return v


def predict(seed):
    """Template index 0..2 chosen by the scene for XOR of the four slot checksum words = seed."""
    g = Rng(seed)
    for _ in range(16):
        g.draw(0), g.draw(0x68), g.draw(4)
    return g.draw(3)


def moon_template(core):
    base = core.u16(0x10000 + 0x2CC)
    o = core.read(0x10000 + base, 544)
    tiles = []
    for i in range(128):
        x, y, t, a = o[i * 4:i * 4 + 4]
        h = (o[512 + i // 4] >> ((i % 4) * 2)) & 3
        if (a >> 4) & 3 == 3 and (a >> 1) & 7 == 0 and 70 <= y <= 96 and 190 <= (x | (h & 1) << 8) <= 216:
            tiles.append(t | (a & 1) << 8)
    return MOONS.get(tuple(sorted(t for t in tiles if t in (27, 40, 41, 42, 43, 44, 45))), 'unknown %s' % tiles)


def main():
    rom, core_path, field, out = sys.argv[1:5]
    n_random = int(sys.argv[sys.argv.index('--random') + 1]) if '--random' in sys.argv else 20
    out = pathlib.Path(out)
    out.mkdir(parents=True, exist_ok=True)
    c = retro.Core(rom, core_path)
    c.load_state(pathlib.Path(field).read_bytes())
    c.run(30)
    c.write(0xD1, bytes([0x95, 0x4D, 0xCA]))
    c.write(0xD0, b'\x01')
    c.run(25400)                           # map 107, just before the restart
    late = c.save_state()
    sram = c.lib.retro_get_memory_data(0)

    def run(words, name=None):
        c.load_state(late)
        for i, w in enumerate(words):
            sram[i * 0x400 + 1], sram[i * 0x400 + 2] = w & 255, w >> 8
        c.run(1300)
        if name:
            c.save_ppm(str(out / name))
        return moon_template(c)

    print('baseline SRAM', run([0x6060] * 4, 'baseline.ppm'))
    rnd = random.Random(1)
    bad = 0
    for k in range(n_random):
        w = [rnd.getrandbits(16) for _ in range(4)]
        got, want = run(w), 'T%d' % predict(w[0] ^ w[1] ^ w[2] ^ w[3])
        bad += not got.startswith(want)
        print([hex(x) for x in w], got, 'predicted', want)
    print('mismatches', bad, 'of', n_random)


if __name__ == '__main__':
    main()
