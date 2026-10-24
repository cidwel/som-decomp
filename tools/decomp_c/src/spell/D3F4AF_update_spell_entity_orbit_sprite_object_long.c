#include "som_c.h"

/* D3F4AF update_spell_entity_orbit_sprite_object_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/update_spell_entity_orbit_sprite_object_long.s
 * Documented in docs/actor-cast-entity-orbit-callbacks.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: nothing.
 */
static void update_spell_entity_orbit_sprite_object_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    JSR(c, 0xF4B1, 0xD3F4B3); /* update_spell_entity_orbit_sprite_object */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xD3F4AF, SOM_RTL, "gen", update_spell_entity_orbit_sprite_object_long, 0, 0, 1, 1, 0, 4, 2)
