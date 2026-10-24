#include "som_c.h"

/* C105EE actor_script_increment_variable_2   [class A, 10 bytes, 4 instructions]
 * Source: src/rom/actor_script_increment_variable_2.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void actor_script_increment_variable_2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x05F0, 0xC10179); GUARD_JSR(c, sp_call, 0x05F0); } /* read_actor_script_variable_2 */
    uint16_t a_all = r->a;
    r->a = (a_all >> 8 << 8) | (uint8_t)((uint8_t)a_all + 1);
    r->z = (uint8_t)((uint8_t)a_all + 1) == 0;
    r->n = (uint8_t)((uint8_t)a_all + 1) & 0x80;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x05F4, 0xC101C7); GUARD_JSR(c, sp_call, 0x05F4); } /* write_actor_script_variable_2 */
    TAIL_CALL(c, 0xC10121, SOM_RTS); /* advance_actor_script_1_bytes */
}
SOM_REGISTER(0xC105EE, SOM_RTS, "gen", actor_script_increment_variable_2, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 10, 4)
