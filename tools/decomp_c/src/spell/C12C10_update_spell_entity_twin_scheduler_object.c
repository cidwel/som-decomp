#include "som_c.h"

/* C12C10 update_spell_entity_twin_scheduler_object   [class A, 5 bytes, 2 instructions]
 * Source: src/rom/update_spell_entity_twin_scheduler_object.s
 * Documented in docs/actor-cast-entity-twin-callbacks.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void update_spell_entity_twin_scheduler_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSL(c, 0x2C13, 0xC12E02); GUARD_JSL(c, sp_call, 0x2C13); } /* update_spell_entity_twin_sprite_object_long */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12C10, SOM_RTS, "gen", update_spell_entity_twin_scheduler_object, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 5, 2)
