#include "som_c.h"

/* C1C3D3 mirror_map_graphics_two_tile_odd_rows   [class B, 77 bytes, 41 instructions]
 * Source: src/rom/mirror_map_graphics_two_tile_odd_rows.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=8 bit DB=$7F D=$0000.  Callers read: B.
 */
static void mirror_map_graphics_two_tile_odd_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
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
        uint8_t value4 = BUS8(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y1 + 2));
        uint8_t value5 = BUS8(c, RAM16(0x000A) + 0x7F0000 + (uint8_t)(y1 + 2));
        r->a = (value4 << 8) | value5;
        r->y = (uint8_t)(y1 + 2);
        r->mf = 1;
        r->xf = 1;
        r->db = 0x7F;
        r->dp = 0;
        JSR(c, 0xC400, 0xC1C44F); /* reverse_map_graphics_pixel_span_bits */
        uint16_t a_all = r->a;
        BUS8_SET(c, RAM16(0x000C) + 0x7F0000 + (uint8_t)(y1 + 2), (uint8_t)a_all);
        BUS8_SET(c, RAM16(0x0008) + 0x7F0000 + (uint8_t)(y1 + 2), a_all >> 8);
        uint8_t value6 = BUS8(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y1 + 3));
        uint8_t value7 = BUS8(c, RAM16(0x000A) + 0x7F0000 + (uint8_t)(y1 + 3));
        r->a = (value6 << 8) | value7;
        r->y = (uint8_t)(y1 + 3);
        r->mf = 1;
        r->xf = 1;
        JSR(c, 0xC40E, 0xC1C44F); /* reverse_map_graphics_pixel_span_bits */
        uint16_t a_all2 = r->a;
        BUS8_SET(c, RAM16(0x000C) + 0x7F0000 + (uint8_t)(y1 + 3), (uint8_t)a_all2);
        BUS8_SET(c, RAM16(0x0008) + 0x7F0000 + (uint8_t)(y1 + 3), a_all2 >> 8);
        a_hi1 = (uint8_t)a_all2;
        y1 = (uint8_t)(y1 + 4);
        if (!(y1 < 0x20)) break;
    }
    uint16_t value8 = RAM16(0x0008);
    RAM16_SET(0x0006, value8);
    r->a = value8;
    r->mf = 0;
    r->xf = 1;
    r->db = 0x7F;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1C3D3, SOM_RTS, "gen", mirror_map_graphics_two_tile_odd_rows, 0, L_B, 1, 0, 1, 77, 41)
