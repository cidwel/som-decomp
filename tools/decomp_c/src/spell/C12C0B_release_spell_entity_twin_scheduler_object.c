#include "som_c.h"
#include "som_hand_b.h"

/* C12C0B release_spell_entity_twin_scheduler_object   [class A, 5 bytes, 2 instructions]
 * Source: src/rom/release_spell_entity_twin_scheduler_object.s
 * Documented in docs/actor-cast-entity-twin-callbacks.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void release_spell_entity_twin_scheduler_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSL(c, 0x2C0E, 0xC12D34); GUARD_JSL(c, sp_call, 0x2C0E); } /* release_spell_entity_twin_sprite_object_long */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12C0B, SOM_RTS, "hand", release_spell_entity_twin_scheduler_object, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 5, 2)
