#include "som_c.h"

/* C273B7 advance_descriptor_seven_vertical_sine_around_saved_origin   [class B, 47 bytes, 20 instructions]
 * Source: src/rom/advance_descriptor_seven_vertical_sine_around_saved_origin.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void advance_descriptor_seven_vertical_sine_around_saved_origin(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0358);
    r->a = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    { const uint16_t sp_call = r->sp; JSR(c, 0x73BC, 0xC22A60); GUARD_JSR(c, sp_call, 0x73BC); } /* mask_angle_and_derive_native_sine */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    BUS16_SET(c, (uint16_t)(dp_ret + 0x46), a_all);
    BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), 0x20);
    r->a = 0x20;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x73C6, 0xC22B94); GUARD_JSR(c, sp_call, 0x73C6); } /* multiply_signed_words_to_double_word */
    bool x_ret3 = r->xf;
    if (x_ret3) {
        uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
        uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
        uint16_t value4 = BUS16_RDP(c, (db_ret << 0x10) + 0x035C);
        uint16_t value5 = BUS16_RDP(c, (db_ret << 0x10) + 0x32 + value2);
        BUS16_SET(c, (db_ret << 0x10) + 0x40 + value2, (uint16_t)((uint16_t)(value3 + value4) - value5));
        uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp_ret + 0xC5));
        r->a = value6;
        r->x = value2;
        r->y = (uint8_t)y;
        r->c = (uint16_t)(value3 + value4) >= value5;
        r->z = value6 == 0;
        r->n = value6 & 0x8000;
        r->v = (((uint16_t)(value3 + value4) ^ value5) & ((uint16_t)(value3 + value4) ^ (uint16_t)((uint16_t)(value3 + value4) - value5)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x73DA, 0xC20A47); GUARD_JSR(c, sp_call, 0x73DA); } /* move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding */
        uint16_t value7 = BUS16_RDP(c, (db_ret << 0x10) + 0x0358);
        BUS16_SET(c, (db_ret << 0x10) + 0x0358, (uint16_t)(value7 + 0x20));
        r->a = (uint16_t)(value7 + 0x20);
        r->c = value7 + 0x20 > 0xFFFF;
        r->z = (uint16_t)(value7 + 0x20) == 0;
        r->n = (uint16_t)(value7 + 0x20) & 0x8000;
        r->v = ((value7 ^ (uint16_t)(value7 + 0x20)) & ((uint16_t)(value7 + 0x20) ^ 0x20) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 1;
        RETURN_RTS(c);
    } else {
        uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
        uint16_t value9 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
        uint16_t value10 = BUS16_RDP(c, (db_ret << 0x10) + 0x035C);
        uint16_t value11 = BUS16_RDP(c, (db_ret << 0x10) + 0x32 + value8);
        BUS16_SET(c, (db_ret << 0x10) + 0x40 + value8, (uint16_t)((uint16_t)(value9 + value10) - value11));
        uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp_ret + 0xC5));
        r->a = value12;
        r->x = value8;
        r->c = (uint16_t)(value9 + value10) >= value11;
        r->z = value12 == 0;
        r->n = value12 & 0x8000;
        r->v = (((uint16_t)(value9 + value10) ^ value11) & ((uint16_t)(value9 + value10) ^ (uint16_t)((uint16_t)(value9 + value10) - value11)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x73DA, 0xC20A47); GUARD_JSR(c, sp_call, 0x73DA); } /* move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding */
        uint16_t value13 = BUS16_RDP(c, (db_ret << 0x10) + 0x0358);
        BUS16_SET(c, (db_ret << 0x10) + 0x0358, (uint16_t)(value13 + 0x20));
        r->a = (uint16_t)(value13 + 0x20);
        r->c = value13 + 0x20 > 0xFFFF;
        r->z = (uint16_t)(value13 + 0x20) == 0;
        r->n = (uint16_t)(value13 + 0x20) & 0x8000;
        r->v = ((value13 ^ (uint16_t)(value13 + 0x20)) & ((uint16_t)(value13 + 0x20) ^ 0x20) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC273B7, SOM_RTS, "gen", advance_descriptor_seven_vertical_sine_around_saved_origin, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 47, 20)
