#include "som_c.h"

/* C12BED update_spell_entity_summon_scheduler_object   [class A, 5 bytes, 2 instructions]
 * Source: src/rom/update_spell_entity_summon_scheduler_object.s
 * Documented in docs/actor-entity-summon-wrappers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void update_spell_entity_summon_scheduler_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    JSL(c, 0x2BF0, 0xD3F159); /* update_spell_sprite_object_long */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12BED, SOM_RTS, "hand", update_spell_entity_summon_scheduler_object, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 5, 2)
