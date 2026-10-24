#include "som_c.h"

/* C12EDD initialize_spell_entity_orbit_family   [class A, 5 bytes, 2 instructions]
 * Source: src/rom/initialize_spell_entity_orbit_family.s
 * Documented in docs/actor-cast-entity-orbit-callbacks.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void initialize_spell_entity_orbit_family(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSL(c, 0x2EE0, 0xD3F228); GUARD_JSL(c, sp_call, 0x2EE0); } /* initialize_spell_entity_orbit_sprites_long */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12EDD, SOM_RTS, "gen", initialize_spell_entity_orbit_family, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 5, 2)
