#include "som_c.h"

/* C0C9E6 fill_map_tile_rows_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/fill_map_tile_rows_long.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void fill_map_tile_rows_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0xC9E8, 0xC0CA71); /* fill_map_tile_rows */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0C9E6, SOM_RTL, "gen", fill_map_tile_rows_long, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 4, 2)
