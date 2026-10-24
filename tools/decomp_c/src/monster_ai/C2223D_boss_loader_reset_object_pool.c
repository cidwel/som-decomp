#include "som_c.h"

/* C2223D boss_loader_reset_object_pool   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/boss_loader_reset_object_pool.s
 * Entry: M=any X=any DB=any D=any.  Callers read: ABXYCZNV.
 */
static void boss_loader_reset_object_pool(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, -1)) return;
    TAIL_CALL(c, 0xC20CEA, SOM_RTS); /* reset_boss_object_pool_through_dma */
}
SOM_REGISTER(0xC2223D, SOM_RTS, "gen", boss_loader_reset_object_pool, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, -1, -1, 3, 1)
