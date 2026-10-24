#include "som_c.h"

/* C11FC8 actor_script_apply_selected_effect_to_current_target   [class A, 9 bytes, 3 instructions]
 * Source: src/rom/actor_script_apply_selected_effect_to_current_target.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void actor_script_apply_selected_effect_to_current_target(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x1FCA, 0xC105A5); GUARD_JSR(c, sp_call, 0x1FCA); } /* resolve_visible_current_actor_target */
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x1FCD, 0xC11FB3); GUARD_JSR(c, sp_call, 0x1FCD); } /* actor_script_call_selected_effect_preserving_context */
    TAIL_CALL(c, 0xC10121, SOM_RTS); /* advance_actor_script_1_bytes */
}
SOM_REGISTER(0xC11FC8, SOM_RTS, "gen", actor_script_apply_selected_effect_to_current_target, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 9, 3)
