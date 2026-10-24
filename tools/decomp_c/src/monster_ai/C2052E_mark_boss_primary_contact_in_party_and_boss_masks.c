#include "som_c.h"

/* C2052E mark_boss_primary_contact_in_party_and_boss_masks   [class B, 48 bytes, 22 instructions]
 * Source: src/rom/mark_boss_primary_contact_in_party_and_boss_masks.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void mark_boss_primary_contact_in_party_and_boss_masks(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint8_t a_055d = 0;
    uint8_t a_hi_055d = 0;
    uint8_t x_055d = 0;
    uint8_t y_055d = 0;
    bool carry_055d = 0;
    bool zero_055d = 0;
    bool negative_055d = 0;
    bool overflow_055d = 0;
    uint8_t a_055d2 = 0;
    uint8_t a_hi_055d2 = 0;
    uint16_t x_055d2 = 0;
    uint16_t y_055d2 = 0;
    bool carry_055d2 = 0;
    bool zero_055d2 = 0;
    bool negative_055d2 = 0;
    bool overflow_055d2 = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0530, 0xC2055E); GUARD_JSR(c, sp_call, 0x0530); } /* scan_party_primary_shapes_against_two_boss_boxes */
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool zero_ret = r->z;
    bool negative_ret = r->n;
    bool overflow_ret = r->v;
    if (!carry_ret) {
        if (x_ret) {
            a_055d = (uint8_t)a_all;
            a_hi_055d = a_all >> 8;
            x_055d = (uint8_t)x_ret2;
            y_055d = (uint8_t)y_ret;
            carry_055d = carry_ret;
            zero_055d = zero_ret;
            negative_055d = negative_ret;
            overflow_055d = overflow_ret;
            goto shared_055D;
        } else {
            a_055d2 = (uint8_t)a_all;
            a_hi_055d2 = a_all >> 8;
            x_055d2 = x_ret2;
            y_055d2 = y_ret;
            carry_055d2 = carry_ret;
            zero_055d2 = zero_ret;
            negative_055d2 = negative_ret;
            overflow_055d2 = overflow_ret;
            goto shared_055D_1;
        }
    }
    if (x_ret) {
        uint8_t value = RAM8(0x028B);
        uint16_t value2 = RAM16(0x0224);
        uint8_t value3 = BUS8(c, 0xC205F0 + value);
        RAM8(0x005A + (uint8_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000)) = value3 | RAM8(0x005A + (uint8_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000));
        uint8_t value5 = RAM8(0x0224);
        uint8_t value6 = RAM8(0x0287);
        uint8_t value7 = BUS8(c, 0xC205F0 + value5);
        uint8_t value8 = RAM8(0x0059 + value6);
        RAM8(0x0059 + value6) = value7 | value8;
        uint8_t value9 = RAM8(0x0287);
        a_055d = value7 | value8;
        a_hi_055d = (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000) >> 8;
        x_055d = value9;
        y_055d = value6;
        carry_055d = 1;
        zero_055d = value9 == 0;
        negative_055d = value9 & 0x80;
        overflow_055d = (((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        goto shared_055D;
    } else {
        uint16_t value10 = RAM16(0x028B);
        uint16_t value11 = RAM16(0x0224);
        uint8_t value12 = BUS8(c, 0xC205F0 + value10);
        RAM8(0x005A + (uint16_t)((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) + 0xE000)) = value12 | RAM8(0x005A + (uint16_t)((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) + 0xE000));
        uint16_t value14 = RAM16(0x0224);
        uint16_t value15 = RAM16(0x0287);
        uint8_t value16 = BUS8(c, 0xC205F0 + value14);
        uint8_t value17 = RAM8(0x0059 + value15);
        RAM8(0x0059 + value15) = value16 | value17;
        uint16_t value18 = RAM16(0x0287);
        a_055d2 = value16 | value17;
        a_hi_055d2 = (uint16_t)((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) + 0xE000) >> 8;
        x_055d2 = value18;
        y_055d2 = value15;
        carry_055d2 = 1;
        zero_055d2 = value18 == 0;
        negative_055d2 = value18 & 0x8000;
        overflow_055d2 = (((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value11 << 8) | (value11 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        goto shared_055D_1;
    }
    shared_055D:;
    r->a = (a_hi_055d << 8) | a_055d;
    r->x = x_055d;
    r->y = y_055d;
    r->c = carry_055d;
    r->z = zero_055d;
    r->n = negative_055d;
    r->v = overflow_055d;
    r->mf = 0;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0x0200;
    RETURN_RTS(c);
    shared_055D_1:;
    r->a = (a_hi_055d2 << 8) | a_055d2;
    r->x = x_055d2;
    r->y = y_055d2;
    r->c = carry_055d2;
    r->z = zero_055d2;
    r->n = negative_055d2;
    r->v = overflow_055d2;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2052E, SOM_RTS, "gen", mark_boss_primary_contact_in_party_and_boss_masks, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 48, 22)
