#include "som_c.h"

/* C21978 prepare_animation_object_mirrored_position   [class B, 86 bytes, 43 instructions]
 * Source: src/rom/prepare_animation_object_mirrored_position.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYV.
 */
static void prepare_animation_object_mirrored_position(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint8_t value;
    BUS8_OK(c, (RAM8(0x0278) << 0x10) + RAM16(0x0276) + y, value);
    RAM8(0x0299) = value;
    if (value & 0x80) {
        RAM8(0x029A) = 0xFF;
    }
    uint8_t value2;
    BUS8_OK(c, (RAM8(0x0278) << 0x10) + RAM16(0x0276) + (uint16_t)(y + 1), value2);
    RAM8(0x029B) = value2;
    if (value2 & 0x80) {
        RAM8(0x029C) = 0xFF;
    }
    uint16_t value3 = RAM16(0x0287);
    uint16_t value4 = RAM16(0x0098 + value3);
    uint8_t a_hi1;
    if ((value4 & 0x40) == 0) {
        a_hi1 = value4 >> 8;
    } else {
        uint16_t value5 = RAM16(0x0299);
        RAM16_SET(0x0299, (uint16_t)((value5 ^ 0xFFFF) + 1));
        a_hi1 = (uint16_t)((value5 ^ 0xFFFF) + 1) >> 8;
    }
    uint16_t value6 = RAM16(0x0098 + value3);
    uint8_t a_hi2;
    if ((value6 & 0x80) == 0) {
        a_hi2 = value6 >> 8;
    } else {
        uint16_t value7 = RAM16(0x029B);
        RAM16_SET(0x029B, (uint16_t)((value7 ^ 0xFFFF) + 1));
        a_hi2 = (uint16_t)((value7 ^ 0xFFFF) + 1) >> 8;
    }
    RAM16_SET(0x029F, (uint16_t)(RAM16(0x002B + value3) + RAM16(0x0299)));
    uint16_t value10 = RAM16(0x0032 + value3);
    uint16_t value11 = RAM16(0x029B);
    RAM16_SET(0x02A1, (uint16_t)(value10 + value11));
    uint16_t value12 = RAM16(0x0066 + value3);
    RAM16_SET(0x029D, value12);
    RAM16_SET(0x02A3, value3);
    r->a = value12;
    r->x = value3;
    r->y = (uint16_t)(y + 2);
    r->v = ((value10 ^ (uint16_t)(value10 + value11)) & (value11 ^ (uint16_t)(value10 + value11)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21978, SOM_RTS, "hand", prepare_animation_object_mirrored_position, 0, L_B | L_X | L_Y | L_V, 2, 0, 0, 86, 43)
