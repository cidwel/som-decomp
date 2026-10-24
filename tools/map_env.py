"""Run the game's own map loader ($C0:B03F: $C0:87C4, BC9B, BC0B, E9F8, BEAA) for any map id on top of a ZSNES save state and capture what it builds.
The loader assembles the tile id layers (`$7F:0000` = layer 1, `$7F:4000` = layer 2, 128 ids per row), the 4-byte tile attribute entries (`$7F:B800` / `$7F:BC00`),
the tilemap words of every 16x16 tile (`$7F:C000` / `$7F:C800`, 4 words each: top-left, top-right, bottom-left, bottom-right), the palette (`$7E:0600`)
and uploads the 4bpp character graphics to VRAM (DMA / direct writes, captured by `rip_hero_anims.PpuCpu`).
usage:  map_env.py ROM dump MAP [MAP ...] OUTDIR [STATE]     writes OUTDIR/map_<id>.json (arrays; VRAM characters as base64) for each map
library: MapEnv(rom, state).load(map_id, flags={}) -> dict
STATE: optional ZSNES v143 state (docs/graphics.md section 8); without it WRAM starts as zeros, which gives the same layers, graphics, palette and attribute entries for tile ids below 0xC0 (the entries of the trigger tiles 0xBD-0xFF are not built by the loader and stay zero). Event flags ($7E:CF00-CFFF) are cleared to a new game and then set from `flags` (index -> value)."""
import sys, os, json, base64
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import romio, zsnes_state, cpu65816 as cpu, rip_hero_anims as R


class MapEnv:
    def __init__(self, rom, state=None):
        self.rom = rom
        if state is None:
            zsnes_state.load_wram = lambda p: bytearray(0x20000)       # a power-on WRAM: the loader needs nothing from a save state
        self.g = R.Game(rom, state or '')
        self.c = c = self.g.c
        self.base = (bytes(c.wram), bytes(c.vram), bytes(c.cgram))
        orig = c.ppu
        c.regs = {}; c.scroll = {o: 0 for o in range(0x210D, 0x2115)}; c.latch = 0

        def ppu(o, v):
            if 0x2180 <= o <= 0x2183: cpu.CPU.hwwrite(c, o, v); return
            if o in c.scroll:                                   # the write-twice scroll registers
                if o in (0x210D, 0x210F, 0x2111, 0x2113):
                    c.scroll[o] = ((v << 8) | (c.latch & ~7) | ((c.scroll[o] >> 8) & 7)) & 0x3FF
                else:
                    c.scroll[o] = ((v << 8) | c.latch) & 0x3FF
                c.latch = v
            c.regs[o] = v
            orig(o, v)
        c.ppu = ppu
        base_read = c.hwread

        def hwread(o):
            if 0x4300 <= o < 0x4380: return c.ch.get(o, 0)         # the loader reads back $4372/$4375 to split a DMA that crosses a bank
            return base_read(o)
        c.hwread = hwread
        plain_rd8 = c.rd8

        def rd8(a):
            if (a >> 16) & 0xFF >= 0xE0: a &= ~0x200000            # banks $E0-$FF mirror $C0-$DF on a 2 MiB HiROM cart
            return plain_rd8(a)
        c.rd8 = rd8
        run_dma = c.dma

        self.drop_full_vram = False

        def dma(mask):
            if self.drop_full_vram:
                # With a power-on WRAM one upload queue entry is empty: count 0 = 64 KiB from $7E:9C00 over the whole VRAM. The running
                # game never issues it (measured on map 256 and 128: without it the same 38 characters change as in the game).
                for ch in range(8):
                    b = 0x4300 + ch * 16
                    if mask >> ch & 1 and c.ch.get(b + 1, 0) == 0x18 and not (c.ch.get(b + 5, 0) | c.ch.get(b + 6, 0)):
                        mask &= ~(1 << ch)
            regs = {k: dict(c.ch) for k in (0,)}
            run_dma(mask)
            for ch in range(8):                                   # real DMA leaves the source address advanced and the count at 0 (the second half of a split transfer relies on it)
                if not mask >> ch & 1: continue
                b = 0x4300 + ch * 16
                n = (regs[0].get(b + 5, 0) | regs[0].get(b + 6, 0) << 8) or 0x10000
                if not regs[0].get(b, 0) & 0x08:
                    src = (regs[0].get(b + 2, 0) | regs[0].get(b + 3, 0) << 8) + n
                    c.ch[b + 2], c.ch[b + 3] = src & 255, (src >> 8) & 255
                c.ch[b + 5] = c.ch[b + 6] = 0
        c.dma = dma

    def callrts(self, a, m=1):
        c = self.c
        c.M = m; c.XF = 0; c.S = 0x1F00; c.push16(0xFFFD); c.PB = a >> 16; c.PC = a & 0xFFFF
        n = 0
        while not (c.PB == a >> 16 and c.PC == 0xFFFE):
            c.step(); n += 1
            if n > 8_000_000: raise RuntimeError('timeout at %02X:%04X' % (c.PB, c.PC))

    def calll(self, a, A=None):
        c = self.c
        c.M = 0; c.XF = 0
        if A is not None: c.A = A
        c.S = 0x1F00; c.push8(0xFE); c.push16(0xFFFD); c.PB = a >> 16; c.PC = a & 0xFFFF
        while not (c.PB == 0xFE and c.PC == 0xFFFE): c.step()

    def load(self, map_id, flags=None, entry_event=False, transition=None):
        """transition: one of the map's own entry transitions. What the loader puts on BG3 (the log bridge of the opening, map 256) depends
        on the transition the map is entered by; without one, any transition is used and the map id is overwritten (BG3 stays empty)."""
        c = self.c; w = c.wram
        self._last_load = (map_id, flags, entry_event, transition)
        w[:] = self.base[0]; c.vram[:] = self.base[1]; c.cgram[:] = self.base[2]
        c.regs.clear()
        for a in range(0xCF00, 0xD000): w[a] = 0
        for k, v in (flags or {}).items(): w[0xCF00 + k] = v
        for a in (0xD0, 0xF1, 0x4E, 0x4F, 0x1D04, 0x1D00): w[a] = 0
        for i in range(9): w[0xE60 + i] = 0
        self.calll(0xC1E76D, A=0x800 | (59 if transition is None else transition))
        if transition is None:
            w[0xDC] = map_id & 255; w[0xDD] = map_id >> 8
        w[0xFF] = 0; w[0xE2] = 0
        for a in (0xC087C4, 0xC0BC9B, 0xC0BC0B, 0xC0E9F8): self.callrts(a)
        if entry_event: self.callrts(0xC0BEAA)
        return self.snapshot(map_id)

    def animation_phases(self, phases=4, step=8, start=48):
        """Runs the animation routines of the frame body (`$01:B033`, `$01:BFE0`, `$02:BAD6`) and the NMI upload for `start + phases * step` frames of the loaded map.
        Returns (vram, palette) per phase: the state right after the loader with every character and palette colour that the animation routines change replaced
        by its value at frame `start + k * step`. What the animation changes is told apart from what the NMI alone uploads (with a power-on WRAM it also uploads
        data of other screen layers, which is not part of the map) by running the same frames a second time, from a fresh load, with the NMI only: a character
        that differs between the two runs, or between the phases, is animation. Water palette cycles (header byte 1 bit 7), character animations (header byte 0
        bit 6) and what they set once and keep (the ripples and the water colours of Potos Falls, map 128) show up here."""
        base_v, base_p = bytes(self.c.vram[:0x8000]), bytes(self.c.wram[0x600:0x800])

        def run(animate):
            snaps = []
            for f in range(start + phases * step):
                if animate:
                    for a in (0x01B033, 0x01BFE0, 0x02BAD6): self.calll(a)
                self.g.nmi()
                if f >= start and (f - start) % step == 0:
                    snaps.append((bytes(self.c.vram[:0x8000]), bytes(self.c.wram[0x600:0x800])))
            return snaps
        self.drop_full_vram = True
        try:
            snaps = run(True)
            self.load(*self._last_load)
            plain = run(False)
        finally:
            self.drop_full_vram = False
        def changed(k, base, size, span):
            cycles = [i for i in range(0, span, size) if len({s[k][i:i + size] for s in snaps}) > 1]
            # set once by the animation: changed in the animated run, untouched by the NMI-only run (where the NMI writes, it is not map data)
            once = [i for i in range(0, span, size)
                    if snaps[-1][k][i:i + size] != base[i:i + size] and all(q[k][i:i + size] == base[i:i + size] for q in plain)]
            return sorted(set(cycles) | set(once))
        chars = changed(0, base_v, 32, 0x8000)
        cols = changed(1, base_p, 2, 0x200)
        out = []
        for v, p in snaps:
            nv, np_ = bytearray(base_v), bytearray(base_p)
            for i in chars: nv[i:i + 32] = v[i:i + 32]
            for i in cols: np_[i:i + 2] = p[i:i + 2]
            out.append((bytes(nv), bytes(np_)))
        return out

    def snapshot(self, map_id):
        c = self.c; w = c.wram
        w16 = lambda a: w[a] | w[a + 1] << 8
        W, H = w16(0xC0) // 16, w16(0xC2) // 16
        W2, H2 = w16(0xC4) // 16, w16(0xC6) // 16
        wr = lambda off, n: bytes(w[0x10000 + off:0x10000 + off + n])
        lay = lambda base, ww, hh: [list(wr(base + 128 * y, ww)) for y in range(hh)]
        return dict(
            map=map_id, width=W, height=H, width2=W2, height2=H2,
            layer1=lay(0, W, H), layer2=lay(0x4000, W2, H2) if W2 and H2 else None,
            attr1=list(wr(0xB800, 0x400)), attr2=list(wr(0xBC00, 0x400)),
            tiledef1=list(wr(0xC000, 0x800)),
            tiledef2=list(wr(0xC800, 0x800)),
            palette=list(bytes(w[0x600:0x800])),
            vram=base64.b64encode(bytes(c.vram[:0x8000])).decode(),
            vram_full=base64.b64encode(bytes(c.vram)).decode(),
            # PPU state the loader leaves: BG mode, layer bases, main/sub screens, colour math, scroll, and the camera ($A8/$AA)
            ppu={'%04X' % k: v for k, v in sorted(c.regs.items()) if k < 0x2140},
            scroll={'%04X' % k: v for k, v in sorted(c.scroll.items())},
            camera=[w16(0xA8), w16(0xAA)],
            hdr_wram=dict(b8=w[0xB8], b30=w[0x30], b94=w[0x94], b90=w[0x90], b9a=w[0x9A], b80=w[0x80], b99=w[0x99]))


def main():
    rom = romio.rom_from_argv()
    if sys.argv[1] != 'dump': sys.exit(__doc__)
    args = sys.argv[2:]
    state = args.pop() if args and not args[-1].isdigit() and os.path.isfile(args[-1]) else None
    maps = [int(a, 0) for a in args[:-1]]
    out = args[-1]
    os.makedirs(out, exist_ok=True)
    env = MapEnv(rom, state)
    for m in maps:
        d = env.load(m)
        json.dump(d, open(os.path.join(out, 'map_%d.json' % m), 'w'))
        print(m, d['width'], d['height'], d['width2'], d['height2'])


if __name__ == '__main__':
    main()
