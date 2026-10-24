#include "som_c.h"

/* D3FE39 release_random_fallback_object_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/release_random_fallback_object_long.s
 * Documented in docs/actor-cast-entity-fallback-lifecycle.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void release_random_fallback_object_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0xFE3B, 0xD3FE3D); GUARD_JSR(c, sp_call, 0xFE3B); } /* release_random_fallback_object */
    RETURN_RTL(c);
}
SOM_REGISTER(0xD3FE39, SOM_RTL, "gen", release_random_fallback_object_long, 0, 0, 1, 1, 0, 4, 2)
