#include "som_c.h"
#include "som_hand_b.h"

/* C12E02 update_spell_entity_twin_sprite_object_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/update_spell_entity_twin_sprite_object_long.s
 * Documented in docs/actor-cast-entity-twin-callbacks.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: nothing.
 */
static void update_spell_entity_twin_sprite_object_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2E04, 0xC12E06); GUARD_JSR(c, sp_call, 0x2E04); } /* update_spell_entity_twin_sprite_object */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC12E02, SOM_RTL, "hand", update_spell_entity_twin_sprite_object_long, 0, 0, 1, 1, 0, 4, 2)
