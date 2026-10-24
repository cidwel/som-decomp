#include "som_c.h"

/* C1C420 mirror_map_graphics_two_tile_all_rows   [class B, 47 bytes, 24 instructions]
 * Source: src/rom/mirror_map_graphics_two_tile_all_rows.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$7F D=$0000.  Callers read: B.
 */
static void mirror_map_graphics_two_tile_all_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0006);
    RAM16_SET(0x000A, (uint16_t)(value + 0x20));
    RAM16_SET(0x0008, (uint16_t)((uint16_t)(value + 0x20) + 0x20 + (value + 0x20 > 0xFFFF)));
    RAM16_SET(0x000C, (uint16_t)((uint16_t)((uint16_t)(value + 0x20) + 0x20 + (value + 0x20 > 0xFFFF)) + 0x20 + ((uint16_t)(value + 0x20) + 0x20 + (value + 0x20 > 0xFFFF) > 0xFFFF)));
    uint8_t a_hi1 = (uint16_t)((uint16_t)((uint16_t)(value + 0x20) + 0x20 + (value + 0x20 > 0xFFFF)) + 0x20 + ((uint16_t)(value + 0x20) + 0x20 + (value + 0x20 > 0xFFFF) > 0xFFFF)) >> 8;
    uint8_t y1 = 0x1F;
    for (;;) {
        uint8_t value2 = BUS8(c, RAM16(0x0006) + 0x7F0000 + y1);
        uint8_t value3 = BUS8(c, RAM16(0x000A) + 0x7F0000 + y1);
        r->a = (value2 << 8) | value3;
        r->y = y1;
        r->mf = 1;
        r->xf = 1;
        r->db = 0x7F;
        r->dp = 0;
        JSR(c, 0xC43F, 0xC1C44F); /* reverse_map_graphics_pixel_span_bits */
        uint16_t a_all = r->a;
        BUS8_SET(c, RAM16(0x000C) + 0x7F0000 + y1, (uint8_t)a_all);
        BUS8_SET(c, RAM16(0x0008) + 0x7F0000 + y1, a_all >> 8);
        a_hi1 = (uint8_t)a_all;
        y1 = (uint8_t)(y1 - 1);
        if (!(!(y1 & 0x80))) break;
    }
    uint16_t value4 = RAM16(0x0008);
    RAM16_SET(0x0006, value4);
    r->a = value4;
    r->mf = 0;
    r->xf = 1;
    r->db = 0x7F;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1C420, SOM_RTS, "gen", mirror_map_graphics_two_tile_all_rows, 0, L_B, 1, 1, 1, 47, 24)
