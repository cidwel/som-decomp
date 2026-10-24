#include "som_c.h"

/* C282B9 cast_right_spell08_variant_one   [class A, 7 bytes, 3 instructions]
 * Source: src/rom/cast_right_spell08_variant_one.s
 * Documented in docs/boss-native58-cast.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void cast_right_spell08_variant_one(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    r->a = 8;
    { const uint16_t sp_call = r->sp; JSR(c, 0x82BE, 0xC282E4); GUARD_JSR(c, sp_call, 0x82BE); } /* cast_selected_spell_at_parent_target_and_execute_success */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC282B9, SOM_RTS, "gen", cast_right_spell08_variant_one, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 7, 3)
