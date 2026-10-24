#include "som_c.h"

/* C272FF complete_descriptor_seven_alternate_event_death   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/complete_descriptor_seven_alternate_event_death.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void complete_descriptor_seven_alternate_event_death(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7301, 0xC20BCE); GUARD_JSR(c, sp_call, 0x7301); } /* advance_alternate_boss_death_callback_effects_and_event_gates */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC272FF, SOM_RTS, "gen", complete_descriptor_seven_alternate_event_death, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 4, 2)
