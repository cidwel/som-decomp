#include "som_c.h"

/* C1800F cast_actor_request_public_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/cast_actor_request_public_jump.s
 * Documented in docs/actor-cast-api.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BXYCV.
 */
static void cast_actor_request_public_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    TAIL_CALL(c, 0xC1806F, SOM_RTL); /* cast_actor_request_preserving_cpu_context */
}
SOM_REGISTER(0xC1800F, SOM_RTL, "gen", cast_actor_request_public_jump, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 3, 1)
