#include "som_c.h"

/* C0E034 refresh_actor_identity_graphics_and_program_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/refresh_actor_identity_graphics_and_program_long.s
 * Documented in docs/actor-action-identity-refresh.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: YCV.
 */
static void refresh_actor_identity_graphics_and_program_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0xE036, 0xC0E038); GUARD_JSR(c, sp_call, 0xE036); } /* refresh_map_object_identity_graphics_and_ai */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0E034, SOM_RTL, "hand", refresh_actor_identity_graphics_and_program_long, 0, L_Y | L_C | L_V, 1, 1, 0, 4, 2)
