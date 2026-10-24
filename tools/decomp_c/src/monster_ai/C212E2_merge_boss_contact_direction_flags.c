#include "som_c.h"

/* C212E2 merge_boss_contact_direction_flags   [class B, 93 bytes, 48 instructions]
 * Source: src/rom/merge_boss_contact_direction_flags.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABY.
 */
static void merge_boss_contact_direction_flags(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    RAM16_SET(0x024A, 0);
    uint16_t value = RAM16(0x0246);
    uint16_t value2 = RAM16(0x0256);
    uint8_t a1;
    uint8_t a_hi1;
    if (!((uint16_t)(value - value2) & 0x8000)) {
        a1 = (uint8_t)(value - value2);
        a_hi1 = (uint16_t)(value - value2) >> 8;
    } else {
        a1 = (uint8_t)(((uint16_t)(value - value2) ^ 0xFFFF) + 1);
        a_hi1 = (uint16_t)(((uint16_t)(value - value2) ^ 0xFFFF) + 1) >> 8;
    }
    RAM16_SET(0x0252, (a_hi1 << 8) | a1);
    uint16_t value3 = RAM16(0x0248);
    uint16_t value4 = RAM16(0x0258);
    uint16_t value5 = RAM16(0x0252);
    uint8_t a_hi6;
    if ((uint16_t)(value3 + value4) < value5) {
        a_hi6 = (uint16_t)(value3 + value4) >> 8;
    } else {
        uint16_t value6 = RAM16(0x024E);
        uint16_t value7 = RAM16(0x025E);
        uint8_t a2;
        uint8_t a_hi2;
        if (!((uint16_t)(value6 - value7) & 0x8000)) {
            a2 = (uint8_t)(value6 - value7);
            a_hi2 = (uint16_t)(value6 - value7) >> 8;
        } else {
            a2 = (uint8_t)(((uint16_t)(value6 - value7) ^ 0xFFFF) + 1);
            a_hi2 = (uint16_t)(((uint16_t)(value6 - value7) ^ 0xFFFF) + 1) >> 8;
        }
        RAM16_SET(0x0252, (a_hi2 << 8) | a2);
        uint16_t value8 = RAM16(0x0250);
        uint16_t value9 = RAM16(0x0260);
        uint16_t value10 = RAM16(0x0252);
        uint8_t a_hi5;
        if ((uint16_t)(value8 + value9) < value10) {
            a_hi5 = (uint16_t)(value8 + value9) >> 8;
        } else {
            uint16_t value11 = RAM16(0x0259);
            uint8_t a_hi3;
            if (((uint16_t)(value - value2) ^ value11) & 0x8000) {
                a_hi3 = ((uint16_t)(value - value2) ^ value11) >> 8;
            } else {
                uint16_t value12 = RAM16(0x024A);
                RAM16_SET(0x024A, value12 | 1);
                a_hi3 = (value12 | 1) >> 8;
            }
            uint16_t value13 = RAM16(0x025A);
            uint8_t a_hi4;
            if (((uint16_t)(value6 - value7) ^ value13) & 0x8000) {
                a_hi4 = ((uint16_t)(value6 - value7) ^ value13) >> 8;
            } else {
                uint16_t value14 = RAM16(0x024A);
                RAM16_SET(0x024A, value14 | 2);
                a_hi4 = (value14 | 2) >> 8;
            }
            a_hi5 = a_hi4;
        }
        a_hi6 = a_hi5;
    }
    uint16_t value15 = RAM16(0x0295);
    uint8_t value16 = RAM8(0x024A);
    uint8_t value17 = RAM8(0x0029 + value15);
    RAM8(0x0029 + value15) = value16 | value17;
    r->a = (a_hi6 << 8) | (value16 | value17);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC212E2, SOM_RTS, "gen", merge_boss_contact_direction_flags, 0, L_A | L_B | L_Y, 1, 0, 0, 93, 48)
