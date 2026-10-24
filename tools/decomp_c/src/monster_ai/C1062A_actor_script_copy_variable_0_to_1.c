#include "som_c.h"

/* C1062A actor_script_copy_variable_0_to_1   [class A, 9 bytes, 3 instructions]
 * Source: src/rom/actor_script_copy_variable_0_to_1.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void actor_script_copy_variable_0_to_1(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x062C, 0xC1015B); GUARD_JSR(c, sp_call, 0x062C); } /* read_actor_script_variable_0 */
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x062F, 0xC101AE); GUARD_JSR(c, sp_call, 0x062F); } /* write_actor_script_variable_1 */
    TAIL_CALL(c, 0xC10121, SOM_RTS); /* advance_actor_script_1_bytes */
}
SOM_REGISTER(0xC1062A, SOM_RTS, "gen", actor_script_copy_variable_0_to_1, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 9, 3)
