#include "som_c.h"

/* C1481A update_random_fallback_scheduler_object   [class A, 5 bytes, 2 instructions]
 * Source: src/rom/update_random_fallback_scheduler_object.s
 * Documented in docs/actor-cast-entity-fallback-lifecycle.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void update_random_fallback_scheduler_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    JSL(c, 0x481D, 0xD3FFB9); /* update_random_fallback_object_long */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1481A, SOM_RTS, "hand", update_random_fallback_scheduler_object, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 5, 2)
