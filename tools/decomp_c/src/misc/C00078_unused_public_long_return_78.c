#include "som_c.h"

/* C00078 unused_public_long_return_78   [class A, 1 bytes, 1 instructions]
 * Source: src/rom/unused_public_long_return_78.s
 * Documented in docs/native-unused-return-aliases.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void unused_public_long_return_78(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC00078, SOM_RTL, "gen", unused_public_long_return_78, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 1, 1)
