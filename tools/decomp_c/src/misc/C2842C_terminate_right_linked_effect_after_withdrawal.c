#include "som_c.h"

/* C2842C terminate_right_linked_effect_after_withdrawal   [class A, 2 bytes, 2 instructions]
 * Source: src/rom/terminate_right_linked_effect_after_withdrawal.s
 * Documented in docs/boss-native58-linked-effects.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void terminate_right_linked_effect_after_withdrawal(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    r->c = true; /* SEC */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2842C, SOM_RTS, "hand", terminate_right_linked_effect_after_withdrawal, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 2, 2)
