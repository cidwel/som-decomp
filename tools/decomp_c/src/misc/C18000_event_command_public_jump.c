#include "som_c.h"

/* C18000 event_command_public_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/event_command_public_jump.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCV.
 */
static void event_command_public_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC1E753, SOM_RTL); /* event_command_native_context_wrapper */
}
SOM_REGISTER(0xC18000, SOM_RTL, "gen", event_command_public_jump, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 3, 1)
