"""Render a map dump (map_env.py) to PNG: BG2 priority 0, BG1 priority 0, BG2 priority 1, BG1 priority 1, colour 0 of each palette transparent, backdrop = palette entry 0.
usage: map_render.py DUMP.json OUT.png [layer1|layer2|both] [grid]
library: render(dump, which='both') -> gfx_decode.Image"""
import sys, os, json, base64
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import gfx_decode as G


def palette(dump):
    p = dump['palette']
    return [G.bgr555(p[2 * i] | p[2 * i + 1] << 8) for i in range(256)]


def char_cache(vram):
    cache = {}
    def get(n):
        t = cache.get(n)
        if t is None:
            t = cache[n] = G.decode_tile(vram, n * 32)
        return t
    return get


def render(dump, which='both', priorities=True):
    vram = base64.b64decode(dump['vram'])
    pal = palette(dump)
    ch = char_cache(vram)
    W, H = dump['width'], dump['height']
    img = G.Image(W * 16, H * 16)
    for y in range(img.h):
        for x in range(img.w): img.put(x, y, pal[0])
    layers = []
    if which in ('both', 'layer2') and dump['layer2']: layers.append((dump['layer2'], dump['tiledef2'], 0))
    if which in ('both', 'layer1'): layers.append((dump['layer1'], dump['tiledef1'], 0))
    passes = []
    for prio in (0, 1):
        for rows, td, _ in layers: passes.append((rows, td, prio))
    for rows, td, prio in passes:
        for ty, row in enumerate(rows):
            for tx, tid in enumerate(row):
                for k in range(4):
                    e = td[tid * 8 + 2 * k] | td[tid * 8 + 2 * k + 1] << 8
                    if ((e >> 13) & 1) != prio: continue
                    t = ch(e & 0x3FF)
                    pl = (e >> 10) & 7
                    ox, oy = tx * 16 + (k & 1) * 8, ty * 16 + (k >> 1) * 8
                    for yy in range(8):
                        sy = 7 - yy if e & 0x8000 else yy
                        for xx in range(8):
                            ci = t[sy][7 - xx if e & 0x4000 else xx]
                            if ci: img.put(ox + xx, oy + yy, pal[pl * 16 + ci])
    return img


def main():
    dump = json.load(open(sys.argv[1]))
    which = sys.argv[3] if len(sys.argv) > 3 else 'both'
    img = render(dump, which)
    G.write_png(sys.argv[2], img)


if __name__ == '__main__':
    main()
