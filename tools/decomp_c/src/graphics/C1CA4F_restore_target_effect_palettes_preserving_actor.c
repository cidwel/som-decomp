#include "som_c.h"

/* C1CA4F restore_target_effect_palettes_preserving_actor   [class A, 9 bytes, 7 instructions]
 * Source: src/rom/restore_target_effect_palettes_preserving_actor.s
 * Documented in docs/actor-cast-coordinator.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XYCV.
 */
static void restore_target_effect_palettes_preserving_actor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    r->x = y;
    r->sp -= 4;
    JSR(c, 0xCA54, 0xC1CAAC); /* restore_actor_effect_palettes_unless_deferred */
    r->sp += 4;
    r->x = x;
    r->y = y;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1CA4F, SOM_RTS, "gen", restore_target_effect_palettes_preserving_actor, 0, L_X | L_Y | L_C | L_V, 4, 1, 0, 9, 7)
