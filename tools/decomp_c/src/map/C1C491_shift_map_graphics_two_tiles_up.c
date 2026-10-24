#include "som_c.h"

/* C1C491 shift_map_graphics_two_tiles_up   [class B, 121 bytes, 73 instructions]
 * Source: src/rom/shift_map_graphics_two_tiles_up.s
 * Documented in docs/maps.md
 * Entry: M=any X=8 bit DB=$7F D=$0000.  Callers read: BX.
 */
static void shift_map_graphics_two_tiles_up(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, -1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t x = r->x;
    uint16_t value = RAM16(0x0006);
    RAM16_SET(0x000A, (uint16_t)(value + 0x20));
    RAM16_SET(0x0008, (uint16_t)((uint16_t)(value + 0x20) + 0x20 + (value + 0x20 > 0xFFFF)));
    RAM16_SET(0x000C, (uint16_t)((uint16_t)((uint16_t)(value + 0x20) + 0x20 + (value + 0x20 > 0xFFFF)) + 0x20 + ((uint16_t)(value + 0x20) + 0x20 + (value + 0x20 > 0xFFFF) > 0xFFFF)));
    uint16_t value2 = BUS16(c, RAM16(0x0006) + 0x7F0000);
    RAM16_SET(0x0002, value2);
    uint8_t a_hi1 = value2 >> 8;
    uint8_t y1 = 0;
    for (;;) {
        uint16_t value3 = BUS16(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y1 + 2));
        BUS16_SET(c, RAM16(0x0008) + 0x7F0000 + (uint8_t)(y1 + 0), value3);
        a_hi1 = value3 >> 8;
        y1 = (uint8_t)(y1 + 2);
        if (!(y1 < 0x0E)) break;
    }
    uint16_t value4 = BUS16(c, RAM16(0x000A) + 0x7F0000);
    BUS16_SET(c, RAM16(0x0008) + 0x7F000E, value4);
    uint8_t a_hi2 = value4 >> 8;
    uint8_t y2 = 0;
    for (;;) {
        uint16_t value5 = BUS16(c, RAM16(0x000A) + 0x7F0000 + (uint8_t)(y2 + 2));
        BUS16_SET(c, RAM16(0x000C) + 0x7F0000 + (uint8_t)(y2 + 0), value5);
        a_hi2 = value5 >> 8;
        y2 = (uint8_t)(y2 + 2);
        if (!(y2 < 0x0E)) break;
    }
    BUS16_SET(c, RAM16(0x000C) + 0x7F0000 + y2, RAM16(0x0002));
    uint16_t value7 = BUS16(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y2 + 2));
    RAM16_SET(0x0002, value7);
    uint8_t a_hi3 = value7 >> 8;
    uint8_t y3 = (uint8_t)(y2 + 2);
    for (;;) {
        uint16_t value8 = BUS16(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y3 + 2));
        BUS16_SET(c, RAM16(0x0008) + 0x7F0000 + (uint8_t)(y3 + 0), value8);
        a_hi3 = value8 >> 8;
        y3 = (uint8_t)(y3 + 2);
        if (!(y3 < 0x1E)) break;
    }
    uint16_t value9 = BUS16(c, RAM16(0x000A) + 0x7F0010);
    BUS16_SET(c, RAM16(0x0008) + 0x7F001E, value9);
    uint8_t a_hi4 = value9 >> 8;
    uint8_t y4 = 0x10;
    for (;;) {
        uint16_t value10 = BUS16(c, RAM16(0x000A) + 0x7F0000 + (uint8_t)(y4 + 2));
        BUS16_SET(c, RAM16(0x000C) + 0x7F0000 + (uint8_t)(y4 + 0), value10);
        a_hi4 = value10 >> 8;
        y4 = (uint8_t)(y4 + 2);
        if (!(y4 < 0x1E)) break;
    }
    BUS16_SET(c, RAM16(0x000C) + 0x7F0000 + y4, RAM16(0x0002));
    uint16_t value12 = RAM16(0x0008);
    RAM16_SET(0x0006, value12);
    r->a = value12;
    r->x = x;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1C491, SOM_RTS, "gen", shift_map_graphics_two_tiles_up, 0, L_B | L_X, 1, -1, 1, 121, 73)
