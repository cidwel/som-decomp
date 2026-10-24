#include "som_c.h"

/* C0002D actor_combat_tick_public_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/actor_combat_tick_public_jump.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void actor_combat_tick_public_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC03815, SOM_RTL); /* actor_combat_tick_internal_jump */
}
SOM_REGISTER(0xC0002D, SOM_RTL, "gen", actor_combat_tick_public_jump, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 3, 1)
