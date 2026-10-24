#include "som_c.h"

/* C18012 refresh_map_tiles_public_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/refresh_map_tiles_public_jump.s
 * Entry: M=8 bit X=16 bit DB=$00 D=any.  Callers read: ABXYCZNV.
 */
static void refresh_map_tiles_public_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    TAIL_CALL(c, 0xC1803D, SOM_RTL); /* refresh_map_tiles_preserving_cpu_context */
}
SOM_REGISTER(0xC18012, SOM_RTL, "gen", refresh_map_tiles_public_jump, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 3, 1)
