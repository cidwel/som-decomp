#include "som_c.h"

/* C18003 actor_command_public_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/actor_command_public_jump.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: AYCV.
 */
static void actor_command_public_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC1CB12, SOM_RTL); /* dispatch_external_actor_command_with_saved_context */
}
SOM_REGISTER(0xC18003, SOM_RTL, "gen", actor_command_public_jump, 0, L_A | L_Y | L_C | L_V, 1, 0, 0, 3, 1)
