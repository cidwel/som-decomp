#include "som_c.h"

/* C28E90 terminate_descriptor_eleven_height_child   [class A, 2 bytes, 2 instructions]
 * Source: src/rom/terminate_descriptor_eleven_height_child.s
 * Documented in docs/boss-descriptor-eleven-children.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void terminate_descriptor_eleven_height_child(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    r->c = true; /* SEC */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28E90, SOM_RTS, "hand", terminate_descriptor_eleven_height_child, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 2, 2)
