#include "som_c.h"

/* C04E6B select_actor_miss_reaction_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/select_actor_miss_reaction_long.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void select_actor_miss_reaction_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    JSR(c, 0x4E6D, 0xC04E6F); /* select_actor_random_miss_reaction */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC04E6B, SOM_RTL, "gen", select_actor_miss_reaction_long, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 4, 2)
