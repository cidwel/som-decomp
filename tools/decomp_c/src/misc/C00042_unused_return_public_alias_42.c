#include "som_c.h"

/* C00042 unused_return_public_alias_42   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/unused_return_public_alias_42.s
 * Documented in docs/native-unused-return-aliases.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void unused_return_public_alias_42(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC0382A, SOM_RTL); /* unused_return_internal_alias_2a */
}
SOM_REGISTER(0xC00042, SOM_RTL, "gen", unused_return_public_alias_42, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 3, 1)
