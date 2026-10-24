#include "som_c.h"

/* D3F831 initialize_spell_entity_trail_sprites_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/initialize_spell_entity_trail_sprites_long.s
 * Documented in docs/actor-cast-entity-trail-init.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: nothing.
 */
static void initialize_spell_entity_trail_sprites_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0xF833, 0xD3F835); GUARD_JSR(c, sp_call, 0xF833); } /* initialize_spell_entity_trail_sprites */
    RETURN_RTL(c);
}
SOM_REGISTER(0xD3F831, SOM_RTL, "gen", initialize_spell_entity_trail_sprites_long, 0, 0, 1, 1, 0, 4, 2)
