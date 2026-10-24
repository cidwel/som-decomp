#include "som_c.h"

/* C12ECD scale_spell_entity_signed_quarter_turn_vector_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/scale_spell_entity_signed_quarter_turn_vector_long.s
 * Documented in docs/actor-cast-entity-signed-vectors.md
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: X.
 */
static void scale_spell_entity_signed_quarter_turn_vector_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2ECF, 0xC14AA8); GUARD_JSR(c, sp_call, 0x2ECF); } /* scale_spell_entity_signed_quarter_turn_vector */
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC12ECD, SOM_RTL, "gen", scale_spell_entity_signed_quarter_turn_vector_long, 0, L_X, 1, -1, 0, 4, 2)
