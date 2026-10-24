"""SPC700 interpreter (the sound CPU), enough to run the game's sound driver while the 65816 talks to it through the four APU ports.
library: Apu(ram) -> .step(), .run(n), .ports_out (read by the 65816), .ports_in (written by the 65816), .dsp (128 DSP registers), .spc() -> .spc file bytes
Cycle counts are approximate (one count per instruction byte plus one); the timers advance from that count. The DSP is not emulated: its registers are
only stored, so that a .spc snapshot carries them (libgme then plays the snapshot)."""
import struct

N, V, P, B, H, I, Z, C = 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01


class Apu:
    def __init__(self, ram, pc=0x0200):
        self.ram = bytearray(ram)
        self.a = self.x = self.y = 0
        self.sp = 0xEF
        self.psw = 0
        self.pc = pc
        self.dsp = bytearray(128)
        self.ports_in = [0, 0, 0, 0]
        self.ports_out = [0, 0, 0, 0]
        self.cycles = 0
        self.tdiv = [0, 0, 0]
        self.tcount = [0, 0, 0]
        self.tsub = [0, 0, 0]
        self.ttarget = [0, 0, 0]
        self.control = 0
        self.dspaddr = 0

    # ---- memory
    def rd(self, a):
        a &= 0xFFFF
        if 0xF0 <= a <= 0xFF:
            if 0xF4 <= a <= 0xF7: return self.ports_in[a - 0xF4]
            if a == 0xF3: return self.dsp[self.dspaddr & 0x7F]
            if a == 0xF2: return self.dspaddr
            if 0xFD <= a <= 0xFF:
                v = self.tcount[a - 0xFD]; self.tcount[a - 0xFD] = 0; return v
            return 0
        return self.ram[a]

    def wr(self, a, v):
        a &= 0xFFFF; v &= 0xFF
        if 0xF0 <= a <= 0xFF:
            if 0xF4 <= a <= 0xF7: self.ports_out[a - 0xF4] = v
            elif a == 0xF1:
                for t in range(3):
                    if v >> t & 1 and not self.control >> t & 1: self.tcount[t] = 0; self.tdiv[t] = 0; self.tsub[t] = 0
                if v & 0x10: self.ports_in[0] = self.ports_in[1] = 0
                if v & 0x20: self.ports_in[2] = self.ports_in[3] = 0
                self.control = v
            elif a == 0xF2: self.dspaddr = v
            elif a == 0xF3: self.dsp[self.dspaddr & 0x7F] = v
            elif 0xFA <= a <= 0xFC: self.ttarget[a - 0xFA] = v
            self.ram[a] = v
            return
        self.ram[a] = v

    def dp(self, d): return ((0x100 if self.psw & P else 0) + (d & 0xFF)) & 0xFFFF
    def rdw_dp(self, d): return self.rd(self.dp(d)) | self.rd(self.dp(d + 1)) << 8
    def fetch(self):
        v = self.ram[self.pc]; self.pc = (self.pc + 1) & 0xFFFF; return v
    def fetchw(self):
        lo = self.fetch(); return lo | self.fetch() << 8
    def push(self, v): self.ram[0x100 + self.sp] = v & 0xFF; self.sp = (self.sp - 1) & 0xFF
    def pop(self): self.sp = (self.sp + 1) & 0xFF; return self.ram[0x100 + self.sp]

    # ---- flags
    def nz(self, v):
        v &= 0xFF
        self.psw = (self.psw & ~(N | Z)) | (v & 0x80) | (0 if v else Z)
        return v
    def setf(self, f, on): self.psw = (self.psw | f) if on else (self.psw & ~f)

    def adc(self, a, b):
        c = self.psw & C
        r = a + b + c
        self.setf(C, r > 0xFF)
        self.setf(H, ((a & 0xF) + (b & 0xF) + c) > 0xF)
        self.setf(V, (~(a ^ b) & (a ^ r)) & 0x80)
        return self.nz(r)
    def sbc(self, a, b): return self.adc(a, b ^ 0xFF)
    def cmp(self, a, b):
        r = a - b
        self.setf(C, r >= 0); self.nz(r & 0xFF)

    def tick(self, n):
        self.cycles += n
        for t in range(3):
            if not self.control >> t & 1: continue
            self.tdiv[t] += n
            per = 16 if t == 2 else 128
            while self.tdiv[t] >= per:
                self.tdiv[t] -= per
                self.tsub[t] += 1
                if self.tsub[t] >= (self.ttarget[t] or 256):
                    self.tsub[t] = 0
                    self.tcount[t] = (self.tcount[t] + 1) & 0x0F

    def run(self, n):
        for _ in range(n): self.step()

    def step(self):
        pc0 = self.pc
        op = self.fetch()
        hi, lo = op >> 4, op & 0x0F
        alu = {0: 'or', 2: 'and', 4: 'eor', 6: 'cmp', 8: 'adc', 0xA: 'sbc'}
        if lo in (4, 5, 6, 7, 8, 9) and (hi & ~1) in alu:
            kind = alu[hi & ~1]
            odd = hi & 1
            if lo == 9:
                if odd:
                    dst = self.dp(self.x); src = self.dp(self.y)
                else:
                    s = self.fetch(); d = self.fetch(); src = self.dp(s); dst = self.dp(d)
                self._alu_mem(kind, dst, self.rd(src))
            elif lo == 8 and odd:
                imm = self.fetch(); d = self.dp(self.fetch())
                self._alu_mem(kind, d, imm)
            else:
                if lo == 8: v = self.fetch()
                else:
                    if not odd:
                        if lo == 4: a = self.dp(self.fetch())
                        elif lo == 5: a = self.fetchw()
                        elif lo == 6: a = self.dp(self.x)
                        else: a = self.rdw_dp(self.fetch() + self.x)
                    else:
                        if lo == 4: a = self.dp(self.fetch() + self.x)
                        elif lo == 5: a = (self.fetchw() + self.x) & 0xFFFF
                        elif lo == 6: a = (self.fetchw() + self.y) & 0xFFFF
                        else: a = (self.rdw_dp(self.fetch()) + self.y) & 0xFFFF
                    v = self.rd(a)
                self.a = self._alu(kind, self.a, v)
            self.tick(self.pc - pc0 + 1)
            return
        f = getattr(self, 'op_%02x' % op, None)
        if f is None:
            self._generic(op)
        else:
            f()
        self.tick(max(2, (self.pc - pc0) & 0xFFFF) + 1)

    def _alu(self, kind, a, v):
        if kind == 'or': return self.nz(a | v)
        if kind == 'and': return self.nz(a & v)
        if kind == 'eor': return self.nz(a ^ v)
        if kind == 'cmp': self.cmp(a, v); return a
        if kind == 'adc': return self.adc(a, v)
        return self.sbc(a, v)

    def _alu_mem(self, kind, addr, v):
        r = self._alu(kind, self.rd(addr), v)
        if kind != 'cmp': self.wr(addr, r)

    def _rmw(self, kind, a):
        v = self.rd(a) if a is not None else self.a
        c = self.psw & C
        if kind == 'asl': self.setf(C, v & 0x80); v = (v << 1) & 0xFF
        elif kind == 'rol': self.setf(C, v & 0x80); v = ((v << 1) | c) & 0xFF
        elif kind == 'lsr': self.setf(C, v & 1); v >>= 1
        elif kind == 'ror': self.setf(C, v & 1); v = (v >> 1) | (0x80 if c else 0)
        elif kind == 'dec': v = (v - 1) & 0xFF
        elif kind == 'inc': v = (v + 1) & 0xFF
        self.nz(v)
        if a is None: self.a = v
        else: self.wr(a, v)

    def branch(self, cond):
        r = self.fetch()
        if cond: self.pc = (self.pc + (r - 256 if r > 127 else r)) & 0xFFFF

    def _generic(self, op):
        hi, lo = op >> 4, op & 0x0F
        rmw = {0x0: 'asl', 0x2: 'rol', 0x4: 'lsr', 0x6: 'ror', 0x8: 'dec', 0xA: 'inc'}
        if lo in (0xB, 0xC) and (hi & ~1) in rmw:
            kind = rmw[hi & ~1]
            if not hi & 1:
                a = self.dp(self.fetch()) if lo == 0xB else self.fetchw()
            else:
                a = self.dp(self.fetch() + self.x) if lo == 0xB else None
            self._rmw(kind, a)
            return
        if lo == 1:                                            # TCALL n
            n = hi
            self.push(self.pc >> 8); self.push(self.pc)
            v = 0xFFDE - 2 * n
            self.pc = self.ram[v] | self.ram[v + 1] << 8
            return
        if lo == 2:                                            # SET1 / CLR1 dp.bit
            bit = hi >> 1
            a = self.dp(self.fetch())
            v = self.rd(a)
            self.wr(a, (v & ~(1 << bit)) if hi & 1 else (v | (1 << bit)))
            return
        if lo == 3:                                            # BBS / BBC dp.bit, rel
            bit = hi >> 1
            v = self.rd(self.dp(self.fetch()))
            on = bool(v >> bit & 1)
            self.branch(on if not hi & 1 else not on)
            return
        if lo == 0 and hi & 1:                                 # branches
            cond = {0x1: not self.psw & N, 0x3: bool(self.psw & N), 0x5: not self.psw & V, 0x7: bool(self.psw & V),
                    0x9: not self.psw & C, 0xB: bool(self.psw & C), 0xD: not self.psw & Z, 0xF: bool(self.psw & Z)}[hi]
            self.branch(cond)
            return
        raise NotImplementedError('SPC700 op %02X at %04X' % (op, (self.pc - 1) & 0xFFFF))

    # ---- the rest, one method per opcode
    def op_00(self): pass
    def op_ef(self): self.pc = (self.pc - 1) & 0xFFFF
    def op_ff(self): self.pc = (self.pc - 1) & 0xFFFF
    def op_20(self): self.psw &= ~P
    def op_40(self): self.psw |= P
    def op_60(self): self.psw &= ~C
    def op_80(self): self.psw |= C
    def op_a0(self): self.psw |= I
    def op_c0(self): self.psw &= ~I
    def op_e0(self): self.psw &= ~(V | H)
    def op_ed(self): self.psw ^= C
    def op_2f(self): self.branch(True)
    def op_3f(self):
        a = self.fetchw(); self.push(self.pc >> 8); self.push(self.pc); self.pc = a
    def op_4f(self):
        u = self.fetch(); self.push(self.pc >> 8); self.push(self.pc); self.pc = 0xFF00 | u
    def op_6f(self): lo = self.pop(); self.pc = lo | self.pop() << 8
    def op_7f(self): self.psw = self.pop(); lo = self.pop(); self.pc = lo | self.pop() << 8
    def op_0f(self):
        self.push(self.pc >> 8); self.push(self.pc); self.push(self.psw); self.psw = (self.psw | B) & ~I
        self.pc = self.ram[0xFFDE] | self.ram[0xFFDF] << 8
    def op_5f(self): self.pc = self.fetchw()
    def op_1f(self):
        a = (self.fetchw() + self.x) & 0xFFFF; self.pc = self.rd(a) | self.rd(a + 1) << 8
    def op_0d(self): self.push(self.psw)
    def op_2d(self): self.push(self.a)
    def op_4d(self): self.push(self.x)
    def op_6d(self): self.push(self.y)
    def op_8e(self): self.psw = self.pop()
    def op_ae(self): self.a = self.pop()
    def op_ce(self): self.x = self.pop()
    def op_ee(self): self.y = self.pop()
    def op_2e(self):
        v = self.rd(self.dp(self.fetch())); self.branch(v != self.a)
    def op_de(self):
        v = self.rd(self.dp(self.fetch() + self.x)); self.branch(v != self.a)
    def op_6e(self):
        a = self.dp(self.fetch()); v = (self.rd(a) - 1) & 0xFF; self.wr(a, v); self.branch(v != 0)
    def op_fe(self):
        self.y = (self.y - 1) & 0xFF; self.branch(self.y != 0)
    def op_1e(self): self.cmp(self.x, self.rd(self.fetchw()))
    def op_3e(self): self.cmp(self.x, self.rd(self.dp(self.fetch())))
    def op_c8(self): self.cmp(self.x, self.fetch())
    def op_5e(self): self.cmp(self.y, self.rd(self.fetchw()))
    def op_7e(self): self.cmp(self.y, self.rd(self.dp(self.fetch())))
    def op_ad(self): self.cmp(self.y, self.fetch())
    # MOV loads (set NZ)
    def op_e4(self): self.a = self.nz(self.rd(self.dp(self.fetch())))
    def op_e5(self): self.a = self.nz(self.rd(self.fetchw()))
    def op_e6(self): self.a = self.nz(self.rd(self.dp(self.x)))
    def op_e7(self): self.a = self.nz(self.rd(self.rdw_dp(self.fetch() + self.x)))
    def op_e8(self): self.a = self.nz(self.fetch())
    def op_f4(self): self.a = self.nz(self.rd(self.dp(self.fetch() + self.x)))
    def op_f5(self): self.a = self.nz(self.rd((self.fetchw() + self.x) & 0xFFFF))
    def op_f6(self): self.a = self.nz(self.rd((self.fetchw() + self.y) & 0xFFFF))
    def op_f7(self): self.a = self.nz(self.rd((self.rdw_dp(self.fetch()) + self.y) & 0xFFFF))
    def op_bf(self): self.a = self.nz(self.rd(self.dp(self.x))); self.x = (self.x + 1) & 0xFF
    def op_cd(self): self.x = self.nz(self.fetch())
    def op_e9(self): self.x = self.nz(self.rd(self.fetchw()))
    def op_f8(self): self.x = self.nz(self.rd(self.dp(self.fetch())))
    def op_f9(self): self.x = self.nz(self.rd(self.dp(self.fetch() + self.y)))
    def op_8d(self): self.y = self.nz(self.fetch())
    def op_ec(self): self.y = self.nz(self.rd(self.fetchw()))
    def op_eb(self): self.y = self.nz(self.rd(self.dp(self.fetch())))
    def op_fb(self): self.y = self.nz(self.rd(self.dp(self.fetch() + self.x)))
    # MOV stores
    def op_c4(self): self.wr(self.dp(self.fetch()), self.a)
    def op_c5(self): self.wr(self.fetchw(), self.a)
    def op_c6(self): self.wr(self.dp(self.x), self.a)
    def op_c7(self): self.wr(self.rdw_dp(self.fetch() + self.x), self.a)
    def op_d4(self): self.wr(self.dp(self.fetch() + self.x), self.a)
    def op_d5(self): self.wr((self.fetchw() + self.x) & 0xFFFF, self.a)
    def op_d6(self): self.wr((self.fetchw() + self.y) & 0xFFFF, self.a)
    def op_d7(self): self.wr((self.rdw_dp(self.fetch()) + self.y) & 0xFFFF, self.a)
    def op_af(self): self.wr(self.dp(self.x), self.a); self.x = (self.x + 1) & 0xFF
    def op_d8(self): self.wr(self.dp(self.fetch()), self.x)
    def op_c9(self): self.wr(self.fetchw(), self.x)
    def op_d9(self): self.wr(self.dp(self.fetch() + self.y), self.x)
    def op_cb(self): self.wr(self.dp(self.fetch()), self.y)
    def op_cc(self): self.wr(self.fetchw(), self.y)
    def op_db(self): self.wr(self.dp(self.fetch() + self.x), self.y)
    # register moves
    def op_7d(self): self.a = self.nz(self.x)
    def op_dd(self): self.a = self.nz(self.y)
    def op_5d(self): self.x = self.nz(self.a)
    def op_fd(self): self.y = self.nz(self.a)
    def op_9d(self): self.x = self.nz(self.sp)
    def op_bd(self): self.sp = self.x
    def op_fa(self):
        s = self.fetch(); d = self.fetch(); self.wr(self.dp(d), self.rd(self.dp(s)))
    def op_8f(self):
        imm = self.fetch(); d = self.fetch(); self.wr(self.dp(d), imm)
    # 16-bit
    def op_ba(self):
        d = self.fetch(); self.a = self.rd(self.dp(d)); self.y = self.rd(self.dp(d + 1))
        ya = self.a | self.y << 8
        self.psw = (self.psw & ~(N | Z)) | (N if ya & 0x8000 else 0) | (0 if ya else Z)
    def op_da(self):
        d = self.fetch(); self.wr(self.dp(d), self.a); self.wr(self.dp(d + 1), self.y)
    def _w16(self, d, v):
        self.wr(self.dp(d), v & 0xFF); self.wr(self.dp(d + 1), v >> 8 & 0xFF)
        self.psw = (self.psw & ~(N | Z)) | (N if v & 0x8000 else 0) | (0 if v & 0xFFFF else Z)
    def op_3a(self):
        d = self.fetch(); self._w16(d, (self.rdw_dp(d) + 1) & 0xFFFF)
    def op_1a(self):
        d = self.fetch(); self._w16(d, (self.rdw_dp(d) - 1) & 0xFFFF)
    def _setya(self, v):
        v &= 0xFFFF; self.a = v & 0xFF; self.y = v >> 8
        self.psw = (self.psw & ~(N | Z)) | (N if v & 0x8000 else 0) | (0 if v else Z)
    def op_7a(self):
        m = self.rdw_dp(self.fetch()); ya = self.a | self.y << 8; r = ya + m
        self.setf(C, r > 0xFFFF); self.setf(V, (~(ya ^ m) & (ya ^ r)) & 0x8000)
        self.setf(H, ((ya & 0xFFF) + (m & 0xFFF)) > 0xFFF); self._setya(r)
    def op_9a(self):
        m = self.rdw_dp(self.fetch()); ya = self.a | self.y << 8; r = ya - m
        self.setf(C, r >= 0); self.setf(V, ((ya ^ m) & (ya ^ r)) & 0x8000)
        self.setf(H, ((ya & 0xFFF) - (m & 0xFFF)) >= 0); self._setya(r)
    def op_5a(self):
        m = self.rdw_dp(self.fetch()); ya = self.a | self.y << 8; r = ya - m
        self.setf(C, r >= 0); r &= 0xFFFF
        self.psw = (self.psw & ~(N | Z)) | (N if r & 0x8000 else 0) | (0 if r else Z)
    def op_cf(self): self._setya(self.y * self.a); self.nz(self.y)
    def op_9e(self):
        ya = self.a | self.y << 8
        self.setf(V, self.y >= self.x); self.setf(H, (self.y & 0xF) >= (self.x & 0xF))
        if self.x and self.y < (self.x << 1):
            self.a = (ya // self.x) & 0xFF; self.y = ya % self.x
        else:
            q = 255 - (ya - (self.x << 9)) // (256 - self.x) if self.x != 256 else 0
            r = self.x + (ya - (self.x << 9)) % (256 - self.x)
            self.a = q & 0xFF; self.y = r & 0xFF
        self.nz(self.a)
    def op_9f(self): self.a = self.nz(((self.a << 4) | (self.a >> 4)) & 0xFF)
    def op_df(self):
        if self.psw & C or self.a > 0x99: self.a = (self.a + 0x60) & 0xFF; self.psw |= C
        if self.psw & H or (self.a & 0xF) > 9: self.a = (self.a + 6) & 0xFF
        self.nz(self.a)
    def op_be(self):
        if not self.psw & C or self.a > 0x99: self.a = (self.a - 0x60) & 0xFF; self.psw &= ~C
        if not self.psw & H or (self.a & 0xF) > 9: self.a = (self.a - 6) & 0xFF
        self.nz(self.a)
    # increments of X / Y
    def op_1d(self): self.x = self.nz(self.x - 1)
    def op_3d(self): self.x = self.nz(self.x + 1)
    def op_dc(self): self.y = self.nz(self.y - 1)
    def op_fc(self): self.y = self.nz(self.y + 1)
    # bit ops on 13-bit address
    def _m(self):
        w = self.fetchw(); return w & 0x1FFF, w >> 13
    def op_0a(self):
        a, b = self._m(); self.setf(C, (self.psw & C) or (self.rd(a) >> b & 1))
    def op_2a(self):
        a, b = self._m(); self.setf(C, (self.psw & C) or not (self.rd(a) >> b & 1))
    def op_4a(self):
        a, b = self._m(); self.setf(C, (self.psw & C) and (self.rd(a) >> b & 1))
    def op_6a(self):
        a, b = self._m(); self.setf(C, (self.psw & C) and not (self.rd(a) >> b & 1))
    def op_8a(self):
        a, b = self._m(); self.setf(C, bool(self.psw & C) != bool(self.rd(a) >> b & 1))
    def op_ea(self):
        a, b = self._m(); self.wr(a, self.rd(a) ^ (1 << b))
    def op_aa(self):
        a, b = self._m(); self.setf(C, self.rd(a) >> b & 1)
    def op_ca(self):
        a, b = self._m(); v = self.rd(a); self.wr(a, (v | (1 << b)) if self.psw & C else (v & ~(1 << b)))
    def op_0e(self):
        a = self.fetchw(); v = self.rd(a); self.nz(self.a - v); self.wr(a, v | self.a)
    def op_4e(self):
        a = self.fetchw(); v = self.rd(a); self.nz(self.a - v); self.wr(a, v & ~self.a)

    def spc(self):
        """.spc file of the current state (libgme loads it and plays from the current PC)."""
        h = bytearray(0x10200)
        h[:0x21] = b'SNES-SPC700 Sound File Data v0.30'
        h[0x21:0x24] = bytes([26, 26, 27]); h[0x24] = 30
        h[0x25:0x27] = struct.pack('<H', self.pc)
        h[0x27], h[0x28], h[0x29], h[0x2A], h[0x2B] = self.a, self.x, self.y, self.psw, self.sp
        ram = bytearray(self.ram)
        ram[0xF1] = self.control & 0x07
        ram[0xF4:0xF8] = bytes(self.ports_in)
        for t in range(3): ram[0xFA + t] = self.ttarget[t]; ram[0xFD + t] = self.tcount[t]
        ram[0xF2] = self.dspaddr
        h[0x100:0x10100] = ram
        h[0x10100:0x10180] = self.dsp
        return bytes(h)
