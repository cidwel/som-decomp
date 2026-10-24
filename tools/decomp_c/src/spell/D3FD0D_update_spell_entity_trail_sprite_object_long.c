#include "som_c.h"

/* D3FD0D update_spell_entity_trail_sprite_object_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/update_spell_entity_trail_sprite_object_long.s
 * Documented in docs/actor-cast-entity-trail-state.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void update_spell_entity_trail_sprite_object_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0xFD0F, 0xD3FD11); GUARD_JSR(c, sp_call, 0xFD0F); } /* update_spell_entity_trail_sprite_object */
    RETURN_RTL(c);
}
SOM_REGISTER(0xD3FD0D, SOM_RTL, "gen", update_spell_entity_trail_sprite_object_long, 0, 0, 1, 1, 0, 4, 2)
