#include "som_c.h"

/* C1C2DA rotate_map_graphics_two_tile_odd_rows_right   [class B, 77 bytes, 45 instructions]
 * Source: src/rom/rotate_map_graphics_two_tile_odd_rows_right.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=8 bit DB=$7F D=$0000.  Callers read: BX.
 */
static void rotate_map_graphics_two_tile_odd_rows_right(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t x = r->x;
    uint16_t value = RAM16(0x0006);
    RAM16_SET(0x000A, (uint16_t)(value + 0x20));
    RAM16_SET(0x0008, (uint16_t)((uint16_t)(value + 0x20) + 0x20 + (value + 0x20 > 0xFFFF)));
    RAM16_SET(0x000C, (uint16_t)((uint16_t)((uint16_t)(value + 0x20) + 0x20 + (value + 0x20 > 0xFFFF)) + 0x20 + ((uint16_t)(value + 0x20) + 0x20 + (value + 0x20 > 0xFFFF) > 0xFFFF)));
    uint8_t a_hi1 = (uint16_t)((uint16_t)((uint16_t)(value + 0x20) + 0x20 + (value + 0x20 > 0xFFFF)) + 0x20 + ((uint16_t)(value + 0x20) + 0x20 + (value + 0x20 > 0xFFFF) > 0xFFFF)) >> 8;
    uint8_t y1 = 0;
    for (;;) {
        uint16_t value2 = BUS16(c, RAM16(0x0006) + 0x7F0000 + y1);
        BUS16_SET(c, RAM16(0x0008) + 0x7F0000 + y1, value2);
        uint16_t value3 = BUS16(c, RAM16(0x000A) + 0x7F0000 + y1);
        BUS16_SET(c, RAM16(0x000C) + 0x7F0000 + y1, value3);
        uint8_t value4 = BUS8(c, RAM16(0x000A) + 0x7F0000 + (uint8_t)(y1 + 2));
        uint8_t value5 = BUS8(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y1 + 2));
        BUS8_SET(c, RAM16(0x0008) + 0x7F0000 + (uint8_t)(y1 + 2), (value5 >> 1) | ((value4 & 1) << 7));
        BUS8_SET(c, RAM16(0x000C) + 0x7F0000 + (uint8_t)(y1 + 2), (value4 >> 1) | ((value5 & 1) << 7));
        uint8_t value6 = BUS8(c, RAM16(0x000A) + 0x7F0000 + (uint8_t)(y1 + 3));
        uint8_t value7 = BUS8(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y1 + 3));
        BUS8_SET(c, RAM16(0x0008) + 0x7F0000 + (uint8_t)(y1 + 3), (value7 >> 1) | ((value6 & 1) << 7));
        BUS8_SET(c, RAM16(0x000C) + 0x7F0000 + (uint8_t)(y1 + 3), (value6 >> 1) | ((value7 & 1) << 7));
        a_hi1 = value3 >> 8;
        y1 = (uint8_t)(y1 + 4);
        if (!(y1 < 0x20)) break;
    }
    uint16_t value8 = RAM16(0x0008);
    RAM16_SET(0x0006, value8);
    r->a = value8;
    r->x = x;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1C2DA, SOM_RTS, "gen", rotate_map_graphics_two_tile_odd_rows_right, 0, L_B | L_X, 1, 0, 1, 77, 45)
