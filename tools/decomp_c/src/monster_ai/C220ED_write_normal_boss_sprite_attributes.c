#include "som_c.h"

/* C220ED write_normal_boss_sprite_attributes   [class B, 99 bytes, 52 instructions]
 * Source: src/rom/write_normal_boss_sprite_attributes.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: X.
 */
static void write_normal_boss_sprite_attributes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = BUS16(c, RAM16(0x0279) + 0x7E0002);
    RAM16_SET(0x029B, value);
    RAM16_SET(0x0297, value | 0x2000);
    uint16_t value2 = RAM16(0x0297);
    RAM16_SET(0x0802 + x, value2);
    uint8_t value3 = RAM8(0x0295);
    uint8_t value4 = BUS8(c, 0xC221B3 + (uint8_t)(value2 >> 8 << 8 | (value3 & 3)));
    RAM8(0x0A00 + (uint8_t)((value2 >> 8 << 8) | (value3 >> 2))) = (uint8_t)((value2 >> 8 << 8) | value4) & RAM8(0x0A00 + (uint8_t)((value2 >> 8 << 8) | (value3 >> 2)));
    uint8_t value6 = RAM8(0x029A);
    uint8_t x1;
    if (!(value6 & 0x80)) {
        x1 = (uint8_t)((value2 >> 8 << 8) | (value3 >> 2));
    } else {
        uint8_t value7 = RAM8(0x0295);
        uint8_t value8 = BUS8(c, 0xD97F2D + (uint8_t)(value2 >> 8 << 8 | (value7 & 3)));
        RAM8(0x0A00 + (uint8_t)((value2 >> 8 << 8) | (value7 >> 2))) = (uint8_t)((value2 >> 8 << 8) | value8) | RAM8(0x0A00 + (uint8_t)((value2 >> 8 << 8) | (value7 >> 2)));
        x1 = (uint8_t)((value2 >> 8 << 8) | (value7 >> 2));
    }
    uint8_t value10 = RAM8(0x029C);
    uint8_t x2;
    if ((value10 & 0x20) == 0) {
        x2 = x1;
    } else {
        uint8_t value11 = RAM8(0x0295);
        uint8_t value12 = BUS8(c, 0xD97F31 + (uint8_t)(value2 >> 8 << 8 | (value11 & 3)));
        RAM8(0x0A00 + (uint8_t)((value2 >> 8 << 8) | (value11 >> 2))) = (uint8_t)((value2 >> 8 << 8) | value12) | RAM8(0x0A00 + (uint8_t)((value2 >> 8 << 8) | (value11 >> 2)));
        x2 = (uint8_t)((value2 >> 8 << 8) | (value11 >> 2));
    }
    r->x = x2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC220ED, SOM_RTS, "gen", write_normal_boss_sprite_attributes, 0, L_X, 1, 0, 0, 99, 52)
