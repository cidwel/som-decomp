#include "som_c.h"

/* C12EC9 scale_spell_entity_signed_angle_vector_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/scale_spell_entity_signed_angle_vector_long.s
 * Documented in docs/actor-cast-entity-signed-vectors.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: XY.
 */
static void scale_spell_entity_signed_angle_vector_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2ECB, 0xC149EC); GUARD_JSR(c, sp_call, 0x2ECB); } /* scale_spell_entity_signed_angle_vector */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC12EC9, SOM_RTL, "gen", scale_spell_entity_signed_angle_vector_long, 0, L_X | L_Y, 1, 1, 0, 4, 2)
