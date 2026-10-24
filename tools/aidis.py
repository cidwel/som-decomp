"""AI bytecode lister. usage: aidis.py ROM HEXPC [HEXLEN] [--text]   (PC relative to ROM 0x104F15)
Lengths verified by reading handler code ($C1:2257 table) and by running handlers in cpu65816. With --text the opcodes whose handlers were
executed by tools/ai_ops.py (the ones the Rabite, Chobin Hood and Polter Chair scripts use) get a one-line description; the others are printed as opNN.
Conditional ops are written IFxx args -> target: the jump is taken when the condition described for the op holds."""
import sys, romio
BASE = 0x104F15
N0 = set([0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x31,0x32,0x33,0x34,0x35,0x37,0x38,0x39,0x3A,0x3B,0x3D,0x3E,0x3F,0x40,0x41,0x43,0x44,0x45,0x46,0x47,
          0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A,0x5B,0x5C,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6A,0x6B,
          0x6C,0x6D,0x6E,0x6F,0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7A,0x7B,0x7C,0x9D,0x9E,0xD6,0xF6,0x01])
N1 = set(list(range(0x0A,0x1A)) + [0x36,0x3C,0x42,0x48,0x5F,0x60,0xF5,0xF2])
N3 = set([0x2D,0x2E,0x2F,0x30])
N4 = set([0xBA,0xBB,0xBC,0xBD])
FIX = {}
for o in list(range(0x1A,0x25))+[0x5D,0x5E,0x61,0x9F,0xFB,0xFC,0xF3,0xF4,0xDF,0xE1,0xE8,0xEC,0xEE,0x00]+list(range(0xA0,0xBA))+[o for o in range(0xC0,0xD9) if o != 0xD6]: FIX[o]=1
for o in range(0x25,0x2D): FIX[o]=2
for o in (0xE2,0xED,0xF0,0xF1,0xF9,0xFA): FIX[o]=2
for o in (0xE3,0xE4,0xE5,0xE6,0xE7,0xE9,0xEA,0xEB,0xEF,0xF7,0xFD,0xFE,0xBE,0xBF,0xFF): FIX[o]=3
for o in (0xDA,0xDB,0xDC,0xE0): FIX[o]=4
# ops whose handler table entry ($C1:2257) is the error handler $C1:0100: the script restarts at entry + 3
UNDEF = set(list(range(0x7D, 0x9D)) + [0xA2, 0xA3, 0xC2, 0xC3, 0xD9, 0xDD, 0xDE, 0xF8])
def decode(d, pc):
    """returns (length, text, target_or_None, falls_through)"""
    op = d[BASE+pc]; b = d[BASE+pc+1:BASE+pc+8]
    if op in UNDEF: return 1, 'op%02X ??? (undefined: error handler)' % op, None, False
    if op in FIX:
        n = FIX[op]
        args = ' '.join('%02X'%x for x in d[BASE+pc+1:BASE+pc+n])
        if op == 0xFF: return n, 'CALL %04X' % (b[0]<<8|b[1]), b[0]<<8|b[1], True
        if op == 0x00: return n, 'RET', None, False
        return n, 'op%02X %s' % (op, args), None, True
    n = 0 if op in N0 else 1 if op in N1 else 3 if op in N3 else 4 if op in N4 else None
    if n is None: return 1, 'op%02X ???' % op, None, True
    off = BASE+pc+1+n
    fb = d[off]
    if fb & 0x80:
        ol = 1; v = fb & 0x7F
        if v & 0x40: v -= 0x80
    else:
        ol = 2; v = ((fb<<8)|d[off+1])
        if v & 0x4000: v |= 0x8000
        if v & 0x8000: v -= 0x10000
    ln = 1+n+ol
    tgt = (pc+ln+v) & 0xFFFF
    args = ' '.join('%02X'%x for x in d[BASE+pc+1:BASE+pc+1+n])
    kind = 'JMP' if op==1 else 'IF%02X' % op
    return ln, '%s %s-> %04X' % (kind, args+' ' if args else '', tgt), tgt, op != 1
# op -> (mnemonic, kind, description); kind: flow, branch (conditional jump), var, target, field, pos, cmd
INFO = {}
def _i(op, name, kind, desc): INFO[op] = (name, kind, desc)
_i(0x00, 'ret', 'flow', 'return: pops the address pushed by CALL; at depth 0 the error handler restarts the script at entry+3')
_i(0x01, 'jmp', 'flow', 'jump')
_i(0xFF, 'call', 'flow', 'call the 16-bit big-endian address; pushes pc+3; the error handler runs when the depth would reach 16')
for _k in range(4):
    _i(0x02 + _k, 'if_var%d_nz' % _k, 'branch', 'jump if var%d != 0' % _k)
    _i(0x06 + _k, 'if_var%d_z' % _k, 'branch', 'jump if var%d == 0' % _k)
    _i(0x0A + _k, 'if_var%d_ne' % _k, 'branch', 'jump if var%d != arg' % _k)
    _i(0x0E + _k, 'if_var%d_eq' % _k, 'branch', 'jump if var%d == arg' % _k)
    _i(0x12 + _k, 'if_var%d_gt' % _k, 'branch', 'jump if var%d > arg' % _k)
    _i(0x16 + _k, 'if_var%d_lt' % _k, 'branch', 'jump if var%d < arg' % _k)
    _i(0x1A + _k, 'inc_var%d' % _k, 'var', 'var%d = (var%d + 1) & 15' % (_k, _k))
    _i(0x1E + _k, 'dec_var%d' % _k, 'var', 'var%d = (var%d - 1) & 15' % (_k, _k))
    _i(0x25 + _k, 'set_var%d' % _k, 'var', 'var%d = arg & 15' % _k)
    _i(0x29 + _k, 'rnd_var%d' % _k, 'var', 'var%d = random 0..(arg & 15), inclusive, uniform (no draw when 0; rejection sampling of the low nibble of the RNG byte)' % _k)
for _k in (1, 2, 3): _i(0x21 + _k, 'var%d_eq_var0' % _k, 'var', 'var%d = var0' % _k)
_i(0x2D, 'if_field_and_nz', 'branch', 'jump if byte(objref arg1, offset arg2 + 0x180) & arg3 != 0')
_i(0x2E, 'if_field_and_z', 'branch', 'jump if byte(objref arg1, offset arg2 + 0x180) & arg3 == 0')
_i(0x2F, 'if_field_lt', 'branch', 'jump if byte(objref arg1, offset arg2 + 0x180) < arg3')
_i(0x30, 'if_field_gt', 'branch', 'jump if byte(objref arg1, offset arg2 + 0x180) > arg3')
_i(0xBA, 'if_word_and_nz', 'branch', 'jump if word(objref arg1, offset arg2 + 0x180) & word(arg3, arg4) != 0')
_i(0xBB, 'if_word_and_z', 'branch', 'jump if word(objref arg1, offset arg2 + 0x180) & word(arg3, arg4) == 0')
_i(0xBC, 'if_word_lt', 'branch', 'jump if word(objref arg1, offset arg2 + 0x180) < word(arg3, arg4)')
_i(0xBD, 'if_word_gt', 'branch', 'jump if word(objref arg1, offset arg2 + 0x180) > word(arg3, arg4)')
_i(0xDA, 'field_or', 'field', 'byte(objref arg1, offset arg2 + 0x180) |= arg3')
_i(0xDB, 'field_and', 'field', 'byte(objref arg1, offset arg2 + 0x180) &= arg3')
_i(0xDC, 'field_set', 'field', 'byte(objref arg1, offset arg2 + 0x180) = arg3')
for _op, _px in ((0x31, 16), (0x49, 32), (0x4E, 48), (0x53, 64)): _i(_op, 'if_no_hero_%d' % _px, 'branch', 'jump if no valid hero is within %d px' % _px)
_i(0x58, 'if_no_hero_onscreen', 'branch', 'jump if no valid hero is on screen')
for _op, _px in ((0x34, 16), (0x4C, 32), (0x51, 48), (0x56, 64)): _i(_op, 'if_tgt_not_within_%d' % _px, 'branch', 'jump unless the current target is on screen and within %d px' % _px)
_i(0x46, 'if_tgt_not_band_64', 'branch', 'jump unless the current target is on screen and in distance class 8 (49-64 px, or a coordinate offset of 256 or more)')
_i(0x5A, 'if_tgt_not_beyond_64', 'branch', 'jump unless the current target is on screen and farther than 64 px (distance class 0x10 or 0x30)')
for _op, _nm, _d in ((0x66, 'v64', 'vertical lane (|dx| < 16, vertical major axis), within 64 px'), (0x68, 'v48', 'vertical lane, within 48 px'), (0x6A, 'v', 'vertical lane, any distance'),
                     (0x6F, 'h64', 'horizontal lane (|dy| < 16, horizontal major axis), within 64 px'), (0x71, 'h48', 'horizontal lane, within 48 px'), (0x73, 'h', 'horizontal lane, any distance')):
    _i(_op, 'if_tgt_not_lane_' + _nm, 'branch', 'jump unless the current target is on screen in the ' + _d)
_i(0x77, 'if_tgt_not_below', 'branch', 'jump unless the current target is on screen, below and the vertical axis is the major one')
_i(0x79, 'if_tgt_not_left', 'branch', 'jump unless the current target is on screen, to the left and the horizontal axis is the major one')
_i(0x75, 'if_tgt_not_above', 'branch', 'jump unless the current target is on screen, above and the vertical axis is the major one')
_i(0x7B, 'if_tgt_not_right', 'branch', 'jump unless the current target is on screen, to the right and the horizontal axis is the major one')
_i(0x5F, 'if_obj_outside', 'branch', 'jump if object ref arg1 is outside the box 8 <= x <= 248, 8 <= y-h <= 216')
_i(0x60, 'if_obj_inside', 'branch', 'jump if object ref arg1 is inside the box 8 <= x <= 248, 8 <= y-h <= 216')
_i(0x54, 'if_no_ally_64', 'branch', 'jump if none of the other monster slots 3-5 holds a valid ordinary monster (id < 0x80) within 64 px')
_i(0xD8, 'tgt2_ally', 'target', 'second target = first such other monster (FF if none)')
_i(0x32, 'if_no_monster_16', 'branch', 'hero AI: jump if no valid monster (slots 3-5, id < 0x80) is within 16 px')
_i(0x4A, 'if_no_monster_32', 'branch', 'hero AI: jump if no valid monster is within 32 px')
_i(0x4F, 'if_no_monster_48', 'branch', 'hero AI: jump if no valid monster is within 48 px')
_i(0x62, 'if_fight', 'branch', 'hero AI: jump if a valid monster exists and no pad-bound hero ($D9-$DB) is farther than 96 px')
_i(0xA0, 'tgt_none', 'target', 'current target = FF')
_i(0xA6, 'tgt_monster_16', 'target', 'hero AI: current target = first valid monster (slots 3-5) within 16 px, FF if none')
_i(0xB2, 'tgt_monster_32', 'target', 'hero AI: current target = first valid monster within 32 px')
_i(0xB5, 'tgt_monster_48', 'target', 'hero AI: current target = first valid monster within 48 px')
_i(0xB8, 'tgt_monster_64', 'target', 'hero AI: current target = first valid monster within 64 px')
_i(0xDF, 'swing_plain', 'cmd', 'hero AI: gauge +0x1ED == 0: clear flag +0x14C bit 0, command 02 (swing), yield; else continue')
_i(0xE1, 'follow', 'cmd', 'hero AI: command 01 (follow the party), yield')
_i(0xF2, 'if_charge_set', 'branch', 'hero AI: arg 0: jump if the charge setting $CC7D + slot is above the stage +0x19B; arg != 0: jump if it is not')
_i(0xF3, 'charge_start', 'cmd', 'hero AI: charge setting $CC7D + slot != 0 and flag +0x14C bit 0 clear: set the flag, command 06 (hold the attack button), yield; else continue')
_i(0xF4, 'charge_release', 'cmd', 'hero AI: flag +0x14C bit 0 set: clear it, command 07 (release the attack button), yield; else continue')
_i(0xF5, 'if_crowd_gt', 'branch', 'jump if more than arg of the monster slots 3-5 (this one included) are active and on screen')
for _op, _px in ((0xA5, 16), (0xB1, 32), (0xB4, 48), (0xB7, 64)): _i(_op, 'tgt_within_%d' % _px, 'target', 'current target = first valid hero within %d px (FF if none)' % _px)
_i(0x5D, 'tgt_far', 'target', 'current target = first valid hero farther than 64 px (FF if none)')
_i(0xC0, 'tgt2_none', 'target', 'second target = FF')
_i(0xC1, 'tgt2_cur', 'target', 'second target = current target')
_i(0xC4, 'tgt2_self', 'target', 'second target = own slot')
_i(0x9F, 'pos_save', 'pos', 'save the own screen position (x, y - h)')
_i(0x9D, 'if_pos_same', 'branch', 'jump if the own screen position equals the saved one')
_i(0x9E, 'if_pos_moved', 'branch', 'jump if the own screen position differs from the saved one')
_i(0xE0, 'hop', 'cmd', 'command C1, direction code arg1, animation arg2, flag arg3; yield')
_i(0xE2, 'pose', 'cmd', 'command 40, animation arg1; yield')
_i(0xE3, 'turn_facing', 'cmd', 'command C1 in the current facing direction when the actor is not moving (else from the velocity bytes), animation arg1, flag arg2; yield')
_i(0xE4, 'move_toward', 'cmd', 'if the current target is on screen: command C1 toward it (primary direction), animation arg1, flag arg2; yield (otherwise continue)')
_i(0xE5, 'move_toward2', 'cmd', 'as E4 with the second target')
_i(0xE6, 'move_away', 'cmd', 'if the current target is on screen: command C1 away from it (primary direction), animation arg1, flag arg2; yield')
_i(0xE7, 'move_away2', 'cmd', 'as E6 with the second target')
_i(0xFD, 'move_toward_alt', 'cmd', 'as E4 with the alternate direction (always a diagonal code)')
_i(0xFE, 'move_away_alt', 'cmd', 'as E6 with the alternate direction')
_i(0xBE, 'move_toward_card', 'cmd', 'as E4 with the cardinal code (horizontal when |dx| >= |dy|)')
_i(0xBF, 'move_away_card', 'cmd', 'as E6 with the cardinal code')
_i(0xE8, 'swing', 'cmd', 'if the cooldown gauge obj+0x1ED is 0: obj+0x19B = obj+0x1C0, command 02; yield (otherwise continue)')
_i(0xED, 'cmd43', 'cmd', 'command 43 with argument arg1; yield')
_i(0xEF, 'cmd81', 'cmd', 'command 81 with arguments arg1, arg2; yield')
_i(0xE9, 'cast', 'cmd', 'cast attack/spell arg2 with animation arg1 on the second target if it is on screen, MP obj+0x186 >= cost of attack arg2, not confused and obj+0x60 != E0: command 44, calls $C0:001B; else command C1 in the facing direction, animation 0, flag 5; yield')
_i(0xEA, 'cast_all', 'cmd', 'cast attack/spell arg2 with animation arg1 on a whole side: MP obj+0x186 >= cost, or obj+0x60 != E0 and not confused; second target < 3: slots 0-2 when hero 0 is valid, else slots 3-5 when slot 3 holds a valid monster that is not this one; command 44 (targets +1 in obj+0x178..0x17A, count in obj+0x176), calls $C0:001B; else command C1 in the facing direction, animation 0, flag 5; yield')
_i(0xEE, 'cmd04', 'cmd', 'command 04; yield')
for _op in sorted(UNDEF): _i(_op, 'undefined', 'flow', 'undefined op: the handler is the error handler $C1:0100 (script restarts at entry + 3)')
_i(0xFC, 'flash', 'cmd', 'toggle the palette flash bytes obj+0x1E3 / 0x1E4 and call $C0:003C (only when obj+0x191 & 0xDF == 0); continue')
DESC = {op: v[2] for op, v in INFO.items()}
def listing(d, pc, n, text=False):
    p = pc; out = []
    while p < pc+n:
        ln, t, tg, _ = decode(d, p)
        raw = ' '.join('%02X'%x for x in d[BASE+p:BASE+p+ln])
        extra = ('   ; ' + DESC[d[BASE+p]]) if text and d[BASE+p] in DESC else ''
        out.append('%04X: %-18s %s%s' % (p, raw, t, extra)); p += ln
    return '\n'.join(out)
if __name__ == '__main__':
    d = romio.rom_from_argv()
    text = '--text' in sys.argv
    a = [x for x in sys.argv[1:] if not x.startswith('--')]
    print(listing(d, int(a[0],16), int(a[1],16) if len(a)>1 else 0x40, text))
