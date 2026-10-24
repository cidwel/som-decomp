#include "som_c.h"

/* C03851 unused_return_internal_alias_51   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/unused_return_internal_alias_51.s
 * Documented in docs/native-unused-return-aliases.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: nothing.
 */
static void unused_return_internal_alias_51(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC0385D, SOM_RTL); /* unused_cast_completion_return */
}
SOM_REGISTER(0xC03851, SOM_RTL, "gen", unused_return_internal_alias_51, 0, 0, 1, 0, 0, 3, 1)
