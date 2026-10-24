#include "som_c.h"

/* D3EA00 initialize_spell_entity_burst_sprites_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/initialize_spell_entity_burst_sprites_long.s
 * Documented in docs/actor-cast-entity-burst-init.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void initialize_spell_entity_burst_sprites_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0xEA02, 0xD3EA04); GUARD_JSR(c, sp_call, 0xEA02); } /* initialize_spell_entity_burst_sprites */
    RETURN_RTL(c);
}
SOM_REGISTER(0xD3EA00, SOM_RTL, "gen", initialize_spell_entity_burst_sprites_long, 0, 0, 1, 1, 0, 4, 2)
