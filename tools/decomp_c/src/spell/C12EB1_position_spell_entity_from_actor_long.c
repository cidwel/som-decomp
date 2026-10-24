#include "som_c.h"

/* C12EB1 position_spell_entity_from_actor_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/position_spell_entity_from_actor_long.s
 * Documented in docs/actor-cast-entity-mode-two.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BXYCV.
 */
static void position_spell_entity_from_actor_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2EB3, 0xC138EA); GUARD_JSR(c, sp_call, 0x2EB3); } /* position_spell_entity_from_actor_coordinates */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC12EB1, SOM_RTL, "hand", position_spell_entity_from_actor_long, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 4, 2)
