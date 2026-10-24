#include "som_c.h"

/* C28CFB advance_descriptor_eleven_sine_height_with_fractional_carry   [class B, 46 bytes, 19 instructions]
 * Source: src/rom/advance_descriptor_eleven_sine_height_with_fractional_carry.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXY.
 */
static void advance_descriptor_eleven_sine_height_with_fractional_carry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x035C);
    RAM16_SET(0x035C, (uint16_t)(value + 8));
    r->a = (uint16_t)(value + 8);
    r->c = value + 8 > 0xFFFF;
    r->z = (uint16_t)(value + 8) == 0;
    r->n = (uint16_t)(value + 8) & 0x8000;
    r->v = ((value ^ (uint16_t)(value + 8)) & ((uint16_t)(value + 8) ^ 8) & 0x8000) != 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8D07, 0xC22A60); GUARD_JSR(c, sp_call, 0x8D07); } /* mask_angle_and_derive_native_sine */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    BUS16_SET(c, (uint16_t)(dp_ret + 0x46), a_all);
    BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), 0x10);
    r->a = 0x10;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8D11, 0xC22B94); GUARD_JSR(c, sp_call, 0x8D11); } /* multiply_signed_words_to_double_word */
    bool x_ret3 = r->xf;
    if (x_ret3) {
        uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
        uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x55));
        uint16_t value4 = BUS16_RDP(c, (db_ret << 0x10) + 0x0358);
        BUS16_SET(c, (db_ret << 0x10) + 0x64 + value2, (uint16_t)((value3 & 0xFF00) + value4));
        uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
        uint16_t value6 = BUS16_RDP(c, (db_ret << 0x10) + 0x035A);
        BUS16_SET(c, (db_ret << 0x10) + 0x66 + value2, (uint16_t)(value5 + value6 + ((value3 & 0xFF00) + value4 > 0xFFFF)));
        r->a = (uint16_t)(value5 + value6 + ((value3 & 0xFF00) + value4 > 0xFFFF));
        r->x = value2;
        r->y = (uint8_t)y;
        r->mf = 0;
        r->xf = 1;
        RETURN_RTS(c);
    } else {
        uint16_t value7 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
        uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x55));
        uint16_t value9 = BUS16_RDP(c, (db_ret << 0x10) + 0x0358);
        BUS16_SET(c, (db_ret << 0x10) + 0x64 + value7, (uint16_t)((value8 & 0xFF00) + value9));
        uint16_t value10 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
        uint16_t value11 = BUS16_RDP(c, (db_ret << 0x10) + 0x035A);
        BUS16_SET(c, (db_ret << 0x10) + 0x66 + value7, (uint16_t)(value10 + value11 + ((value8 & 0xFF00) + value9 > 0xFFFF)));
        r->a = (uint16_t)(value10 + value11 + ((value8 & 0xFF00) + value9 > 0xFFFF));
        r->x = value7;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC28CFB, SOM_RTS, "gen", advance_descriptor_eleven_sine_height_with_fractional_carry, 0, L_B | L_X | L_Y, 1, 0, 0, 46, 19)
