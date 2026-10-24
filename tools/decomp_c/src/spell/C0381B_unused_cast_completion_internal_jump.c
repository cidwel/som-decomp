#include "som_c.h"

/* C0381B unused_cast_completion_internal_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/unused_cast_completion_internal_jump.s
 * Documented in docs/actor-cast-restore.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABCV.
 */
static void unused_cast_completion_internal_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC0385D, SOM_RTL); /* unused_cast_completion_return */
}
SOM_REGISTER(0xC0381B, SOM_RTL, "gen", unused_cast_completion_internal_jump, 0, L_A | L_B | L_C | L_V, 1, 1, 0, 3, 1)
