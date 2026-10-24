#include "som_c.h"

/* C2396D prepare_boss_spell_targets   [class B, 212 bytes, 100 instructions]
 * Source: src/rom/prepare_boss_spell_targets.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void prepare_boss_spell_targets(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM16_SET(0x0295, a);
    RAM8(0x0170 + x) = RAM8(0x0295);
    RAM8(0x0177 + x) = 0;
    RAM8(0x0178 + x) = 0;
    RAM8(0x0179 + x) = 0;
    RAM8(0x017A + x) = 0;
    uint8_t value2 = RAM8(0x0296);
    if ((value2 & 2) != 0) {
        uint8_t a1;
        uint8_t a_hi4;
        uint16_t x4;
        uint16_t y2;
        bool carry2;
        bool zero1;
        bool negative1;
        bool overflow4;
        if ((value2 & 1) != 0) {
            RAM16_SET(0x0224, 0);
            RAM16_SET(0x0226, 0);
            uint8_t a_hi1 = a >> 8;
            uint16_t x1 = x;
            uint16_t y1 = y;
            bool carry1 = carry;
            bool overflow1 = overflow;
            for (;;) {
                uint16_t value3 = RAM16(0x0226);
                uint16_t value4 = RAM16(0x0000 + (uint16_t)((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE600 + ((((uint8_t)value3 << 8) | (value3 >> 8)) >> 0x0F)));
                uint8_t a_hi3;
                uint16_t x3;
                bool overflow3;
                if ((value4 & 0xFF) != 1) {
                    a_hi3 = 0;
                    x3 = x1;
                    overflow3 = (((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE600 + ((((uint8_t)value3 << 8) | (value3 >> 8)) >> 0x0F))) & ((uint16_t)((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE600 + ((((uint8_t)value3 << 8) | (value3 >> 8)) >> 0x0F)) ^ 0xE600) & 0x8000) != 0;
                } else {
                    uint16_t value5 = RAM16(0x0190 + (uint16_t)((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE600 + ((((uint8_t)value3 << 8) | (value3 >> 8)) >> 0x0F)));
                    uint8_t a_hi2;
                    uint16_t x2;
                    bool overflow2;
                    if ((value5 & 0x8000) != 0) {
                        a_hi2 = value5 >> 8;
                        x2 = x1;
                        overflow2 = (((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE600 + ((((uint8_t)value3 << 8) | (value3 >> 8)) >> 0x0F))) & ((uint16_t)((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE600 + ((((uint8_t)value3 << 8) | (value3 >> 8)) >> 0x0F)) ^ 0xE600) & 0x8000) != 0;
                    } else {
                        uint16_t value6 = RAM16(0x0287);
                        uint16_t value7 = RAM16(0x0224);
                        uint8_t value8 = RAM8(0x0226);
                        RAM8(0x0178 + (uint16_t)(value6 + value7)) = (uint8_t)(value8 + 4);
                        RAM16_SET(0x0224, (uint16_t)(RAM16(0x0224) + 1));
                        uint16_t value9 = RAM16(0x0287);
                        a_hi2 = (uint16_t)(value6 + value7) >> 8;
                        x2 = value9;
                        overflow2 = ((value8 ^ (uint8_t)(value8 + 4)) & ((uint8_t)(value8 + 4) ^ 4) & 0x80) != 0;
                    }
                    a_hi3 = a_hi2;
                    x3 = x2;
                    overflow3 = overflow2;
                }
                RAM16_SET(0x0226, (uint16_t)(RAM16(0x0226) + 1));
                uint16_t value10 = RAM16(0x0226);
                a_hi1 = value10 >> 8;
                x1 = x3;
                y1 = (uint16_t)((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE600 + ((((uint8_t)value3 << 8) | (value3 >> 8)) >> 0x0F));
                carry1 = value10 >= 3;
                overflow1 = overflow3;
                if (!(value10 < 3)) break;
            }
            uint8_t value11 = RAM8(0x0224);
            RAM8(0x0176 + x1) = value11;
            a1 = value11;
            a_hi4 = a_hi1;
            x4 = x1;
            y2 = y1;
            carry2 = carry1;
            zero1 = value11 == 0;
            negative1 = value11 & 0x80;
            overflow4 = overflow1;
        } else {
            RAM8(0x0176 + x) = 1;
            uint8_t value12 = RAM8(0x028B);
            RAM8(0x0178 + x) = (uint8_t)(value12 + 4);
            a1 = (uint8_t)(value12 + 4);
            a_hi4 = a >> 8;
            x4 = x;
            y2 = y;
            carry2 = value12 + 4 > 0xFF;
            zero1 = (uint8_t)(value12 + 4) == 0;
            negative1 = (uint8_t)(value12 + 4) & 0x80;
            overflow4 = ((value12 ^ (uint8_t)(value12 + 4)) & ((uint8_t)(value12 + 4) ^ 4) & 0x80) != 0;
        }
        r->a = (a_hi4 << 8) | a1;
        r->x = x4;
        r->y = y2;
        r->c = carry2;
        r->z = zero1;
        r->n = negative1;
        r->v = overflow4;
        RETURN_RTS(c);
    }
    if ((value2 & 1) != 0) {
        RAM16_SET(0x0224, 0);
        RAM16_SET(0x0226, 0);
        uint8_t a_hi5 = a >> 8;
        uint16_t x5 = x;
        uint16_t y3 = y;
        bool carry3 = carry;
        bool overflow5 = overflow;
        for (;;) {
            uint16_t value13 = RAM16(0x0226);
            uint16_t value14 = RAM16(0x0000 + (uint16_t)((uint16_t)((((uint8_t)value13 << 8) | (value13 >> 8)) << 1) + 0xE000 + ((((uint8_t)value13 << 8) | (value13 >> 8)) >> 0x0F)));
            uint8_t a_hi7;
            uint16_t x7;
            bool overflow7;
            if ((value14 & 0xFF) != 1) {
                a_hi7 = 0;
                x7 = x5;
                overflow7 = (((uint16_t)((((uint8_t)value13 << 8) | (value13 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value13 << 8) | (value13 >> 8)) << 1) + 0xE000 + ((((uint8_t)value13 << 8) | (value13 >> 8)) >> 0x0F))) & ((uint16_t)((uint16_t)((((uint8_t)value13 << 8) | (value13 >> 8)) << 1) + 0xE000 + ((((uint8_t)value13 << 8) | (value13 >> 8)) >> 0x0F)) ^ 0xE000) & 0x8000) != 0;
            } else {
                uint16_t value15 = RAM16(0x0190 + (uint16_t)((uint16_t)((((uint8_t)value13 << 8) | (value13 >> 8)) << 1) + 0xE000 + ((((uint8_t)value13 << 8) | (value13 >> 8)) >> 0x0F)));
                uint8_t a_hi6;
                uint16_t x6;
                bool overflow6;
                if ((value15 & 0x8000) != 0) {
                    a_hi6 = value15 >> 8;
                    x6 = x5;
                    overflow6 = (((uint16_t)((((uint8_t)value13 << 8) | (value13 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value13 << 8) | (value13 >> 8)) << 1) + 0xE000 + ((((uint8_t)value13 << 8) | (value13 >> 8)) >> 0x0F))) & ((uint16_t)((uint16_t)((((uint8_t)value13 << 8) | (value13 >> 8)) << 1) + 0xE000 + ((((uint8_t)value13 << 8) | (value13 >> 8)) >> 0x0F)) ^ 0xE000) & 0x8000) != 0;
                } else {
                    uint16_t value16 = RAM16(0x0287);
                    uint16_t value17 = RAM16(0x0224);
                    RAM8(0x0178 + (uint16_t)(value16 + value17)) = (uint8_t)(RAM8(0x0226) + 1);
                    RAM16_SET(0x0224, (uint16_t)(RAM16(0x0224) + 1));
                    uint16_t value19 = RAM16(0x0287);
                    a_hi6 = (uint16_t)(value16 + value17) >> 8;
                    x6 = value19;
                    overflow6 = ((value16 ^ (uint16_t)(value16 + value17)) & (value17 ^ (uint16_t)(value16 + value17)) & 0x8000) != 0;
                }
                a_hi7 = a_hi6;
                x7 = x6;
                overflow7 = overflow6;
            }
            RAM16_SET(0x0226, (uint16_t)(RAM16(0x0226) + 1));
            uint16_t value20 = RAM16(0x0226);
            a_hi5 = value20 >> 8;
            x5 = x7;
            y3 = (uint16_t)((uint16_t)((((uint8_t)value13 << 8) | (value13 >> 8)) << 1) + 0xE000 + ((((uint8_t)value13 << 8) | (value13 >> 8)) >> 0x0F));
            carry3 = value20 >= 3;
            overflow5 = overflow7;
            if (!(value20 < 3)) break;
        }
        uint8_t value21 = RAM8(0x0224);
        RAM8(0x0176 + x5) = value21;
        r->a = (a_hi5 << 8) | value21;
        r->x = x5;
        r->y = y3;
        r->c = carry3;
        r->z = value21 == 0;
        r->n = value21 & 0x80;
        r->v = overflow5;
        RETURN_RTS(c);
    }
    RAM8(0x0176 + x) = 1;
    uint8_t value22 = RAM8(0x00A9 + x);
    RAM8(0x0178 + x) = (uint8_t)(value22 + 1);
    r->a = (a >> 8 << 8) | (uint8_t)(value22 + 1);
    r->z = (uint8_t)(value22 + 1) == 0;
    r->n = (uint8_t)(value22 + 1) & 0x80;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2396D, SOM_RTS, "gen", prepare_boss_spell_targets, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 212, 100)
