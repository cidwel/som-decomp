#include "som_c.h"

/* C14801 initialize_spell_entity_trail_family   [class A, 5 bytes, 2 instructions]
 * Source: src/rom/initialize_spell_entity_trail_family.s
 * Documented in docs/actor-cast-entity-trail-init.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void initialize_spell_entity_trail_family(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSL(c, 0x4804, 0xD3F831); GUARD_JSL(c, sp_call, 0x4804); } /* initialize_spell_entity_trail_sprites_long */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC14801, SOM_RTS, "gen", initialize_spell_entity_trail_family, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 5, 2)
