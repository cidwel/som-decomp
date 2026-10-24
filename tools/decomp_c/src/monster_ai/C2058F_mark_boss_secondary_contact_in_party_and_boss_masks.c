#include "som_c.h"

/* C2058F mark_boss_secondary_contact_in_party_and_boss_masks   [class B, 48 bytes, 22 instructions]
 * Source: src/rom/mark_boss_secondary_contact_in_party_and_boss_masks.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void mark_boss_secondary_contact_in_party_and_boss_masks(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x0591, 0xC205BF); /* scan_three_party_collision_targets_for_boss */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool zero_ret = r->z;
    bool negative_ret = r->n;
    bool overflow_ret = r->v;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if (!carry_ret) {
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        y1 = y_ret;
        carry1 = carry_ret;
        zero1 = zero_ret;
        negative1 = negative_ret;
        overflow1 = overflow_ret;
    } else {
        uint16_t value = RAM16(0x028B);
        uint16_t value2 = RAM16(0x0224);
        uint8_t value3 = BUS8(c, 0xC205F0 + value);
        RAM8(0x0059 + (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000)) = value3 | RAM8(0x0059 + (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000));
        uint16_t value5 = RAM16(0x0224);
        uint16_t value6 = RAM16(0x0287);
        uint8_t value7 = BUS8(c, 0xC205F0 + value5);
        uint8_t value8 = RAM8(0x005A + value6);
        RAM8(0x005A + value6) = value7 | value8;
        uint16_t value9 = RAM16(0x0287);
        a1 = value7 | value8;
        a_hi1 = (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000) >> 8;
        x1 = value9;
        y1 = value6;
        carry1 = 1;
        zero1 = value9 == 0;
        negative1 = value9 & 0x8000;
        overflow1 = (((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2058F, SOM_RTS, "gen", mark_boss_secondary_contact_in_party_and_boss_masks, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 48, 22)
