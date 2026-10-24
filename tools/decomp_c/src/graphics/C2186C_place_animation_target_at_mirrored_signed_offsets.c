#include "som_c.h"

/* C2186C place_animation_target_at_mirrored_signed_offsets   [class B, 106 bytes, 52 instructions]
 * Source: src/rom/place_animation_target_at_mirrored_signed_offsets.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void place_animation_target_at_mirrored_signed_offsets(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0287);
    RAM16_SET(0x0295, RAM16(0x002B + value));
    RAM16_SET(0x0297, RAM16(0x0032 + value));
    RAM8(0x029A) = 0;
    RAM8(0x029C) = 0;
    uint8_t value4;
    BUS8_OK(c, (RAM8(0x0278) << 0x10) + RAM16(0x0276) + y, value4);
    RAM8(0x0299) = value4;
    if (value4 & 0x80) {
        RAM8(0x029A) = 0xFF;
    }
    uint8_t value5;
    BUS8_OK(c, (RAM8(0x0278) << 0x10) + RAM16(0x0276) + (uint16_t)(y + 1), value5);
    RAM8(0x029B) = value5;
    if (value5 & 0x80) {
        RAM8(0x029C) = 0xFF;
    }
    uint16_t value6 = RAM16(0x0098 + value);
    uint8_t a_hi1;
    if ((value6 & 0x40) == 0) {
        a_hi1 = value6 >> 8;
    } else {
        uint16_t value7 = RAM16(0x0299);
        RAM16_SET(0x0299, (uint16_t)((value7 ^ 0xFFFF) + 1));
        a_hi1 = (uint16_t)((value7 ^ 0xFFFF) + 1) >> 8;
    }
    uint16_t value8 = RAM16(0x0098 + value);
    uint8_t a_hi2;
    if ((value8 & 0x80) == 0) {
        a_hi2 = value8 >> 8;
    } else {
        uint16_t value9 = RAM16(0x029B);
        RAM16_SET(0x029B, (uint16_t)((value9 ^ 0xFFFF) + 1));
        a_hi2 = (uint16_t)((value9 ^ 0xFFFF) + 1) >> 8;
    }
    uint16_t value10 = RAM16(0x00A9 + value);
    RAM16_SET(0x0002 + (uint16_t)((uint16_t)((((value10 & 0xFF) << 8) | 0) << 1) + 0xE000), (uint16_t)(RAM16(0x0295) + RAM16(0x0299)));
    uint16_t value13 = RAM16(0x0297);
    uint16_t value14 = RAM16(0x029B);
    RAM16_SET(0x0004 + (uint16_t)((uint16_t)((((value10 & 0xFF) << 8) | 0) << 1) + 0xE000), (uint16_t)(value13 + value14));
    uint16_t value15 = RAM16(0x0287);
    r->a = (uint16_t)(value13 + value14);
    r->x = value15;
    r->y = (uint16_t)(y + 2);
    r->c = value13 + value14 > 0xFFFF;
    r->z = value15 == 0;
    r->n = value15 & 0x8000;
    r->v = ((value13 ^ (uint16_t)(value13 + value14)) & (value14 ^ (uint16_t)(value13 + value14)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2186C, SOM_RTS, "hand", place_animation_target_at_mirrored_signed_offsets, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 106, 52)
