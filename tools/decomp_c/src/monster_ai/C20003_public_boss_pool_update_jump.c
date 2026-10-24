#include "som_c.h"

/* C20003 public_boss_pool_update_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/public_boss_pool_update_jump.s
 * Documented in docs/boss-public-pool-update.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void public_boss_pool_update_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC201F9, SOM_RTL); /* update_boss_pool_then_consume_pending_cast_preserving_context */
}
SOM_REGISTER(0xC20003, SOM_RTL, "gen", public_boss_pool_update_jump, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 3, 1)
