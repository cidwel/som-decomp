#include "som_c.h"

/* C2000F public_boss_random_initialization_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/public_boss_random_initialization_jump.s
 * Documented in docs/boss-public-party-services.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: XY.
 */
static void public_boss_random_initialization_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC2001B, SOM_RTL); /* initialize_boss_random_tables_and_cast_queues_preserving_context */
}
SOM_REGISTER(0xC2000F, SOM_RTL, "gen", public_boss_random_initialization_jump, 0, L_X | L_Y, 1, 0, 0, 3, 1)
