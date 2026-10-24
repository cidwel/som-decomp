#include "som_c.h"

/* D3F228 initialize_spell_entity_orbit_sprites_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/initialize_spell_entity_orbit_sprites_long.s
 * Documented in docs/actor-cast-entity-orbit-callbacks.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$01DA.  Callers read: nothing.
 */
static void initialize_spell_entity_orbit_sprites_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01DA) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0xF22A, 0xD3F22C); GUARD_JSR(c, sp_call, 0xF22A); } /* initialize_spell_entity_orbit_sprites */
    RETURN_RTL(c);
}
SOM_REGISTER(0xD3F228, SOM_RTL, "gen", initialize_spell_entity_orbit_sprites_long, 0, 0, 1, 1, 0, 4, 2)
