#include "som_c.h"

/* C260C9 choose_descriptor_five_phase_zero_action   [class A, 5 bytes, 3 instructions]
 * Source: src/rom/choose_descriptor_five_phase_zero_action.s
 * Documented in docs/boss-descriptor-five.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_five_phase_zero_action(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    r->a = 0xDD82;
    r->c = 0;
    r->z = 0;
    r->n = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC260C9, SOM_RTS, "gen", choose_descriptor_five_phase_zero_action, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 5, 3)
