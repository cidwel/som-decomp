"""Python model of the enemy AI bytecode machine ($C1:2552 -> $C1:251A, handler table $C1:2257) for every opcode that the scripts of the ordinary
monsters 0x00-0x53 use (76 opcodes for 0x00-0x1F; 0x20-0x53 add 75, EA, EE and the undefined op 85), plus the other variable and compare ops that
share their handlers. Undefined ops (handler = the error handler $C1:0100, aidis.UNDEF) restart the script.
The model is written from the handler code and from the experiments of tools/ai_ops.py; it is checked against the real handlers by
tools/monster_model.py (command bytes, script pointer, call stack, the four variables, target slots, saved position, random bytes consumed and
every byte of the object records of slots 0-5 after every AI step, in randomised worlds).
library: VM(rom, entry).step(world, rng_bytes) -> (command bytes written (up to 4 values, None where the op leaves the byte alone), yield value)
         VM.effects: list of side effects of the last step that the game has to replay (see EFFECTS below)
         Actor(x, y, h, active, status)    World(me, heroes, gauge, hp, level, facing, mons=None, slot=3)
Objects are 0x200-byte records (Actor.m); a field is addressed by its offset in the record ("obj+0x190"). Time and movement are not modelled: the
world is whatever the caller sets before each step.

Machine state of one monster (record offsets): pc $144 (word, relative to the script base 0x104F15), variables var0..var3 (the nibbles of $146 low, $146
high, $147 low, $147 high), saved position $148/$14A, flags word $14C (not touched by the ops used here), $14D (copy of the command byte after every step), call
depth $14F and return stack $150 + 2k, current target slot $1AC (FF = none), second target slot $1AD (FF = none), command bytes $140..$143.

EFFECTS (tuples in VM.effects, in order of execution):
  ('set', slot, offset, value)      a byte of an object record was written by a script op (DA/DB/DC) or by the model of an op
  ('cast', spell, target_slot)      op E9 started the cast of attack/spell `spell` on second target `target_slot` ($C0:001B called, command 0x44)
  ('cast_all', spell, [slots])      op EA started the cast of `spell` on the slots listed (always 0,1,2 or 3,4,5; $C0:001B called, command 0x44)
  ('flash',)                        op FC toggled the palette/flash bytes $1E3/$1E4 and called $C0:003C
  ('restart',)                      the error handler $C1:0100 ran: script restarted at entry + 3, variables and targets cleared
"""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import aidis

BASE = aidis.BASE
UNDEF = aidis.UNDEF


class Actor:
    """One object record. x, y, h (jump height), active, status are views of the record bytes."""
    def __init__(self, x=128, y=112, h=0, active=1, status=0, m=None):
        self.m = (m if isinstance(m, bytearray) else bytearray(m)) if m is not None else bytearray(0x200)
        if m is None:
            self.x, self.y, self.h, self.active, self.status = x, y, h, active, status

    def _w(off):
        return property(lambda s: s.m[off] | s.m[off + 1] << 8, lambda s, v: s.m.__setitem__(slice(off, off + 2), bytes([v & 0xFF, (v >> 8) & 0xFF])))

    def _b(off):
        return property(lambda s: s.m[off], lambda s, v: s.m.__setitem__(off, v & 0xFF))

    x = _w(0x20)
    y = _w(0x22)
    h = _b(0x45)
    active = _b(0x00)
    status = _w(0x190)
    del _w, _b

    @property
    def ey(self): return (self.y - self.h) & 0xFFFF            # $C1:032E / $0343: screen y minus jump height

    def b(self, off): return self.m[off]
    def w(self, off): return self.m[off] | self.m[off + 1] << 8

    def sb(self, off, v): self.m[off] = v & 0xFF


class World:
    """Actor records and ambient inputs for one step.
    E3 uses the native-frame byte at D+$80 as velocity_direction_mask. The default
    $80 retains the earlier sign-mask assumption; exact callers must supply the byte.
    """
    def __init__(self, me, heroes, gauge=None, hp=None, level=None, facing=None, mons=None, slot=3, ram=None, pads=None, velocity_direction_mask=0x80):
        self.me, self.heroes, self.mons, self.slot = me, heroes, dict(mons or {}), slot
        self.ram = dict(ram or {})               # WRAM bytes outside the object records read by the scripts ($CC00 page of object ref >= 0x83)
        self.pads = list(pads or [0, 0, 0])      # controller binding bytes $D9-$DB (hero AI op 62)
        self.velocity_direction_mask = velocity_direction_mask & 0xFF
        if gauge is not None: self.gauge = gauge
        if hp is not None: self.hp = hp
        if facing is not None: self.facing = facing
        if level is not None:
            for h in heroes: h.sb(0x181, level)

    gauge = property(lambda s: s.me.m[0x1ED], lambda s, v: s.me.sb(0x1ED, v))
    hp = property(lambda s: s.me.w(0x182), lambda s, v: (s.me.sb(0x182, v), s.me.sb(0x183, v >> 8)))
    facing = property(lambda s: s.me.m[0x10], lambda s, v: s.me.sb(0x10, v))
    level = property(lambda s: s.heroes[0].m[0x181])

    def obj(self, slot):
        """object record of a slot (an inactive empty record when the slot holds nothing)"""
        if slot == self.slot: return self.me
        if 0 <= slot < len(self.heroes): return self.heroes[slot]
        return self.mons.get(slot) or Actor(0, 0, 0, 0, 0)


def on_screen(a):
    """$C1:0526 (used through $C1:05A5 for the current target): active and on screen; the status word is not tested."""
    return a.active == 1 and a.x < 256 and a.ey < 224


def valid(a, me=None):
    """$C1:054A (target acquisition): active, not the actor itself, on screen, status word has none of the bits 0x8460."""
    return a is not me and on_screen(a) and (a.status & 0x8460) == 0


def dist_class(a, b):
    """$C1:0358: 1, 2, 4, 8, 0x10, 0x30 for distance <= 16, 32, 48, 64, 96, farther; 8 when a coordinate difference is 256 or more.
    The sum of squares is a 16-bit sum (carry dropped)."""
    dx = abs(a.x - b.x)
    if dx > 255: return 8
    dy = abs(a.ey - b.ey)
    if dy > 255: return 8
    s = (dx * dx + dy * dy) & 0xFFFF
    if s > 0x2400: return 0x30
    if s > 0x1000: return 0x10
    if s > 0x0900: return 8
    if s > 0x0400: return 4
    if s > 0x0100: return 2
    return 1


def direction(src, dst):
    """$C1:0404 with X = dst, Y = src: returns (hi, lo), the two bytes of the 16-bit result.
    Per axis the offset is dst - src as an absolute value; when it is 256 or more the 16-bit value is folded (0x100 - low byte) and the sign flips.
    big/small = larger/smaller of the two offsets (horizontal wins ties). alt = 5 xor sign bits: 1 right / 2 left | 4 down / 8 up.
    lo = (alt << 4) | (alt & mask9): mask9 is the major-axis mask (3 horizontal, 0xC vertical), or 0xF when 1.5 * small > big ... i.e. when
        (big - small) / 2 + (big - small) / 4 < small (diagonal band).
    hi = (small & 0xF0) | (alt & major-axis mask)."""
    b = 0
    a = (dst.x - src.x) & 0xFFFF
    if (dst.x & 0xFFFF) < (src.x & 0xFFFF):
        a = (-a) & 0xFFFF; b = 3
    if a & 0xFF00:
        a = (-(a | 0xFF00)) & 0xFFFF; b ^= 3
    dx = a
    a = (dst.ey - src.ey) & 0xFFFF
    if dst.ey < src.ey:
        a = (-a) & 0xFFFF; b |= 0x0C
    if a & 0xFF00:
        a = (-(a | 0xFF00)) & 0xFFFF; b ^= 0x0C
    dy = a
    if dy <= dx: small, big, m7, m9 = dy, dx, 3, 3
    else: small, big, m7, m9 = dx, dy, 0x0C, 0x0C
    d = (big - small) & 0xFFFF
    t = (d >> 1) + ((d >> 1) >> 1)
    if t < small: m9 = 0x0F
    alt = (5 ^ b) & 0xFF
    lo = ((alt << 4) | (alt & m9)) & 0xFF
    hi = ((small & 0xF0) | (alt & m7)) & 0xFF
    return hi, lo


def primary_code(dx, dy):
    """kept for the callers of the first version: 8-way code from offsets target - self (dy already minus height)"""
    a = Actor(0, 0, 0, 1, 0); t = Actor(dx & 0xFFFF, dy & 0xFFFF, 0, 1, 0)
    return direction(a, t)[1] & 0x0F


OPP = {1: 2, 2: 1, 4: 8, 8: 4}


class VMError(Exception):
    pass


class VMBadRef(VMError):
    """an op dereferenced an object slot that holds no object (current target FF): the game reads whatever lies below the object table"""


class VM:
    def __init__(self, rom, entry):
        self.rom, self.entry = rom, entry
        self.pc, self.stack, self.var, self.tgt, self.tgt2 = entry, [], [0, 0, 0, 0], 0xFF, 0xFF
        self.mem = [0] * 16          # the 16 stack words of the record: popped entries stay in place, a push overwrites
        self.saved = (0xFFFF, 0xFFFF)
        self.draws = 0
        self.visited = set()
        self.branches = set()        # (pc, jump taken) of every conditional op executed (coverage)
        self.effects = []

    var3 = property(lambda s: s.var[3], lambda s, v: s.var.__setitem__(3, v))

    def b(self, pc): return self.rom[BASE + pc]

    def write_state(self, rec):
        """write the machine state into an object record (offsets as in the game)"""
        rec[0x144], rec[0x145] = self.pc & 0xFF, self.pc >> 8
        rec[0x146] = self.var[0] | self.var[1] << 4
        rec[0x147] = self.var[2] | self.var[3] << 4
        rec[0x148], rec[0x149] = self.saved[0] & 0xFF, self.saved[0] >> 8
        rec[0x14A], rec[0x14B] = self.saved[1] & 0xFF, self.saved[1] >> 8
        rec[0x14F] = len(self.stack)
        for i, p in enumerate(self.mem): rec[0x150 + 2 * i], rec[0x151 + 2 * i] = p & 0xFF, p >> 8
        for i, p in enumerate(self.stack): rec[0x150 + 2 * i], rec[0x151 + 2 * i] = p & 0xFF, p >> 8
        rec[0x1AC], rec[0x1AD] = self.tgt, self.tgt2

    # ---- object access -------------------------------------------------------------------------------------------------------------------
    def slot_of(self, w, ref):
        if ref < 0x80: return ref
        if ref == 0x80: return w.slot
        if ref == 0x81: return self.tgt
        if ref == 0x82: return self.tgt2
        raise VMError('object reference %02X not modelled' % ref)

    def target_obj(self, w, ref):
        s = self.slot_of(w, ref)
        if s >= 0x30: raise VMBadRef('object reference %02X resolves to slot %02X' % (ref, s))
        return w.obj(s)

    def get_byte(self, w, ref, off):
        if ref > 0x82:                      # $C1:2010: page $CA80 + (slot & 3): WRAM $CC00 + slot + offset (party settings $CC73, $CC7A, $CC7D)
            return w.ram.get((0xCC00 + (w.slot & 3) + off) & 0xFFFF, 0)
        o = self.target_obj(w, ref)
        a = off + 0x180
        if a >= 0x200: raise VMError('field offset out of the record')
        if o is w.me:
            if a == 0x1AC: return self.tgt
            if a == 0x1AD: return self.tgt2
        return o.m[a]

    def get_word(self, w, ref, off):
        return self.get_byte(w, ref, off) | self.get_byte(w, ref, off + 1) << 8

    def set_byte(self, w, ref, off, val):
        o = self.target_obj(w, ref)
        a = off + 0x180
        if a >= 0x200: raise VMError('field offset out of the record')
        if o is w.me and a in (0x1AC, 0x1AD, 0x144, 0x145, 0x146, 0x147, 0x14F): raise VMError('script write to machine state')
        o.m[a] = val & 0xFF
        self.effects.append(('set', self.slot_of(w, ref), a, val & 0xFF))

    def rnd(self, rng, n):
        if n == 0: return 0
        while True:
            v = rng[self.draws] & 0x0F; self.draws += 1
            if v <= n: return v

    # ---- target helpers ------------------------------------------------------------------------------------------------------------------
    def band(self, w, thr):
        """first valid hero (slot order) whose distance class <= thr; None if none"""
        for i, h in enumerate(w.heroes):
            if valid(h, w.me) and dist_class(w.me, h) <= thr: return i
        return None

    def cur_obj(self, w, second=False):
        """$C1:05A5 / $05BA: the object of the current (second) target when it is active and on screen, else None"""
        t = self.tgt2 if second else self.tgt
        if t == 0xFF: return None
        o = w.obj(t)
        return o if on_screen(o) else None

    def other_monster(self, w, maxclass):
        """$C1:0C9A (maxclass 8) / $0CE3 (class < 0x20): first of the slots 3-5 that is valid, not this monster and has a monster id below 0x80 and is
        within the class; returns the slot or 0xFF"""
        for s in (3, 4, 5):
            o = w.obj(s)
            if not valid(o, w.me) or o.m[0x180] >= 0x80: continue
            c = dist_class(w.me, o)
            if (maxclass == 8 and c <= 8) or (maxclass == 0x20 and c < 0x20): return s
        return 0xFF

    def restart(self, w, cmd):
        """$C1:0100: error handler, restart at entry + 3"""
        self.pc, self.stack = self.entry + 3, []
        self.var = [0, 0, 0, 0]; self.tgt = self.tgt2 = 0xFF
        w.me.m[0x14C] = w.me.m[0x14D] = w.me.m[0x14E] = 0
        cmd[0] = 0
        self.effects.append(('restart',))
        return 0

    # ---- one AI step ---------------------------------------------------------------------------------------------------------------------
    def step(self, w, rng):
        """run ops until one yields (at most 256); returns (command bytes written, yield value)"""
        self.draws = 0
        self.effects = []
        cmd = [0, None, None, None]
        r = None
        for _ in range(256):
            r = self.op(w, rng, cmd)
            if r is not None and r == 0: break
        else:
            r = self.restart(w, cmd)
        # $C1:24D7: confused actors (status bit 0x80) get the direction bits of their move / pose command mirrored
        if cmd[0] in (0xC1, 0x40) and (w.me.status & 0x80) and cmd[1] is not None:
            k = 0
            if cmd[1] & 0x0C: k = 0x0C
            if cmd[1] & 0x03: k |= 0x03
            cmd[1] ^= k
        self.commit(w, cmd)
        return cmd, r

    def commit(self, w, cmd):
        """write the command bytes, their copy $14D and the machine state into the record of the monster"""
        m = w.me.m
        for i, v in enumerate(cmd):
            if v is not None: m[0x140 + i] = v
        m[0x14D] = cmd[0]
        self.write_state(m)

    def jump_or_skip(self, ln, tgt, take):
        self.branches.add((self.pc, bool(take)))
        self.pc = tgt if take else self.pc + ln

    def op(self, w, rng, cmd):
        """execute one op; returns None to continue (handler value 0xFF) or 0 to yield"""
        pc = self.pc; op = self.b(pc); self.visited.add(pc)
        ln, text, tgt, ft = aidis.decode(self.rom, pc)
        a = [self.b(pc + 1 + i) for i in range(6)]
        me = w.me
        fx = self.effects
        def done(): self.pc = pc + ln
        # ---- control flow
        if op == 0x00:
            if not self.stack: return self.restart(w, cmd)
            self.pc = self.stack.pop(); return None
        if op == 0x01: self.pc = tgt; return None
        if op == 0xFF:
            self.mem[len(self.stack)] = pc + 3
            if len(self.stack) + 1 >= 16: return self.restart(w, cmd)
            self.stack.append(pc + 3); self.pc = tgt; return None
        # ---- variables: 02-09 jump if var != 0 (02-05) / == 0 (06-09); 0A-19 compare with the argument; 1A-24 inc, dec, copy; 25-28 set; 29-2C random
        if 0x02 <= op <= 0x05: self.jump_or_skip(ln, tgt, self.var[op - 2] != 0); return None
        if 0x06 <= op <= 0x09: self.jump_or_skip(ln, tgt, self.var[op - 6] == 0); return None
        if 0x0A <= op <= 0x19:
            k, fam = (op - 0x0A) & 3, (op - 0x0A) >> 2
            v = self.var[k]
            take = (v != a[0], v == a[0], v > a[0], v < a[0])[fam]
            self.jump_or_skip(ln, tgt, take); return None
        if 0x1A <= op <= 0x1D: self.var[op - 0x1A] = (self.var[op - 0x1A] + 1) & 15; done(); return None
        if 0x1E <= op <= 0x21: self.var[op - 0x1E] = (self.var[op - 0x1E] - 1) & 15; done(); return None
        if 0x22 <= op <= 0x24: self.var[op - 0x21] = self.var[0]; done(); return None
        if 0x25 <= op <= 0x28: self.var[op - 0x25] = a[0] & 15; done(); return None
        if 0x29 <= op <= 0x2C: self.var[op - 0x29] = self.rnd(rng, a[0] & 15); done(); return None
        # ---- compares and writes on object fields (argument 1 = object ref, argument 2 = offset - 0x180)
        if op == 0x2D: self.jump_or_skip(ln, tgt, (self.get_byte(w, a[0], a[1]) & a[2]) != 0); return None
        if op == 0x2E: self.jump_or_skip(ln, tgt, (self.get_byte(w, a[0], a[1]) & a[2]) == 0); return None
        if op == 0x2F: self.jump_or_skip(ln, tgt, self.get_byte(w, a[0], a[1]) < a[2]); return None
        if op == 0x30: self.jump_or_skip(ln, tgt, self.get_byte(w, a[0], a[1]) > a[2]); return None
        v16 = a[2] | a[3] << 8
        if op == 0xBA: self.jump_or_skip(ln, tgt, (self.get_word(w, a[0], a[1]) & v16) != 0); return None
        if op == 0xBB: self.jump_or_skip(ln, tgt, (self.get_word(w, a[0], a[1]) & v16) == 0); return None
        if op == 0xBC: self.jump_or_skip(ln, tgt, self.get_word(w, a[0], a[1]) < v16); return None
        if op == 0xBD: self.jump_or_skip(ln, tgt, self.get_word(w, a[0], a[1]) > v16); return None
        if op in (0xDA, 0xDB, 0xDC):
            cur = self.get_byte(w, a[0], a[1])
            self.set_byte(w, a[0], a[1], cur | a[2] if op == 0xDA else cur & a[2] if op == 0xDB else a[2])
            done(); return None
        # ---- target classes
        thr = {0x31: 1, 0x49: 2, 0x4E: 4, 0x53: 8}
        if op in thr: self.jump_or_skip(ln, tgt, self.band(w, thr[op]) is None); return None
        if op == 0x58: self.jump_or_skip(ln, tgt, not any(valid(h, me) for h in w.heroes)); return None
        thr = {0x4C: 2, 0x51: 4, 0x56: 8}
        if op in thr:
            h = self.cur_obj(w)
            self.jump_or_skip(ln, tgt, not (h is not None and dist_class(me, h) <= thr[op])); return None
        if op == 0x34:
            h = self.cur_obj(w)
            self.jump_or_skip(ln, tgt, not (h is not None and dist_class(me, h) == 1)); return None
        if op == 0x46:                      # fall through only when the current target is valid and in the 49-64 px band
            h = self.cur_obj(w)
            self.jump_or_skip(ln, tgt, not (h is not None and dist_class(me, h) == 8)); return None
        if op == 0x5A:                      # fall through only when the current target is valid and in the 65-96 px band
            h = self.cur_obj(w)
            self.jump_or_skip(ln, tgt, not (h is not None and (dist_class(me, h) & 0x10))); return None
        # lane / side tests on the current target: hi byte of $C1:0404
        lanes = {0x66: (0xF3, 8), 0x68: (0xF3, 4), 0x6A: (0xF3, 0x30), 0x6F: (0xFC, 8), 0x71: (0xFC, 4), 0x73: (0xFC, 0x30)}
        if op in lanes:
            mask, cls = lanes[op]
            h = self.cur_obj(w)
            ok = False
            if h is not None:
                hi, _ = direction(me, h)
                ok = (hi & mask) == 0 and dist_class(me, h) <= cls
            self.jump_or_skip(ln, tgt, not ok); return None
        sides = {0x75: 8, 0x77: 4, 0x79: 2, 0x7B: 1}
        if op in sides:
            h = self.cur_obj(w)
            ok = h is not None and (direction(me, h)[0] & sides[op]) != 0
            self.jump_or_skip(ln, tgt, not ok); return None
        if op in (0x5F, 0x60):               # object (ref a0) inside the box 8 <= x <= 248, 8 <= y - h <= 216 (signed words)
            o = self.target_obj(w, a[0])
            sx = o.x - 0x10000 if o.x >= 0x8000 else o.x
            sy = o.ey - 0x10000 if o.ey >= 0x8000 else o.ey
            inside = 8 <= sx <= 0xF8 and 8 <= sy <= 0xD8
            self.jump_or_skip(ln, tgt, (not inside) if op == 0x5F else inside); return None
        if op == 0x54:                      # jump when no other ordinary monster of slots 3-5 is valid within 64 px
            self.jump_or_skip(ln, tgt, self.other_monster(w, 8) == 0xFF); return None
        if op == 0xD8:                      # second target = such a monster (FF when none)
            self.tgt2 = self.other_monster(w, 8); done(); return None
        if op == 0xF5:                      # jump when more than arg of the monsters in slots 3-5 (this one included) are active and on screen
            n = sum(1 for s in (3, 4, 5) if on_screen(w.obj(s)))
            self.jump_or_skip(ln, tgt, n > a[0]); return None
        sel = {0xA5: 1, 0xB1: 2, 0xB4: 4, 0xB7: 8}
        if op in sel:
            i = self.band(w, sel[op]); self.tgt = 0xFF if i is None else i; done(); return None
        if op == 0x5D:
            self.tgt = 0xFF
            for i, h in enumerate(w.heroes):
                if valid(h, me) and dist_class(me, h) > 8: self.tgt = i; break
            done(); return None
        if op == 0xC0: self.tgt2 = 0xFF; done(); return None
        if op == 0xC1: self.tgt2 = self.tgt; done(); return None
        if op == 0xC4: self.tgt2 = w.slot; done(); return None
        # ---- position memory
        if op == 0x9F: self.saved = (me.x, me.ey); done(); return None
        if op == 0x9D: self.jump_or_skip(ln, tgt, self.saved == (me.x, me.ey)); return None
        if op == 0x9E: self.jump_or_skip(ln, tgt, self.saved != (me.x, me.ey)); return None
        # ---- commands
        if op == 0xE0:
            cmd[:] = [0xC1, a[0], a[1], a[2]]; done(); return 0
        if op == 0xE2:
            cmd[0], cmd[1] = 0x40, a[0]; done(); return 0
        if op == 0xE3:
            vx, vy = me.m[6], me.m[7]
            face = 0
            if vx: face = 2 if vx & w.velocity_direction_mask else 1
            if vy: face |= 8 if vy & w.velocity_direction_mask else 4
            if not face: face = {0: 8, 1: 4, 2: 1}.get(w.facing, 2)
            cmd[:] = [0xC1, face, a[0], a[1]]; done(); return 0
        if op in (0xE4, 0xFD, 0xE6, 0xFE, 0xBE, 0xBF, 0xE5, 0xE7):
            second = op in (0xE5, 0xE7)
            h = self.cur_obj(w, second)
            done()
            if h is None: return None
            if op in (0xE4, 0xE5): code = direction(me, h)[1] & 0x0F
            elif op == 0xFD: code = direction(me, h)[1] >> 4
            elif op in (0xE6, 0xE7): code = direction(h, me)[1] & 0x0F
            elif op == 0xFE: code = direction(h, me)[1] >> 4
            elif op == 0xBE: code = direction(me, h)[0] & 0x0F
            else: code = direction(h, me)[0] & 0x0F
            cmd[:] = [0xC1, code, a[0], a[1]]
            return 0
        if op == 0xFA:
            done()
            if w.gauge != 0: return None
            me.m[0x19B] = a[0]; cmd[0] = 0x02; return 0
        if op == 0xEC: cmd[0] = 0x03; done(); return 0
        if op == 0xEB:
            cmd[:] = [0xC0, a[0], a[1], min(15, max(1, ((me.x & 255) + 8) // 16))]
            done(); return 0
        if op == 0xF7:
            cmd[0], cmd[1], cmd[2] = 0x82, a[0], a[1]; done(); return 0
        if op in (0xF0, 0xF1):
            if op == 0xF0: self.tgt = a[0]
            else: self.tgt2 = a[0]
            done(); return None
        if op == 0xE8:
            done()
            if w.gauge != 0: return None
            me.m[0x19B] = me.m[0x1C0]; fx.append(('set', w.slot, 0x19B, me.m[0x1C0]))
            cmd[0] = 0x02; return 0
        if op == 0xED:
            cmd[0], cmd[1] = 0x43, a[0]; done(); return 0
        if op == 0xEF:
            cmd[0], cmd[1], cmd[2] = 0x81, a[0], a[1]; done(); return 0
        if op == 0xE9:
            # cast: needs a valid second target on screen, MP (obj+0x186) >= the cost byte of attack record a[1], not confused, obj+0x60 != 0xE0
            h = self.cur_obj(w, True)
            cost = self.rom[0x102ADF + a[1] * 0x40]
            if h is not None and me.m[0x186] >= cost and not (me.status & 0x80) and me.m[0x60] != 0xE0:
                cmd[0], cmd[1] = 0x44, a[0]
                me.m[0x170] = a[1]
                for off, v in ((0x177, 0), (0x178, (self.tgt2 + 1) & 0xFF), (0x179, 0), (0x17A, 0), (0x176, 1)):
                    me.m[off] = v
                fx.append(('cast', a[1], self.tgt2))
            else:
                cmd[:] = [0xC1, {0: 8, 1: 4, 2: 1}.get(w.facing, 2), 0, 5]
            done(); return 0
        if op == 0xFC:
            if (me.m[0x191] & 0xDF) == 0:
                me.m[0x1E3] = me.m[0x1E9]
                me.m[0x1E4] = (me.m[0x1E4] & 0x80) ^ 0x80
                sel_b = me.m[0x1E9] if me.m[0x1E4] else me.m[0x1E8]
                if not me.m[0x1E4]: me.m[0x1E3] = me.m[0x1E8]
                me.m[0x1E4] |= self.rom[0x101000 + 12 * sel_b]
                fx.append(('flash',))
            done(); return None
        # ---- ops added by the scripts of the monsters 0x20-0x53
        if op in UNDEF: return self.restart(w, cmd)          # e.g. 85: the handler table entry is the error handler $C1:0100
        if op == 0xEE:
            cmd[0] = 0x04; done(); return 0
        if op == 0xEA:
            # $C1:1E98, game bugs kept: the MP test is inverted (BCS), and the target loops never advance X, so they test slot 0 / slot 3
            # three times (slot 3 counts as self only when this monster is in slot 3); docs/monster-ai-opcodes.md section 2
            cost = self.rom[0x102ADF + a[1] * 0x40]
            face = {0: 8, 1: 4, 2: 1}.get(w.facing, 2)
            if not (me.m[0x186] >= cost or (me.m[0x60] != 0xE0 and not (me.m[0x190] & 0x80))):
                cmd[:] = [0xC1, face, 0, 5]; done(); return 0
            for off in range(0x176, 0x17B): me.m[off] = 0
            if self.tgt2 < 3: side, ok = 0, valid(w.obj(0), me)
            else:
                o3 = w.obj(3)
                side, ok = 3, valid(o3, me) and o3.m[0x180] < 0x80
            if not ok:
                cmd[:] = [0xC1, face, 0, 5]; done(); return 0
            for k in range(3): me.m[0x178 + k] = side + k + 1
            me.m[0x176] = 3
            cmd[0], cmd[1] = 0x44, a[0]
            me.m[0x170] = a[1]
            fx.append(('cast_all', a[1], [side, side + 1, side + 2]))
            done(); return 0
        # ---- ops of the hero AI script (entry 0x58EA, object ids 0x80-0x82)
        mthr = {0x32: 1, 0x4A: 2, 0x4F: 4}
        if op in mthr:                      # jump when no valid monster (slots 3-5, id < 0x80) is within the class
            self.jump_or_skip(ln, tgt, self.monster_within(w, mthr[op]) == 0xFF); return None
        msel = {0xA6: 1, 0xB2: 2, 0xB5: 4, 0xB8: 8}
        if op in msel: self.tgt = self.monster_within(w, msel[op]); done(); return None
        if op == 0xA0: self.tgt = 0xFF; done(); return None
        if op == 0x62:                      # jump when a valid monster exists and no pad-bound hero is farther than 96 px
            take = False
            if any(self.valid_monster(w, s) for s in (3, 4, 5)):
                take = True
                for k in range(3):
                    b = w.pads[k] & 7
                    if not b: continue
                    hs = b.bit_length() - 1
                    if dist_class(me, w.obj(hs)) & 0x20: take = False; break
            self.jump_or_skip(ln, tgt, take); return None
        if op == 0xF6:
            take = True
            if any(self.valid_monster(w, s) for s in (3, 4, 5)):
                for bits in w.pads[:3]:
                    binding = bits & 7
                    if binding and not dist_class(me, w.obj(binding.bit_length() - 1)) & 0x20:
                        take = False; break
            self.jump_or_skip(ln, tgt, take); return None
        if op == 0xE1: cmd[0] = 0x01; done(); return 0
        if op == 0xDF:
            done()
            if w.gauge != 0: return None
            me.m[0x14C] &= 0xFE; cmd[0] = 0x02; return 0
        if op == 0xF4:
            done()
            if not me.m[0x14C] & 1: return None
            me.m[0x14C] &= 0xFE; cmd[0] = 0x07; return 0
        if op == 0xF3:
            done()
            if w.ram.get(0xCC7D + w.slot, 0) == 0 or me.m[0x14C] & 1: return None
            me.m[0x14C] |= 1; cmd[0] = 0x06; return 0
        if op == 0xF2:                      # arg 0: jump when the charge setting $CC7D+slot is above the stage +0x19B; arg != 0: when it is not
            above = w.ram.get(0xCC7D + (w.slot & 3), 0) > me.m[0x19B]
            self.jump_or_skip(ln, tgt, above if a[0] == 0 else not above); return None
        raise VMError('op %02X not modelled' % op)

    def valid_monster(self, w, s):
        """$C1:058B: slot s is valid ($C1:054A) and holds a monster (id +0x180 < 0x80)"""
        o = w.obj(s)
        return valid(o, w.me) and o.m[0x180] < 0x80

    def monster_within(self, w, thr):
        """$C1:0AEC / 0C08 / 0C51 / 0C9A: first of the slots 3-5 that is a valid monster within distance class thr, else 0xFF"""
        for s in (3, 4, 5):
            if self.valid_monster(w, s) and dist_class(w.me, w.obj(s)) <= thr: return s
        return 0xFF
