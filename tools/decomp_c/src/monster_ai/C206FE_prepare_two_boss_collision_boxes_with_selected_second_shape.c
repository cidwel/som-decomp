#include "som_c.h"

/* C206FE prepare_two_boss_collision_boxes_with_selected_second_shape   [class B, 123 bytes, 64 instructions]
 * Source: src/rom/prepare_two_boss_collision_boxes_with_selected_second_shape.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABYCV.
 */
static void prepare_two_boss_collision_boxes_with_selected_second_shape(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00CA + x);
    uint16_t value2 = RAM16(0x00CE + x);
    if ((value | value2) != 0) {
        RAM16_SET(0x025E, RAM16(0x002B + x));
        RAM16_SET(0x0260, (uint16_t)((uint16_t)(((RAM16(0x0066 + x) >> 1) ^ 0xFFFF) + 1) + RAM16(0x0032 + x)));
        uint16_t value6 = RAM16(0x0066 + x);
        RAM16_SET(0x0262, value6);
        uint8_t a_hi1 = value6 >> 8;
        uint16_t x1 = 0;
        uint16_t y1 = x;
        for (;;) {
            uint8_t value7 = RAM8(0x00C8 + y1);
            BUS8_SET(c, (uint16_t)(x1 + 0x0246), value7);
            if (!(value7 & 0x80)) {
                BUS8_SET(c, (uint16_t)(x1 + 0x0247), 0);
            } else {
                BUS8_SET(c, (uint16_t)(x1 + 0x0247), 0xFF);
            }
            x1 = (uint16_t)(x1 + 2);
            y1 = (uint16_t)(y1 + 1);
            if (!(x1 != 8)) break;
        }
        uint16_t value8 = RAM16(0x0287);
        uint8_t a_hi2 = a_hi1;
        uint16_t x2 = 0;
        uint16_t y2 = value8;
        for (;;) {
            uint8_t value9 = RAM8(0x00CC + y2);
            BUS8_SET(c, (uint16_t)(x2 + 0x024E), value9);
            if (!(value9 & 0x80)) {
                BUS8_SET(c, (uint16_t)(x2 + 0x024F), 0);
            } else {
                BUS8_SET(c, (uint16_t)(x2 + 0x024F), 0xFF);
            }
            x2 = (uint16_t)(x2 + 2);
            y2 = (uint16_t)(y2 + 1);
            if (!(x2 != 8)) break;
        }
        uint16_t value10 = RAM16(0x025E);
        RAM16_SET(0x0246, (uint16_t)(value10 + RAM16(0x0246)));
        uint16_t value12 = RAM16(0x0260);
        RAM16_SET(0x0248, (uint16_t)(value12 + RAM16(0x0248)));
        RAM16_SET(0x024E, (uint16_t)(value10 + RAM16(0x024E)));
        uint16_t value15 = RAM16(0x0250);
        RAM16_SET(0x0250, (uint16_t)(value12 + value15));
        r->a = (uint16_t)(value12 + value15);
        r->y = y2;
        r->c = 0;
        r->v = ((value12 ^ (uint16_t)(value12 + value15)) & (value15 ^ (uint16_t)(value12 + value15)) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    r->a = value | value2;
    r->c = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC206FE, SOM_RTS, "gen", prepare_two_boss_collision_boxes_with_selected_second_shape, 0, L_A | L_B | L_Y | L_C | L_V, 1, 0, 0, 123, 64)
