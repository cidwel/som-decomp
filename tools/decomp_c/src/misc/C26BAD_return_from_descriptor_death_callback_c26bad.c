#include "som_c.h"

/* C26BAD return_from_descriptor_death_callback_c26bad   [class A, 1 bytes, 1 instructions]
 * Source: src/rom/return_from_descriptor_death_callback_c26bad.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void return_from_descriptor_death_callback_c26bad(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26BAD, SOM_RTS, "gen", return_from_descriptor_death_callback_c26bad, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 1, 1)
