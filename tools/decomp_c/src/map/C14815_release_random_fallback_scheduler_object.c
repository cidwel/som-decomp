#include "som_c.h"
#include "som_hand_b.h"

/* C14815 release_random_fallback_scheduler_object   [class A, 5 bytes, 2 instructions]
 * Source: src/rom/release_random_fallback_scheduler_object.s
 * Documented in docs/actor-cast-entity-fallback-lifecycle.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void release_random_fallback_scheduler_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSL(c, 0x4818, 0xD3FE39); GUARD_JSL(c, sp_call, 0x4818); } /* release_random_fallback_object_long */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC14815, SOM_RTS, "hand", release_random_fallback_scheduler_object, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 5, 2)
