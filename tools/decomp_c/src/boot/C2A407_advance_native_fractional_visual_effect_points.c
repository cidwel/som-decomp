#include "som_c.h"

/* C2A407 advance_native_fractional_visual_effect_points   [class B, 121 bytes, 60 instructions]
 * Source: src/rom/advance_native_fractional_visual_effect_points.s
 * Documented in docs/actor-visual-effect-motion.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void advance_native_fractional_visual_effect_points(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const bool overflow = r->v;
    uint16_t value = RAM16(0xC060 + (x >> 1));
    RAM16_SET(0x0008, value);
    uint8_t value2 = RAM8(0x0008);
    if (value2 != 0) {
        uint8_t a1 = value2;
        uint8_t a_hi1 = value >> 8;
        uint16_t x1 = x;
        uint16_t y1 = x >> 1;
        bool carry1 = x & 0x01;
        bool overflow1 = overflow;
        do {
            RAM8(0xE0D0 + x1) = (uint8_t)(RAM8(0xC000 + y1) + RAM8(0xE0D0 + x1));
            RAM8(0xE0D1 + x1) = (uint8_t)(RAM8(0xC001 + y1) + RAM8(0xE0D1 + x1));
            uint8_t value7 = RAM8(0xC002 + y1);
            uint8_t value8 = RAM8(0xC032 + y1);
            uint8_t value9 = RAM8(0x0009);
            if ((uint8_t)(value7 + value8) < value9) {
                RAM8(0xC002 + y1) = (uint8_t)(value7 + value8);
            } else {
                RAM8(0xC002 + y1) = (uint8_t)((uint8_t)(value7 + value8) - value9 - ((uint8_t)(value7 + value8) >= value9 ^ 1));
                if (RAM8(0xC030 + y1) & 0x80) {
                    RAM8(0xE0D0 + x1)--;
                } else {
                    RAM8(0xE0D0 + x1)++;
                }
            }
            uint8_t value11 = RAM8(0xC003 + y1);
            uint8_t value12 = RAM8(0xC033 + y1);
            uint8_t value13 = RAM8(0x0009);
            uint8_t a2;
            bool carry2;
            bool overflow2;
            if ((uint8_t)(value11 + value12) < value13) {
                RAM8(0xC003 + y1) = (uint8_t)(value11 + value12);
                a2 = (uint8_t)(value11 + value12);
                carry2 = (uint8_t)(value11 + value12) >= value13;
                overflow2 = ((value11 ^ (uint8_t)(value11 + value12)) & (value12 ^ (uint8_t)(value11 + value12)) & 0x80) != 0;
            } else {
                RAM8(0xC003 + y1) = (uint8_t)((uint8_t)(value11 + value12) - value13 - ((uint8_t)(value11 + value12) >= value13 ^ 1));
                uint8_t value14 = RAM8(0xC031 + y1);
                if (value14 & 0x80) {
                    RAM8(0xE0D1 + x1)--;
                } else {
                    RAM8(0xE0D1 + x1)++;
                }
                a2 = value14;
                carry2 = (uint8_t)(value11 + value12) - value13 >= ((uint8_t)(value11 + value12) >= value13 ^ 1);
                overflow2 = (((uint8_t)(value11 + value12) ^ value13) & ((uint8_t)(value11 + value12) ^ (uint8_t)((uint8_t)(value11 + value12) - value13 - ((uint8_t)(value11 + value12) >= value13 ^ 1))) & 0x80) != 0;
            }
            RAM8(0x0008)--;
            a1 = a2;
            x1 = (uint16_t)(x1 + 4);
            y1 = (uint16_t)(y1 + 4);
            carry1 = carry2;
            overflow1 = overflow2;
        } while (RAM8(0x0008) != 0);
        r->a = (a_hi1 << 8) | a1;
        r->x = x;
        r->y = y1;
        r->c = carry1;
        r->v = overflow1;
        RETURN_RTL(c);
    }
    r->a = (value >> 8 << 8) | value2;
    r->y = x >> 1;
    r->c = x & 0x01;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2A407, SOM_RTL, "gen", advance_native_fractional_visual_effect_points, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 121, 60)
