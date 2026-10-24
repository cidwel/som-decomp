#include "som_c.h"

/* C282AB cast_right_spell06   [class A, 7 bytes, 3 instructions]
 * Source: src/rom/cast_right_spell06.s
 * Documented in docs/boss-native58-cast.md
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void cast_right_spell06(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    r->a = 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0x82B0, 0xC282E4); GUARD_JSR(c, sp_call, 0x82B0); } /* cast_selected_spell_at_parent_target_and_execute_success */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC282AB, SOM_RTS, "gen", cast_right_spell06, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 7, 3)
