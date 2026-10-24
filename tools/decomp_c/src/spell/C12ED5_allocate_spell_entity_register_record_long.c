#include "som_c.h"

/* C12ED5 allocate_spell_entity_register_record_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/allocate_spell_entity_register_record_long.s
 * Documented in docs/actor-cast-entity-trail-state.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: XYCV.
 */
static void allocate_spell_entity_register_record_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2ED7, 0xC144B3); GUARD_JSR(c, sp_call, 0x2ED7); } /* allocate_spell_entity_register_record */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC12ED5, SOM_RTL, "hand", allocate_spell_entity_register_record_long, 0, L_X | L_Y | L_C | L_V, 1, 1, 0, 4, 2)
