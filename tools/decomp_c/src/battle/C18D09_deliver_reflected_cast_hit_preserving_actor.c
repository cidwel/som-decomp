#include "som_c.h"

/* C18D09 deliver_reflected_cast_hit_preserving_actor   [class A, 9 bytes, 6 instructions]
 * Source: src/rom/deliver_reflected_cast_hit_preserving_actor.s
 * Documented in docs/actor-cast-execution-check.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCV.
 */
static void deliver_reflected_cast_hit_preserving_actor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    r->y = (a_hi << 8) | a;
    r->sp -= 2;
    JSR(c, 0x8D0D, 0xC18D12); /* deliver_complete_cast_hit_to_target */
    r->sp += 2;
    r->x = x;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC18D09, SOM_RTS, "hand", deliver_reflected_cast_hit_preserving_actor, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 9, 6)
