#include "som_c.h"

/* C21E06 read_and_mirror_boss_animation_collision_shapes   [class B, 122 bytes, 59 instructions]
 * Source: src/rom/read_and_mirror_boss_animation_collision_shapes.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: YV.
 */
static void read_and_mirror_boss_animation_collision_shapes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value;
    BUS16_OK(c, (RAM8(0x027B) << 0x10) + RAM16(0x0279), value);
    RAM16_SET(0x00CA + x, value);
    uint8_t a_hi1;
    uint16_t y1;
    if (value == 0) {
        a_hi1 = value >> 8;
        y1 = 0;
    } else {
        uint16_t value2;
        BUS16_OK(c, (RAM8(0x027B) << 0x10) + RAM16(0x0279) + 2, value2);
        RAM16_SET(0x00C8 + x, value2);
        a_hi1 = value2 >> 8;
        y1 = 2;
    }
    uint16_t value3;
    BUS16_OK(c, (RAM8(0x027B) << 0x10) + RAM16(0x0279) + (uint16_t)(y1 + 2), value3);
    RAM16_SET(0x00C2 + x, value3);
    uint8_t a_hi2;
    uint16_t y2;
    if (value3 == 0) {
        a_hi2 = value3 >> 8;
        y2 = (uint16_t)(y1 + 2);
    } else {
        uint16_t value4;
        BUS16_OK(c, (RAM8(0x027B) << 0x10) + RAM16(0x0279) + (uint16_t)(y1 + 4), value4);
        RAM16_SET(0x00C0 + x, value4);
        a_hi2 = value4 >> 8;
        y2 = (uint16_t)(y1 + 4);
    }
    uint16_t value5;
    BUS16_OK(c, (RAM8(0x027B) << 0x10) + RAM16(0x0279) + (uint16_t)(y2 + 2), value5);
    RAM16_SET(0x00CE + x, value5);
    uint8_t a_hi3;
    uint16_t y3;
    if (value5 == 0) {
        a_hi3 = value5 >> 8;
        y3 = (uint16_t)(y2 + 2);
    } else {
        uint16_t value6;
        BUS16_OK(c, (RAM8(0x027B) << 0x10) + RAM16(0x0279) + (uint16_t)(y2 + 4), value6);
        RAM16_SET(0x00CC + x, value6);
        a_hi3 = value6 >> 8;
        y3 = (uint16_t)(y2 + 4);
    }
    if ((RAM8(0x0098 + x) & 0x40) != 0) {
        RAM8(0x00C0 + x) = (uint8_t)((RAM8(0x00C0 + x) ^ 0xFF) + 1);
        RAM8(0x00C8 + x) = (uint8_t)((RAM8(0x00C8 + x) ^ 0xFF) + 1);
        RAM8(0x00CC + x) = (uint8_t)((RAM8(0x00CC + x) ^ 0xFF) + 1);
    }
    if ((RAM8(0x0098 + x) & 0x80) != 0) {
        RAM8(0x00C1 + x) = (uint8_t)((RAM8(0x00C1 + x) ^ 0xFF) + 1);
        RAM8(0x00C9 + x) = (uint8_t)((RAM8(0x00C9 + x) ^ 0xFF) + 1);
        RAM8(0x00CD + x) = (uint8_t)((RAM8(0x00CD + x) ^ 0xFF) + 1);
    }
    r->y = y3;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21E06, SOM_RTS, "hand", read_and_mirror_boss_animation_collision_shapes, 0, L_Y | L_V, 1, 0, 0, 122, 59)
