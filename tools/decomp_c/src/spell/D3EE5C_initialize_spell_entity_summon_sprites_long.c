#include "som_c.h"

/* D3EE5C initialize_spell_entity_summon_sprites_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/initialize_spell_entity_summon_sprites_long.s
 * Documented in docs/actor-cast-entity-summon-init.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$01B4.  Callers read: nothing.
 */
static void initialize_spell_entity_summon_sprites_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01B4) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0xEE5E, 0xD3EE60); GUARD_JSR(c, sp_call, 0xEE5E); } /* initialize_spell_entity_summon_sprites */
    RETURN_RTL(c);
}
SOM_REGISTER(0xD3EE5C, SOM_RTS, "gen", initialize_spell_entity_summon_sprites_long, 0, 0, 1, 1, 0, 4, 2)
