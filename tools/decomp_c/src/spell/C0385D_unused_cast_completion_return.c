#include "som_c.h"

/* C0385D unused_cast_completion_return   [class A, 1 bytes, 1 instructions]
 * Source: src/rom/unused_cast_completion_return.s
 * Documented in docs/actor-cast-restore.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABCV.
 */
static void unused_cast_completion_return(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0385D, SOM_RTL, "gen", unused_cast_completion_return, 0, L_A | L_B | L_C | L_V, 1, 1, 0, 1, 1)
