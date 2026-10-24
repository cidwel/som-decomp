#include "som_c.h"

/* C0001E finish_previous_cast_public_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/finish_previous_cast_public_jump.s
 * Documented in docs/actor-cast-restore.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABCV.
 */
static void finish_previous_cast_public_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC03806, SOM_RTL); /* finish_previous_cast_internal_jump */
}
SOM_REGISTER(0xC0001E, SOM_RTL, "gen", finish_previous_cast_public_jump, 0, L_A | L_B | L_C | L_V, 1, 1, 0, 3, 1)
