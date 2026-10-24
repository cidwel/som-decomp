#include "som_c.h"

/* C12BE8 initialize_spell_entity_summon_scheduler_family   [class A, 5 bytes, 2 instructions]
 * Source: src/rom/initialize_spell_entity_summon_scheduler_family.s
 * Documented in docs/actor-entity-summon-wrappers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$01B4.  Callers read: ABXYCZNV.
 */
static void initialize_spell_entity_summon_scheduler_family(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01B4) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSL(c, 0x2BEB, 0xD3EE5C); GUARD_JSL(c, sp_call, 0x2BEB); } /* initialize_spell_entity_summon_sprites_long */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12BE8, SOM_RTS, "hand", initialize_spell_entity_summon_scheduler_family, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 5, 2)
