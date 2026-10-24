#include "som_c.h"

/* C11726 actor_script_random_variable_1   [class A, 9 bytes, 3 instructions]
 * Source: src/rom/actor_script_random_variable_1.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void actor_script_random_variable_1(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    JSR(c, 0x1728, 0xC116F4); /* actor_script_random_bounded_nibble */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x172B, 0xC101AE); /* write_actor_script_variable_1 */
    r->mf = 1;
    r->xf = 0;
    TAIL_CALL(c, 0xC1012B, SOM_RTS); /* advance_actor_script_2_bytes */
}
SOM_REGISTER(0xC11726, SOM_RTS, "gen", actor_script_random_variable_1, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 9, 3)
