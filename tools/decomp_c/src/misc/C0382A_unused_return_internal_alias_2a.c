#include "som_c.h"

/* C0382A unused_return_internal_alias_2a   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/unused_return_internal_alias_2a.s
 * Documented in docs/native-unused-return-aliases.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void unused_return_internal_alias_2a(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC0385D, SOM_RTL); /* unused_cast_completion_return */
}
SOM_REGISTER(0xC0382A, SOM_RTL, "gen", unused_return_internal_alias_2a, 0, 0, 1, 1, 0, 3, 1)
