#include "som_c.h"

/* C12EB9 release_spell_entity_sprite_pointer_group_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/release_spell_entity_sprite_pointer_group_long.s
 * Documented in docs/actor-cast-entity-sprite-groups.md
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: BYCV.
 */
static void release_spell_entity_sprite_pointer_group_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2EBB, 0xC1395B); GUARD_JSR(c, sp_call, 0x2EBB); } /* release_spell_entity_sprite_pointer_group */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC12EB9, SOM_RTL, "gen", release_spell_entity_sprite_pointer_group_long, 0, L_B | L_Y | L_C | L_V, 1, -1, 0, 4, 2)
