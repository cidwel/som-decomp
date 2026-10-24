#include "som_c.h"

/* C20000 initialize_boss_resources_public_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/initialize_boss_resources_public_jump.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYV.
 */
static void initialize_boss_resources_public_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC20040, SOM_RTL); /* initialize_boss_resources_from_cache */
}
SOM_REGISTER(0xC20000, SOM_RTL, "gen", initialize_boss_resources_public_jump, 0, L_A | L_B | L_X | L_Y | L_V, 1, 0, 0, 3, 1)
