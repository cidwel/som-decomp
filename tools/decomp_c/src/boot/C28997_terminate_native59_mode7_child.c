#include "som_c.h"

/* C28997 terminate_native59_mode7_child   [class A, 2 bytes, 2 instructions]
 * Source: src/rom/terminate_native59_mode7_child.s
 * Documented in docs/boss-native59-children.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void terminate_native59_mode7_child(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    r->c = true; /* SEC */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28997, SOM_RTS, "hand", terminate_native59_mode7_child, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 2, 2)
