#include "som_c.h"

/* C8E26B actor_selected_effect_no_change   [class A, 1 bytes, 1 instructions]
 * Source: src/rom/actor_selected_effect_no_change.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void actor_selected_effect_no_change(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8E26B, SOM_RTS, "gen", actor_selected_effect_no_change, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 1, 1)
