#include "som_c.h"

/* C0386E actor_selected_effect_native_long_jump   [class A, 4 bytes, 1 instructions]
 * Source: src/rom/actor_selected_effect_native_long_jump.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void actor_selected_effect_native_long_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC8E1ED, SOM_RTL); /* apply_actor_selected_effect_and_status */
}
SOM_REGISTER(0xC0386E, SOM_RTL, "gen", actor_selected_effect_native_long_jump, 0, 0, 1, 1, 0, 4, 1)
