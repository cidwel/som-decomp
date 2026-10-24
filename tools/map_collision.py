"""Tile collision of the real hero movement routine on a loaded map: what blocks a hero, and the shape of the diagonal tiles.
usage: map_collision.py ROM STATE grid MAP        walk a hero from every tile centre 2 px right/left/down/up with the real `$C0:D5C0` and compare with the attribute rule
                                                  (solid = b0 & 7 == 3, diagonal shapes from b2): prints the counts per attribute class
       map_collision.py ROM STATE shape B0 B2     single tile with attribute (B0, 0, B2, 0) on flat floor: ASCII map of the hero positions (2 px grid) from which a 1 px step
                                                  right (left grid) or up (right grid) is refused
       map_collision.py ROM STATE heights           floor heights: hero E00B & 3 against tile types 0-3 (crossing and the new E00B)
STATE: a ZSNES v143 state with the party (the routine needs a hero object). Documented in docs/maps.md section 7."""
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import romio, map_env

ATTR = 0x10000 + 0xB800


class Rig:
    def __init__(self, rom, state, map_id):
        self.env = map_env.MapEnv(rom, state)
        self.d = self.env.load(map_id)
        c = self.env.c
        self.w = w = c.wram
        for k in range(1, 12): w[0xE000 + 0x200 * k] = 0
        w[0xE000 + 0x2C] = 1
        c.hooks[0xC0D6C8] = lambda cp: (setattr(cp, 'PC', (cp.pull16() + 1) & 0xFFFF), True)[1]      # party window off
        for a in (0xF1, 0xFF, 0xD0, 0x52, 0xE2, 0xE8, 0x4E): w[a] = 0
        w[0xE000 + 0x1C] = 0
        w[0xD9] = 1; w[0xDA] = 0; w[0xDB] = 0

    def step(self, x, y, vx, vy):
        w = self.w; B = 0xE000
        w[B + 2] = x & 255; w[B + 3] = x >> 8; w[B + 4] = y & 255; w[B + 5] = y >> 8
        w[B + 6] = (abs(vx) & 0x7F) | (0x80 if vx < 0 else 0); w[B + 7] = (abs(vy) & 0x7F) | (0x80 if vy < 0 else 0)
        self.env.callrts(0xC0D5C0)
        return (w[B + 2] | w[B + 3] << 8, w[B + 4] | w[B + 5] << 8) != (x, y)


def grid(rom, state, m):
    from collections import Counter
    r = Rig(rom, state, m)
    d = r.d
    cnt = Counter()
    for ty in range(2, d['height'] - 2):
        for tx in range(2, d['width'] - 2):
            tid = d['layer1'][ty][tx]
            b0, b2 = d['attr1'][4 * tid], d['attr1'][4 * tid + 2]
            res = []
            for vx, vy in ((-2, 0), (0, 2), (0, -2)):           # these probe the tile under the hero (leading edge inside the own tile)
                res.append(r.step(tx * 16 + 8, ty * 16 + 8, vx, vy))
            cls = 'solid(b0&7==3)' if b0 & 7 == 3 else 'diagonal b2=%02x' % b2 if (b2 >> 4) == 1 and (b2 & 7) >= 4 else 'type%d' % (b0 & 7)
            cnt[(cls, tuple(int(not v) for v in res))] += 1      # 1 = blocked
    for k, v in sorted(cnt.items()): print(k, v)


def shape(rom, state, b0, b2):
    r = Rig(rom, state, 130)
    w = r.w
    T = (20, 20)
    for ty in range(T[1] - 4, T[1] + 5):
        for tx in range(T[0] - 4, T[0] + 5): w[0x10000 + ty * 128 + tx] = 0
    w[ATTR:ATTR + 4] = bytes((0x12, 0, 0, 0)); w[ATTR + 4 * 250:ATTR + 4 * 250 + 4] = bytes((b0, 0, b2, 0))
    w[0x10000 + T[1] * 128 + T[0]] = 250
    rng = range(-24, 40, 2)
    res = {}
    for dy in rng:
        for dx in rng:
            x, y = T[0] * 16 + dx, T[1] * 16 + dy
            res[(dx, dy)] = (r.step(x, y, 1, 0), r.step(x, y, 0, -1))
    for dy in rng:
        print(''.join('.' if res[(dx, dy)][0] else '#' for dx in rng), '  ', ''.join('.' if res[(dx, dy)][1] else '#' for dx in rng))


def heights(rom, state):
    """Hero height bits E00B & 3 against floor types b0 & 7 = 0, 1, 2: walk right from a type-F tile into a type-T tile (2 px steps) and report whether
    the hero crosses, and E00B after standing on each type."""
    r = Rig(rom, state, 130)
    w = r.w; B = 0xE000
    T = (20, 20)
    for ty in range(T[1] - 4, T[1] + 5):
        for tx in range(T[0] - 4, T[0] + 5): w[0x10000 + ty * 128 + tx] = 0
    print('E00B&3 on tile type F, walking into type T (1 = crossed)')
    for f in (0, 1, 2):
        for t in (0, 1, 2, 3):
            w[ATTR:ATTR + 4] = bytes((f, 0, 0, 0)); w[ATTR + 4 * 250:ATTR + 4 * 250 + 4] = bytes((t, 0, 0, 0))
            w[0x10000 + T[1] * 128 + T[0] + 1] = 250
            row = []
            for h in range(4):
                w[B + 0x0B] = (w[B + 0x0B] & ~3) | h
                x, y = T[0] * 16 + 4, T[1] * 16 + 8
                for _ in range(16):
                    r.step(x, y, 2, 0)
                    x = w[B + 2] | w[B + 3] << 8
                row.append('h%d:%d->%d' % (h, int(x >= (T[0] + 1) * 16 + 2), w[B + 0x0B] & 3))
            print('F=%d T=%d  %s' % (f, t, '  '.join(row)))


if __name__ == '__main__':
    rom = romio.rom_from_argv()
    state = sys.argv[1]
    if sys.argv[2] == 'grid': grid(rom, state, int(sys.argv[3]))
    elif sys.argv[2] == 'heights': heights(rom, state)
    elif sys.argv[2] == 'shape': shape(rom, state, int(sys.argv[3], 0), int(sys.argv[4], 0))
    else: sys.exit(__doc__)
