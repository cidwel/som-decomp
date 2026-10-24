#include "som_c.h"

/* C20250 emit_alternating_boss_objects_with_saved_context   [class A, 22 bytes, 15 instructions]
 * Source: src/rom/emit_alternating_boss_objects_with_saved_context.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void emit_alternating_boss_objects_with_saved_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    i_php(c);
    i_phd(c);
    i_phb(c);
    i_sep(r, 0x20);
    a_lda(r, 0x7E);
    i_pha(c);
    i_plb(c);
    i_rep(r, 0x30);
    a_lda(r, 0x0200);
    i_tcd(r);
    { const uint16_t sp_call = r->sp; JSR(c, 0x0261, 0xC2133F); GUARD_JSR(c, sp_call, 0x0261); } /* emit_nine_boss_objects_on_alternating_phases */
    hand_plb(c);
    hand_pld(c);
    hand_plp(c);
    RETURN_RTL(c);
}
SOM_REGISTER(0xC20250, SOM_RTL, "hand", emit_alternating_boss_objects_with_saved_context, 0, L_B | L_X | L_Y | L_C | L_V, 5, 0, 0, 22, 15)
