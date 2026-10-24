#include "som_c.h"

/* C0380C actor_selected_effect_public_jump_mirror   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/actor_selected_effect_public_jump_mirror.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void actor_selected_effect_public_jump_mirror(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC0386E, SOM_RTL); /* actor_selected_effect_native_long_jump */
}
SOM_REGISTER(0xC0380C, SOM_RTL, "gen", actor_selected_effect_public_jump_mirror, 0, 0, 1, 1, 0, 3, 1)
