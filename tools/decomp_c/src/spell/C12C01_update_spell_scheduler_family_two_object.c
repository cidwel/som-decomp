#include "som_c.h"
#include "som_hand_b.h"

/* C12C01 update_spell_scheduler_family_two_object   [class A, 5 bytes, 2 instructions]
 * Source: src/rom/update_spell_scheduler_family_two_object.s
 * Documented in docs/actor-cast-entity-mode-two.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void update_spell_scheduler_family_two_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSL(c, 0x2C04, 0xDCFA6A); GUARD_JSL(c, sp_call, 0x2C04); } /* update_spell_family_two_object_long */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12C01, SOM_RTS, "hand", update_spell_scheduler_family_two_object, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 5, 2)
