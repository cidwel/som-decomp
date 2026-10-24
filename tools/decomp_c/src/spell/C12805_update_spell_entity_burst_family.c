#include "som_c.h"

/* C12805 update_spell_entity_burst_family   [class A, 5 bytes, 2 instructions]
 * Source: src/rom/update_spell_entity_burst_family.s
 * Documented in docs/actor-cast-entity-burst-init.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void update_spell_entity_burst_family(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSL(c, 0x2808, 0xD3ED09); GUARD_JSL(c, sp_call, 0x2808); } /* update_spell_entity_burst_sprite_object_long */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12805, SOM_RTS, "hand", update_spell_entity_burst_family, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 5, 2)
