#include "som_c.h"

/* C1171D actor_script_random_variable_0   [class A, 9 bytes, 3 instructions]
 * Source: src/rom/actor_script_random_variable_0.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$01E7.  Callers read: ABXYCZNV.
 */
static void actor_script_random_variable_0(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01E7) { c->fail = 3; return; }
    JSR(c, 0x171F, 0xC116F4); /* actor_script_random_bounded_nibble */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x1722, 0xC10197); /* write_actor_script_variable_0 */
    r->mf = 1;
    r->xf = 0;
    TAIL_CALL(c, 0xC1012B, SOM_RTS); /* advance_actor_script_2_bytes */
}
SOM_REGISTER(0xC1171D, SOM_RTS, "gen", actor_script_random_variable_0, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 9, 3)
