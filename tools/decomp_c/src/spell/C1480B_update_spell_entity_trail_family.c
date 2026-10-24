#include "som_c.h"

/* C1480B update_spell_entity_trail_family   [class A, 5 bytes, 2 instructions]
 * Source: src/rom/update_spell_entity_trail_family.s
 * Documented in docs/actor-cast-entity-trail-state.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void update_spell_entity_trail_family(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    JSL(c, 0x480E, 0xD3FD0D); /* update_spell_entity_trail_sprite_object_long */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1480B, SOM_RTS, "hand", update_spell_entity_trail_family, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 5, 2)
