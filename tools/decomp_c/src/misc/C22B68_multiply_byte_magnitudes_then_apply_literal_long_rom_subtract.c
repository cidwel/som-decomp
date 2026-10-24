#include "som_c.h"

/* C22B68 multiply_byte_magnitudes_then_apply_literal_long_rom_subtract   [class B, 44 bytes, 23 instructions]
 * Source: src/rom/multiply_byte_magnitudes_then_apply_literal_long_rom_subtract.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void multiply_byte_magnitudes_then_apply_literal_long_rom_subtract(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = BUS8_RDP(c, (uint16_t)(dp + 0x46));
    uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp + 0x4E));
    uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp + 0x46));
    bool carry1;
    bool overflow1;
    if (!(value3 & 0x80)) {
        carry1 = carry;
        overflow1 = overflow;
    } else {
        uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp + 0xC5));
        uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp + 0x46));
        BUS8_SET(c, (uint16_t)(dp + 0x46), (uint8_t)(value4 - value5));
        carry1 = value4 >= value5;
        overflow1 = ((value4 ^ value5) & (value4 ^ (uint8_t)(value4 - value5)) & 0x80) != 0;
    }
    uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp + 0x4E));
    bool carry2;
    bool overflow2;
    if (!(value6 & 0x80)) {
        carry2 = carry1;
        overflow2 = overflow1;
    } else {
        uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp + 0xC5));
        uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp + 0x4E));
        BUS8_SET(c, (uint16_t)(dp + 0x4E), (uint8_t)(value7 - value8));
        carry2 = value7 >= value8;
        overflow2 = ((value7 ^ value8) & (value7 ^ (uint8_t)(value7 - value8)) & 0x80) != 0;
    }
    r->c = carry2;
    r->v = overflow2;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2B87, 0xC22AA6); GUARD_JSR(c, sp_call, 0x2B87); } /* multiply_boss_terrain_row_stride */
    r->sp += 1;
    uint8_t a1;
    bool carry3;
    bool zero1;
    bool negative1;
    bool overflow3;
    if (!((value ^ value2) & 0x80)) {
        a1 = value ^ value2;
        carry3 = carry2;
        zero1 = (value ^ value2) == 0;
        negative1 = (value ^ value2) & 0x80;
        overflow3 = overflow2;
    } else {
        uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp + 0x56));
        uint8_t value10 = BUS8(c, 0x56851A + x);
        a1 = (uint8_t)((value9 ^ 0xFF) - value10 - (carry2 ^ 1));
        carry3 = (value9 ^ 0xFF) - value10 >= (carry2 ^ 1);
        zero1 = (uint8_t)((value9 ^ 0xFF) - value10 - (carry2 ^ 1)) == 0;
        negative1 = (uint8_t)((value9 ^ 0xFF) - value10 - (carry2 ^ 1)) & 0x80;
        overflow3 = ((value9 ^ 0xFF ^ value10) & (value9 ^ 0xFF ^ (uint8_t)((value9 ^ 0xFF) - value10 - (carry2 ^ 1))) & 0x80) != 0;
    }
    SET_A8(r, a1);
    r->c = carry3;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow3;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22B68, SOM_RTS, "gen", multiply_byte_magnitudes_then_apply_literal_long_rom_subtract, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 44, 23)
