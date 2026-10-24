#include "som_c.h"
#include "som_hand_b.h"

/* C12BF2 release_spell_entity_summon_scheduler_object   [class A, 5 bytes, 2 instructions]
 * Source: src/rom/release_spell_entity_summon_scheduler_object.s
 * Documented in docs/actor-entity-summon-wrappers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
/* A callee that replaces its own return address: the interpreter continues from the popped address (see som_hand_b.h). */
#undef I_JSL
#define I_JSL(c, retpc, target) HAND_JSL_RESUME(c, retpc, target, sp0)

static void release_spell_entity_summon_scheduler_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    const uint16_t sp0 = r->sp;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    JSL(c, 0x2BF5, 0xD3EE14); /* release_temporary_spell_sprite_object_long */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12BF2, SOM_RTS, "hand", release_spell_entity_summon_scheduler_object, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 5, 2)
