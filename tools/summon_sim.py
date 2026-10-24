"""Frame-exact harness for hero spell casting on top of a ZSNES v143 save state.
library: Sim(rom, state, slot=1)
  - one video frame = joypad poll, one pass of the main loop body $C0:B08C, then the NMI handler $C0:C0A8 (tile / palette / OAM DMA into the captured PPU);
  - the ring menu ($C1:CB38, a blocking loop inside the frame) runs as it is: its NMI waits ($24 EC D0 FC loops), the sound-busy wait and the V-blank poll are
    satisfied by hooks, and every V-blank poll of the menu ($C0:6943) is one "tick" (one video frame of the menu);
  - the pad is read through $4218/$4219 (main loop) and through the serial ports $4016/$4017 (the menu), so a pad word works for both:
    0x8000 B, 0x4000 Y, 0x2000 Select, 0x1000 Start, 0x0800 up, 0x0400 down, 0x0200 left, 0x0100 right, 0x0080 A, 0x0040 X, 0x0020 L, 0x0010 R;
  - .run_seq(seq) types a list of (pad word, frames to wait) into the ring menu and returns when the hero starts casting;
  - .cast(spell, targets) performs what the menu does when it ends ($C0:731F: spell id, target list, then JSL $C0:001B) without the ring.
The sound driver is not emulated; sound requests (JSL $C3:0004) are logged. No ROM data is stored in the repository."""
import sys, os, re, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import romio, zsnes_state, combat_env as ce, rip_hero_anims as R, gfx_decode as G

HZ = R.HZ
HERO_OBJ = 0xE000
BTN = dict(B=0x8000, Y=0x4000, SEL=0x2000, START=0x1000, UP=0x0800, DOWN=0x0400, LEFT=0x0200, RIGHT=0x0100, A=0x0080, X=0x0040, L=0x0020, R=0x0010)


class SummonCpu(R.PpuCpu):
    """PpuCpu plus: V-blank flag toggling on $4212, serial joypad reads on $4016, a log of the PPU registers written, and HDMA / DMA bookkeeping."""
    def __init__(s):
        super().__init__()
        s.regs = {}; s.serial = 0; s.vb = 0; s.hdma = 0

    def hwread(s, o):
        if o == 0x4212:
            s.vb ^= 0x80; return s.vb
        if o == 0x4016:
            b = (s.pad >> (15 - s.serial)) & 1 if s.serial < 16 else 0
            s.serial += 1; return b
        if o == 0x4017: return 0
        return super().hwread(o)

    def wr8(s, a, v):
        a &= 0xFFFFFF; b = a >> 16; o = a & 0xFFFF
        if (b < 0x40 or 0x80 <= b < 0xC0):
            if o == 0x4016 and not v & 1: s.serial = 0
            if o == 0x420C: s.hdma = v & 0xFF
            if 0x2100 <= o < 0x2140: s.regs[o] = v & 0xFF
        super().wr8(a, v)
        if b == 0x7E and 0x801 <= o < 0xA01 and o & 3 == 1:         # which object wrote this OAM entry: its own piece lists, the projectile table or something else
            ob = s.wram[0x14] | s.wram[0x15] << 8; rel = s.X - 0xE000 - ob; i = (o - 0x800) >> 2
            if 0x90 <= rel < 0xD0: s.owner[i] = (ob, '90')
            elif 0xD0 <= rel < 0x110: s.owner[i] = (ob, 'D0')
            elif 0xD000 <= s.X < 0xD200: s.owner[i] = ((s.X - 0xD000) >> 6, 'proj')
            else: s.owner[i] = (-1, 'other')


class Sim:
    def __init__(s, rom, state, slot=1, keep=(), nmi=True, ai=False):
        ce.cpu.set_rom(rom)
        s.rom = rom; s.slot = slot; s.base = HERO_OBJ + 0x200 * slot
        s.env = ce.Env(rom, state, cpu_class=SummonCpu)
        s.c = c = s.env.c; s.w = c.wram
        s.f = 0; s.t = 0; s.pad = 0; s.padfn = lambda t: 0; s.on_tick = None; s.sounds = []; s.do_nmi = nmi
        w = s.w
        for k in range(11):
            if k != slot and k not in keep: w[HERO_OBJ + 0x200 * k] = 0
        w[0xD9] = 1 << slot; w[0xD4] = (0x200 * slot) & 0xFF; w[0xD5] = (0x200 * slot) >> 8; w[0xDA] = w[0xDB] = 0
        def snd(cp):
            s.sounds.append((s.f, s.t, w[0x1E00], w[0x1E01], w[0x1E02], w[0x1E03]))
            cp.PC = (cp.pull16() + 1) & 0xFFFF; cp.PB = cp.pull8(); return True
        c.hooks[0xC30004] = snd; c.hooks[0xC30000] = snd
        def rts(cp): cp.PC = (cp.pull16() + 1) & 0xFFFF; return True
        for a in (0xE0F9, 0xE6AC): c.hooks[0xC10000 | a] = rts; c.hooks[0x010000 | a] = rts
        def clr(cp): w[0xEC] = 0; return False
        for m in re.finditer(re.escape(bytes([0x24, 0xEC, 0xD0, 0xFC])), rom):      # BIT $EC / BNE: wait for the NMI to clear a flag
            o = m.start(); a = (0xC0 + (o >> 16)) << 16 | (o & 0xFFFF); c.hooks[a] = clr; c.hooks[a & 0x3FFFFF] = clr
        def snd1(cp): w[0xA162] = 2; return False
        for a in (0xC00092, 0xC0012C, 0xC00113): c.hooks[a] = snd1; c.hooks[a & 0x3FFFFF] = snd1
        def snd2(cp): w[0x1D04] &= 0xFE; return False                               # sound-busy wait loop of the menu
        c.hooks[0xD0D5C1] = snd2; c.hooks[0x10D5C1] = snd2
        def vs(cp): s.tick(True); return False                                           # V-blank poll of the menu = one frame
        c.hooks[0xC06943] = vs; c.hooks[0x006943] = vs
        s.ai = ai
        s.hero_hooks()

    def hero_hooks(s):
        def ai(cp):                                            # no monster AI step ($C1:2552) and no party AI: the actors only do what the test asks
            cp.PC = (cp.pull16() + 1) & 0xFFFF; return True
        if not s.ai: s.c.hooks[0xC12552] = ai

    def spawn_monster(s, dx, dy, mid=0, slot=3, hp=9999):
        """A passive monster made by the game's own spawner $C0:DE3B at (hero + dx, hero + dy) (same recipe as glove_sim.GloveSim.spawn)."""
        c, w = s.c, s.w; rec = bytes.fromhex('01 00 00 00 00 00 00 40 4e 66 92 15 40 00 2d 44')
        for i, b in enumerate(rec): w[0xC830 + i] = b
        w[0xC830 + 0xA], w[0xC830 + 0xB], w[0xC830 + 0xD] = 20, 25, mid
        s.env.call(0xC0DE3B, X=0x200 * slot, Y=0xC830 - 0xC800, m=1, x=0, long=False)
        m = s.env.obj(slot); h = s.env.obj(s.slot)
        m.sw(0x182, hp); m.sw(0x184, hp); m.sw(2, h.w(2) + dx); m.sw(4, h.w(4) + dy); m.sb(0x198, 1)
        return m

    def equip(s, row=0):
        """Equips weapon row `row` (0 = a glove: no weapon pieces) with the game's own refresh $C0:E9F8 (tile tables, effect tiles, palettes), like rip_hero_anims.setup."""
        w, b = s.w, s.base - 0xE000
        w[b + 0xE1E3] = row; w[b + 0xE1E4] = row // 9; w[b + 0xE1E8] = row
        s.env.call(0xC0E9F8, m=1, x=0, long=False)
        for _ in range(30): s.frame()

    def screen_xy(s):
        b = s.base - 0xE000
        return s.w[b + 0xE020] | s.w[b + 0xE021] << 8, s.w[b + 0xE022] | s.w[b + 0xE023] << 8

    def face(s, facing):
        s.w[s.base - 0xE000 + 0xE010] = dict(up=0, down=1, right=2, left=0x82)[facing]

    def tick(s, menu=False):
        s.t += 1; s.pad = s.padfn(s.t); s.c.pad = s.pad
        if s.on_tick: s.on_tick(s.t, menu)

    def nmi(s):
        c = s.c; sv = (c.PB, c.PC, c.M, c.XF, c.S, c.A, c.X, c.Y, c.D, c.DB)
        c.wram[0xEC] |= 1; c.M = 0; c.XF = 0; c.S = 0x1E00; c.PB = 0xC0; c.PC = 0xC0A8
        while not (c.PB == 0xC0 and c.PC == 0xC16F): c.step()
        c.PB, c.PC, c.M, c.XF, c.S, c.A, c.X, c.Y, c.D, c.DB = sv

    def frame(s, pad=None, limit=30_000_000):
        c, w = s.c, s.w
        if pad is not None: s.padfn = (lambda p: (lambda t: p))(pad)
        s.tick()
        w[0x56] = s.f % 5
        c.M = 1; c.XF = 0; c.S = 0x1F00; c.push16(0xFFFD); c.PB = 0xC0; c.PC = 0xB08C; c.DB = 0x7E; c.D = 0
        n = 0
        while not (c.PB == 0xC0 and c.PC == 0xFFFE):
            c.step(); n += 1
            if n > limit: raise RuntimeError('stuck at %06X' % (c.PB << 16 | c.PC))
        if s.do_nmi: s.nmi()
        s.f += 1

    def hb(s, o, n=1): return int.from_bytes(s.w[s.base + o:s.base + o + n], 'little')

    @staticmethod
    def element_index(spell):
        """Element index +0x177 of a spell: the spirit it belongs to (the spells come in blocks of six per spirit, Shade has three, Lumina three)."""
        return spell // 6 if spell < 0x24 else (6 if spell < 0x27 else 7)

    def cast(s, spell, targets=(), count=None, element=None, level=None):
        """What the menu does when it ends ($C0:731F then JSL $C0:001B): spell id into +0x170, element index +0x177, count +0x176, target list +0x178..
        (target object slot + 1), then the real cast routine."""
        w, b = s.w, s.base - 0xE000
        w[0xE170 + b] = spell; w[0xE177 + b] = s.element_index(spell) if element is None else element; w[0xE176 + b] = count if count is not None else len(targets)
        for i in range(3): w[0xE178 + b + i] = targets[i] + 1 if i < len(targets) else 0
        for i in range(3): w[0xE172 + b + i] = 0xFF
        s.env.call(0xC0001B, X=b, m=0, x=0, DB=0x7E)
        if level is not None: w[0xE171 + b] = level                  # the magic level the effect scripts read (+0x171)
        s.env.call(0xC188C7, X=b, m=1, x=0, DB=0x7E, long=False)       # the cast pose and effect script of the hero ($C1:DC38 -> $C1:88C7)

    def run_seq(s, seq, start_wait=2, maxt=2000, stop_on_cast=True):
        """Press Y, then type seq = [(pad word, wait frames)...] into the ring menu; stops when the hero leaves the idle state (+0x1C != 0)."""
        class Stop(Exception): pass
        t0 = s.t; script = {}
        t = start_wait; script[t] = script[t + 1] = BTN['Y']; t += 60
        for btn, wait in seq:
            for k in range(3): script[t + k] = btn
            t += wait
        s.padfn = lambda tt: script.get(tt - t0, 0)
        def ot(tt, menu):
            if menu: return
            if stop_on_cast and s.w[s.base - 0xE000 + 0xE01C] != 0: raise Stop()
            if tt - t0 > maxt: raise Stop()
        s.on_tick = ot
        try:
            for i in range(maxt): s.frame()
        except Stop: pass
        s.on_tick = None; s.padfn = lambda tt: 0


def load(rom_path, state_path, slot=1, **kw):
    return Sim(romio.load(rom_path), state_path, slot, **kw)
