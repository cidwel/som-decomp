#include "som_c.h"

/* C0EA41 prepare_object_weapon_graphics_resources   [class B, 193 bytes, 103 instructions]
 * Source: src/rom/prepare_object_weapon_graphics_resources.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void prepare_object_weapon_graphics_resources(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0xE1E3 + x);
    RAM16_SET(0x0000, (value & 0xFF) << 1 << 1);
    uint16_t value2 = RAM16(0x0000);
    if (RAM8(0xE069 + x) == 0) {
        uint8_t value4 = BUS8(c, 0xD01004 + (uint16_t)(((value & 0xFF) << 1 << 1 << 1 << 1) - value2));
        RAM8(0xE069 + x) = value4;
    }
    uint8_t value5 = BUS8(c, 0xD01000 + (uint16_t)(((value & 0xFF) << 1 << 1 << 1 << 1) - value2));
    RAM8(0xE068 + x) = value5;
    uint8_t value6 = BUS8(c, 0xD01003 + (uint16_t)(((value & 0xFF) << 1 << 1 << 1 << 1) - value2));
    RAM8(0xD030 + (x >> 3)) = (uint8_t)((value5 << 8) | value6);
    uint8_t a1;
    uint8_t a_hi1;
    if ((uint8_t)((value5 << 8) | value6) < 4) {
        a1 = (uint8_t)((value5 << 8) | value6);
        a_hi1 = value5;
    } else {
        a1 = value5;
        a_hi1 = (uint8_t)((uint8_t)((value5 << 8) | value6) + 0x12);
    }
    if (x < 0x0600) {
        uint16_t value7 = RAM16(0xE068 + x);
        RAM16_SET(0x0000, (((uint8_t)value7 << 8) | (value7 >> 8)) & 0xFF00);
        RAM16_SET(0xE065 + x, (uint16_t)((uint16_t)((uint16_t)(((uint16_t)((((uint8_t)((((uint8_t)value7 << 8) | (value7 >> 8)) & 0xFF00) << 8) | (((((uint8_t)value7 << 8) | (value7 >> 8)) & 0xFF00) >> 8)) << 4) ^ 0xFFFF) + 1) + RAM16(0x0000)) + RAM16(0xE077 + x)));
    }
    uint16_t value10 = BUS16(c, 0xD4C000 + ((((a1 << 8) | a_hi1) & 0xFF) << 1 << 1));
    RAM16_SET(0x0000, (uint16_t)(value10 << 3));
    uint16_t value11 = RAM16(0x0000);
    RAM16_SET(0x0000, (uint16_t)((uint16_t)(value10 << 4) + value11));
    uint16_t value12 = BUS16(c, 0xD4C002 + ((((a1 << 8) | a_hi1) & 0xFF) << 1 << 1));
    RAM16_SET(0xE06A + x, value12);
    uint8_t a5;
    uint8_t a_hi4;
    bool carry2;
    bool overflow1;
    if (x < 0x0600) {
        uint8_t a2;
        if ((((a1 << 8) | a_hi1) & 0xFF) < 8) {
            a2 = ((a1 << 8) | a_hi1) & 0xFF;
        } else {
            a2 = 0;
        }
        uint8_t a3;
        uint8_t a_hi2;
        bool carry1;
        if (x < 0x0400) {
            a3 = 0;
            a_hi2 = a2;
            carry1 = x >= 0x0400;
        } else {
            a3 = (uint8_t)(((a2 << 8) | 0) + 0x0800);
            a_hi2 = (uint16_t)(((a2 << 8) | 0) + 0x0800) >> 8;
            carry1 = ((a2 << 8) | 0) + 0x0800 > 0xFFFF;
        }
        RAM16_SET(0xE07E + x, (uint16_t)(((a_hi2 << 8) | a3) + 0x1040 + carry1));
        uint16_t value13 = BUS16(c, 0xD0FFD0 + ((((a1 << 8) | a_hi1) & 0xFF) << 1));
        a5 = (uint8_t)value13;
        a_hi4 = value13 >> 8;
        carry2 = ((a1 << 8) | a_hi1) & 0xFF & 0x8000;
        overflow1 = ((((a_hi2 << 8) | a3) ^ (uint16_t)(((a_hi2 << 8) | a3) + 0x1040 + carry1)) & ((uint16_t)(((a_hi2 << 8) | a3) + 0x1040 + carry1) ^ 0x1040) & 0x8000) != 0;
    } else {
        uint16_t value14 = RAM16(0xE1E3 + x);
        uint16_t value15 = RAM16(0xE07B + x);
        uint8_t a4;
        uint8_t a_hi3;
        if (!(value14 & 0x8000)) {
            a4 = (uint8_t)value15;
            a_hi3 = value15 >> 8;
        } else {
            uint16_t value16 = RAM16(0xE07D + x);
            a4 = (uint8_t)value16;
            a_hi3 = value16 >> 8;
        }
        a5 = a4;
        a_hi4 = a_hi3;
        carry2 = value14 & 0x8000;
        overflow1 = (((uint16_t)(value10 << 4) ^ (uint16_t)((uint16_t)(value10 << 4) + value11)) & (value11 ^ (uint16_t)((uint16_t)(value10 << 4) + value11)) & 0x8000) != 0;
    }
    RAM16_SET(0xE02A + x, (a_hi4 << 8) | a5);
    r->a = (a_hi4 << 8) | a5;
    r->c = carry2;
    r->v = overflow1;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0EA41, SOM_RTS, "gen", prepare_object_weapon_graphics_resources, 0, L_B | L_X | L_Y | L_C | L_V, 4, 1, 0, 193, 103)
