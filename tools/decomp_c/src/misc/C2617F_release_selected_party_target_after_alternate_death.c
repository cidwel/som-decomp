#include "som_c.h"

/* C2617F release_selected_party_target_after_alternate_death   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/release_selected_party_target_after_alternate_death.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void release_selected_party_target_after_alternate_death(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6181, 0xC26273); GUARD_JSR(c, sp_call, 0x6181); } /* release_party_control_and_restore_boss_palette_music */
    r->mf = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2617F, SOM_RTS, "gen", release_selected_party_target_after_alternate_death, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 4, 2)
