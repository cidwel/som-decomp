"""Native (no 65816 emulation) decoder of the Secret of Mana (USA) map tile layers, written from the disassembly of the map loader `$C0:CB90-D036`.
usage: map_native.py ROM verify [MAP ...] [--no-boss]   (--no-boss: the boss spawner $C2:0040 does nothing during the load) decode layers, graphics, palette, attributes and tile words with this module and with the real loader (map_env.py) and compare (default: every map)
       map_native.py ROM size                       size in tiles of every map that has a header (first piece of the list)
library: decode_layers(rom, map_id, flags={}) -> dict(width, height, layer1, layer2, origin1, origin2)   decode_gfx(rom, set)   decode_palette(rom, header)   decode_attributes(rom, header)   decode_tile_words(rom, header)
Tilemap words of the 16x16 tiles use the original bit-field delta coder model in map_tile_words.py; marker tile clones are created by the loader (apply_markers).

Piece lists: `$C8:5000 + 2*map` -> list of 5-byte records, the first record of each layer preceded by 0xFE (layer 1) or 0xFF (layer 2). Record: flag index, flag range
(min << 4 | max), piece id low byte, x*2 + piece id bit 8, y*2 + piece id bit 9 (x, y in tiles, 128 tiles per row in the 64 KiB buffer, layer 2 at +0x4000).
A piece is stored in banks $CC-$CF (pointer table `$CD:0004 + 2*id`, bank by the thresholds `$CD:0000/0002/0004`); its body is a byte stream (section 5 of docs/maps.md)."""
import sys, os, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import romio

B = lambda bank, off: ((bank & 0x3F) << 16) + off


class Pieces:
    def __init__(self, rom):
        self.rom = rom
        self.w = lambda bank, off: struct.unpack_from('<H', rom, B(bank, off))[0]

    def locate(self, pid):
        t0, t1, t2 = (self.w(0xCD, 0), self.w(0xCD, 2), self.w(0xCD, 4))
        bank = 0xCD if pid < t0 else 0xCE if pid < t1 else 0xCF if pid < t2 else 0xCC
        return bank, self.w(0xCD, 4 + 2 * pid)


def draw(rom, bank, ptr, mem, dest, w, h):
    """Decode a piece into mem (128 bytes per row); return the end of its encoded body. Mirrors `$C0:CD93`."""
    pos = [ptr]

    def nxt():
        v = rom[B(bank, pos[0])]
        pos[0] += 1
        return v

    d0 = rom[B(bank, ptr)]
    d1 = rom[B(bank, ptr + 1)]
    pos[0] = ptr + 2
    subs = []
    if (d0 & 1) or (d1 & 1):
        while True:
            dims = nxt()
            subs.append((dims, bank, pos[0]))
            while True:
                v = nxt()
                if v >= 0xF8: break
            if v == 0xFF: break
    pending = []
    base = dest
    run_body(rom, bank, pos, mem, base, w, h, subs, pending)
    for idx, at in pending:
        dims, sb, sp = subs[idx]
        sw, sh = (dims & 15) + 1, (dims >> 4) + 1
        p2 = [sp]
        run_body(rom, sb, p2, mem, at, sw, sh, subs, [], sub=True)
    return pos[0]


def run_body(rom, bank, pos, mem, base, w, h, subs, pending, sub=False):
    row, col = 0, 0

    def nxt():
        v = rom[B(bank, pos[0])]
        pos[0] += 1
        return v

    def cell(r, c): return base + r * 128 + c

    def put(v):
        nonlocal row, col
        mem[cell(row, col)] = v & 0xFF
        advance()

    def advance(n=1):
        nonlocal row, col
        col += n
        while col >= w:
            col -= w
            row += 1
        return row >= h

    def idx_back(k):
        r, c = row, col - k
        while c < 0:
            c += w
            r -= 1
        return r, c

    while row < h:
        a = nxt()
        if a < 0xC0:
            put(a)
        elif a < 0xE0:
            n = ((a >> 3) & 3) + 1
            r, c = idx_back(n)
            v = mem[cell(r, c)]
            for _ in range(( a & 7) + 1):
                if row >= h: break
                put(v)
        elif a < 0xF0 and a != 0xE0:
            if a < 0xE8:
                cnt = (a & 7) + 1
                up = 1
            else:
                b = nxt()
                k = ((a & 7) * 2 + (b >> 7)) + 1
                cnt = (b & 0x7F) + 1
                for _ in range(cnt):
                    if row >= h: break
                    r, c = idx_back(k)
                    put(mem[cell(r, c)])
                continue
            for _ in range(cnt):
                if row >= h: break
                put(mem[cell(row - up, col)])
        elif a == 0xE0:
            b = nxt()
            up = 2 if b & 0x80 else 1
            cnt = (b & 0x7F) + 1
            for _ in range(cnt):
                if row >= h: break
                put(mem[cell(row - up, col)])
        elif a < 0xF8:
            if a == 0xF0:
                b = nxt()
                cnt = (b & 0x7F) + 1
                step = -1 if b & 0x80 else 1
            else:
                cnt = (a & 7) + 1
                step = 1
            r, c = idx_back(1)
            v = mem[cell(r, c)]
            for _ in range(cnt):
                if row >= h: break
                v = (v + step) & 0xFF
                put(v)
        else:
            pending.append((a & 7, cell(row, col)))
            advance()


def decode_layers(rom, m, flags=None):
    P = Pieces(rom)
    flags = flags or {}
    mem = bytearray(0x10000)
    p = P.w(0xC8, 0x5000 + 2 * m)
    end = P.w(0xC8, 0x5000 + 2 * m + 2)
    layer2 = False
    wh = [0, 0]
    wh2 = [0, 0]
    origin = [0, 0x4000]
    while p < end:
        b = rom[B(0xC8, p)]
        if b >= 0xFE:
            p += 1
            if b == 0xFF:
                layer2 = True
            else:
                layer2 = False
            ox, oy = rom[B(0xC8, p + 3)] >> 1, rom[B(0xC8, p + 4)] >> 1
            origin[1 if b == 0xFF else 0] = (0x4000 if b == 0xFF else 0) + (oy << 7) + ox
        f, rng, b2, b3, b4 = (rom[B(0xC8, p + i)] for i in range(5))
        v = flags.get(f, 0)
        if (rng >> 4) <= v <= (rng & 15):
            pid = b2 | (b3 & 1) << 8 | (b4 & 1) << 9
            dest = ((b4 >> 1) << 7) + (b3 >> 1) + (0x4000 if layer2 else 0)
            bank, ptr = P.locate(pid)
            d0, d1 = rom[B(bank, ptr)], rom[B(bank, ptr + 1)]
            w, h = (d0 >> 1) + 1, (d1 >> 1) + 1
            tgt = wh2 if layer2 else wh
            if tgt[0] == 0: tgt[0], tgt[1] = w, h
            draw(rom, bank, ptr, mem, dest, w, h)
        p += 5
    W, H = wh
    lay = lambda base, ww, hh: [list(mem[base + 128 * y: base + 128 * y + ww]) for y in range(hh)]
    return dict(width=W, height=H, layer1=lay(origin[0], W, H), layer2=lay(origin[1], wh2[0], wh2[1]) if wh2[0] else None, origin1=origin[0], origin2=origin[1] - 0x4000,
                width2=wh2[0], height2=wh2[1])


def decode_gfx(rom, gset):
    """Characters of graphics set `gset` (header byte 0 & 0x3F) as the 4bpp VRAM bytes that `$C1:F413` uploads from VRAM address 0.
    The set is a list of 3-byte records (word, count - 1) at `$CC:E27E`: word bits 15-13 select the source format (000-011: 2bpp tiles of 16 bytes, planes 2 and 3 filled
    with 0x00/0xFF by bits 14 and 13; 10x: 3bpp tiles of 24 bytes, plane 3 filled by bit 13; 110: 4bpp tiles of 32 bytes; 111: units of 64 bytes), bits 12-0 the first tile
    in the source pool (pool pointers at `$CC:E270`, 3 bytes per format)."""
    w = lambda off: struct.unpack_from('<H', rom, B(0xCC, off))[0]
    start, end = w(0xE27E + 2 * (gset & 0x3F)), w(0xE280 + 2 * (gset & 0x3F))
    out = bytearray()

    def pool(x): return B(rom[B(0xCC, 0xE272 + x)] | 0xC0, w(0xE270 + x))

    def span(src, n): return bytes(rom[(src + i) & 0x1FFFFF] for i in range(n))      # banks $E0-$FF mirror $C0-$DF

    y = start
    while y < end:
        word = rom[B(0xCC, y)] | rom[B(0xCC, y + 1)] << 8
        count = rom[B(0xCC, y + 2)] + 1
        y += 3
        mode = word >> 13
        n = word & 0x1FFF
        if mode < 4:
            src = pool(0) + n * 16
            f2, f3 = (0xFF if mode & 2 else 0), (0xFF if mode & 1 else 0)
            for t in range(count):
                tile = span(src + 16 * t, 16)
                out += tile + bytes([f2, f3] * 8)
        elif mode < 6:
            src = pool(3) + n * 24
            f3 = 0xFF if mode & 1 else 0
            for t in range(count):
                tile = span(src + 24 * t, 24)
                out += tile[:16]
                for r in range(8): out += bytes([tile[16 + r], f3])
        elif mode == 6:
            src = pool(6) + n * 32
            out += span(src, 32 * count)
        else:
            src = pool(9) + n * 64
            out += span(src, 64 * count)
    return bytes(out)


def decode_palette(rom, hdr):
    """BG palette bytes `$7E:0600-06FF` as built by `$C1:F62D` and `$C2:AA60`: row 0 colours 0 and 4-15 zero except the backdrop colour (word at +7 of the 9-byte
    screen setup entry `$C8:0100 + 9 * (header byte 5 & 0x3F)`), rows 1-7: colours 1-15 from `$CC:8000 + 0xD2 * (header byte 1 & 0x7F)` (105 words).
    Colours 2 and 3 of row 0 (window colours, `$D2:7E00`) are copied from the ROM only when a transition number is active and are left zero here."""
    pal = bytearray(0x100)
    base = B(0xCC, 0x8000) + 0xD2 * (hdr[1] & 0x7F)
    for row in range(1, 8):
        for i in range(15):
            o = 32 * row + 2 + 2 * i
            pal[o:o + 2] = rom[base + 30 * (row - 1) + 2 * i:base + 30 * (row - 1) + 2 * i + 2]
    entry = B(0xC8, 0x0100) + 9 * (hdr[5] & 0x3F)
    pal[0:2] = rom[entry + 7:entry + 9]
    return bytes(pal)


def decode_tile_words(rom, hdr):
    """Base 192 tile definitions per layer (768 words, 1536 bytes each).
    Mirrors C2:A069 with native byte wrapping and layer stream selection.
    Marker clones at tile ids >=192 are separate from the base definitions.
    """
    import map_tile_words
    memory = bytearray(0x20000)
    map_tile_words.decode(rom,memory,hdr[2])
    return bytes(memory[0x1C000:0x1C600]),bytes(memory[0x1C800:0x1CE00])


def decode_attributes(rom, hdr):
    """Tile attribute entries (4 bytes per tile id, ids 0-191) of the two layers, as `$C2:A000` + `$C2:A043` build them at `$7F:B800` and `$7F:BC00`.
    The tile set (header byte 2 & 0x3F) is a run of 384 bytes at `$CB:0400 + 0x180 * set`: the first 192 give, per tile id, an index into the table of 4-byte entries at
    `$CB:0000`; the second 192 are an alternative set. Layer 1 uses the alternative set when header byte 2 has bit 6 set, layer 2 when it has bit 7 set."""
    base = B(0xCB, 0x0400) + 0x180 * (hdr[2] & 0x3F)
    def one(second):
        out = bytearray()
        for k in range(192):
            e = rom[base + (0xC0 if second else 0) + k]
            out += rom[B(0xCB, 0) + 4 * e:B(0xCB, 0) + 4 * e + 4]
        return bytes(out)
    return one(bool(hdr[2] & 0x40)), one(bool(hdr[2] & 0x80))


def apply_markers(layer, attr):
    """The loader (`$C0:D037`, `$02:B517`) gives every tile whose attribute entry has b1 bit 7 set a new id 0xC0 + n (n counts in row-major order, per layer) and copies
    the tile's attribute entry and tilemap words to that id; the cell then holds the new id. The new ids are the trigger tiles of the exits; the counter is an 8-bit byte shifted right twice, so the ids wrap after 64 markers."""
    if not layer: return layer
    n = 0
    out = []
    for row in layer:
        r = []
        for t in row:
            if attr[4 * t + 1] & 0x80:
                r.append(0xC0 | (n & 63))
                n += 1
            else:
                r.append(t)
        out.append(r)
    return out


def main():
    rom = romio.rom_from_argv()
    cmd = sys.argv[1]
    if cmd == 'size':
        import map_tables
        t = map_tables.Tables(rom)
        for m in range(map_tables.N_MAPS):
            if t.header(m):
                d = decode_layers(rom, m)
                print(m, d['width'], d['height'], d['width2'], d['height2'])
    elif cmd == 'verify':
        import base64, map_env, map_tables
        env = map_env.MapEnv(rom)
        t = map_tables.Tables(rom)
        bad = 0
        args = sys.argv[2:]
        if '--no-boss' in args:                                # boss records are spawned during the load and their graphics overwrite work buffers
            args.remove('--no-boss')
            def rtl(cp):
                cp.PC = (cp.pull16() + 1) & 0xFFFF; cp.PB = cp.pull8(); return True
            for a in (0xC20040, 0x020040): env.c.hooks[a] = rtl
        ids = [int(a, 0) for a in args] or [m for m in range(map_tables.N_MAPS) if t.header(m)]
        for m in ids:
            h = t.header(m)
            try:
                a = decode_layers(rom, m)
            except IndexError:
                print(m, 'no valid piece list', flush=True)
                continue
            b = env.load(m)
            res = dict(
                layer1=apply_markers(a['layer1'], b['attr1']) == b['layer1'],
                layer2=apply_markers(a['layer2'], b['attr2']) == b['layer2'],
                size=(a['width'], a['height']) == (b['width'], b['height']))
            g = decode_gfx(rom, h[0])
            res['graphics'] = base64.b64decode(b['vram'])[:len(g)] == g
            pal = decode_palette(rom, h)
            res['palette'] = all(pal[i] == b['palette'][i] for i in range(0x100) if not 4 <= i <= 7)
            a1, a2 = decode_attributes(rom, h)
            res['attributes'] = bytes(b['attr1'][:0x300]) == a1 and bytes(b['attr2'][:0x300]) == a2
            w1, w2 = decode_tile_words(rom, h)
            res['tile_words'] = bytes(b['tiledef1'][:0x600]) == w1 and bytes(b['tiledef2'][:0x600]) == w2
            if not all(res.values()): bad += 1
            print(m, a['width'], a['height'], ' '.join('%s=%s' % (k, 'OK' if v else 'DIFF') for k, v in res.items()), flush=True)
        print('maps with a difference:', bad)


if __name__ == '__main__':
    main()
