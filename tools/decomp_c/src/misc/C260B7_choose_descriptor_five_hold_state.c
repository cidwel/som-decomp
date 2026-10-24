#include "som_c.h"

/* C260B7 choose_descriptor_five_hold_state   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/choose_descriptor_five_hold_state.s
 * Documented in docs/boss-descriptor-five.md
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_five_hold_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    r->a = 0xDD77;
    r->z = 0;
    r->n = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC260B7, SOM_RTS, "gen", choose_descriptor_five_hold_state, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 4, 2)
