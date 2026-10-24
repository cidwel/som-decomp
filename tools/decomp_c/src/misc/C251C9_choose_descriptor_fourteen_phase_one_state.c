#include "som_c.h"

/* C251C9 choose_descriptor_fourteen_phase_one_state   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/choose_descriptor_fourteen_phase_one_state.s
 * Documented in docs/boss-descriptor-fourteen.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_fourteen_phase_one_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    r->a = 0xD900;
    r->z = 0;
    r->n = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC251C9, SOM_RTS, "gen", choose_descriptor_fourteen_phase_one_state, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 4, 2)
