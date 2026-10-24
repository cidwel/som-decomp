#include "som_c.h"

/* D3FFB9 update_random_fallback_object_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/update_random_fallback_object_long.s
 * Documented in docs/actor-cast-entity-fallback-lifecycle.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void update_random_fallback_object_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0xFFBB, 0xD3FFBD); GUARD_JSR(c, sp_call, 0xFFBB); } /* update_random_fallback_object */
    RETURN_RTL(c);
}
SOM_REGISTER(0xD3FFB9, SOM_RTL, "gen", update_random_fallback_object_long, 0, 0, 1, 1, 0, 4, 2)
