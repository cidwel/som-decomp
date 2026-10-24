#include "som_c.h"

/* C1C486 advance_map_graphics_two_tile_frame_pointer   [class A, 11 bytes, 6 instructions]
 * Source: src/rom/advance_map_graphics_two_tile_frame_pointer.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=8 bit DB=$7F D=$0000.  Callers read: B.
 */
static void advance_map_graphics_two_tile_frame_pointer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0006);
    RAM16_SET(0x0006, (uint16_t)(value + 0x40));
    r->a = (uint16_t)(value + 0x40);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1C486, SOM_RTS, "gen", advance_map_graphics_two_tile_frame_pointer, 0, L_B, 1, 0, 1, 11, 6)
