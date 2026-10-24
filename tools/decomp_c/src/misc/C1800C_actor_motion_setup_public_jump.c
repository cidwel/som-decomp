#include "som_c.h"

/* C1800C actor_motion_setup_public_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/actor_motion_setup_public_jump.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void actor_motion_setup_public_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC18052, SOM_RTL); /* set_actor_motion_and_clear_previous_effects */
}
SOM_REGISTER(0xC1800C, SOM_RTL, "gen", actor_motion_setup_public_jump, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 3, 1)
