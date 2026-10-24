#include "som_c.h"

/* C11738 actor_script_random_variable_3   [class A, 9 bytes, 3 instructions]
 * Source: src/rom/actor_script_random_variable_3.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void actor_script_random_variable_3(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    JSR(c, 0x173A, 0xC116F4); /* actor_script_random_bounded_nibble */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x173D, 0xC101DE); /* write_actor_script_variable_3 */
    r->mf = 1;
    r->xf = 0;
    TAIL_CALL(c, 0xC1012B, SOM_RTS); /* advance_actor_script_2_bytes */
}
SOM_REGISTER(0xC11738, SOM_RTS, "gen", actor_script_random_variable_3, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 9, 3)
