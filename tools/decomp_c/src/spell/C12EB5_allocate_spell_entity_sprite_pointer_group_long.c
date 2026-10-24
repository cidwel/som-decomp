#include "som_c.h"

/* C12EB5 allocate_spell_entity_sprite_pointer_group_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/allocate_spell_entity_sprite_pointer_group_long.s
 * Documented in docs/actor-cast-entity-sprite-groups.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: Y.
 */
static void allocate_spell_entity_sprite_pointer_group_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2EB7, 0xC1392B); GUARD_JSR(c, sp_call, 0x2EB7); } /* allocate_spell_entity_sprite_pointer_group */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC12EB5, SOM_RTL, "hand", allocate_spell_entity_sprite_pointer_group_long, 0, L_Y, 1, 1, 0, 4, 2)
