#include "som_c.h"

/* C1E753 event_command_native_context_wrapper   [class A, 26 bytes, 18 instructions]
 * Source: src/rom/event_command_native_context_wrapper.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCV.
 */
static void event_command_native_context_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const bool carry = r->c;
    const bool overflow = r->v;
    r->dp = 0;
    r->sp -= 4;
    JSR(c, 0xE768, 0xC1E77B); /* accept_numeric_event_request */
    r->sp += 4;
    r->c = carry;
    r->v = overflow;
    r->mf = 0;
    r->xf = 0;
    r->dp = 0x0200;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1E753, SOM_RTL, "gen", event_command_native_context_wrapper, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 7, 0, 0, 26, 18)
