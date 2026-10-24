#include "som_c.h"

/* C00069 unused_return_public_alias_69   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/unused_return_public_alias_69.s
 * Documented in docs/native-unused-return-aliases.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void unused_return_public_alias_69(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC03851, SOM_RTL); /* unused_return_internal_alias_51 */
}
SOM_REGISTER(0xC00069, SOM_RTL, "gen", unused_return_public_alias_69, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 3, 1)
