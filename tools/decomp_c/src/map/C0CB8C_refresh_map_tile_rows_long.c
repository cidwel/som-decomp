#include "som_c.h"

/* C0CB8C refresh_map_tile_rows_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/refresh_map_tile_rows_long.s
 * Entry: M=8 bit X=16 bit DB=$00 D=any.  Callers read: nothing.
 */
static void refresh_map_tile_rows_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCB8E, 0xC0CB43); GUARD_JSR(c, sp_call, 0xCB8E); } /* refresh_sixteen_map_tile_rows_across_real_frames */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0CB8C, SOM_RTL, "gen", refresh_map_tile_rows_long, 0, 0, 1, 1, 0, 4, 2)
