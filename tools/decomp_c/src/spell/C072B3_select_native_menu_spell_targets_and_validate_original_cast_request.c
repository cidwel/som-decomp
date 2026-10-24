#include "som_c.h"
#include "som_hand_d.h"

/* C072B3 select_native_menu_spell_targets_and_validate_original_cast_request   [class B, 108 bytes, 39 instructions]
 * Source: src/rom/select_native_menu_spell_targets_and_validate_original_cast_request.s
 * Documented in docs/event-menu-weapon-action.md
 * Entry: M=any (Snes9x captures enter with M=8 and M=16; the first instructions are JSLs that do not read M) X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void select_native_menu_spell_targets_and_validate_original_cast_request(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, 0)) return;
L_C072B3:;
    JSL(c, 0x72b6, 0xC06B4C);
    JSL(c, 0x72ba, 0xD0CE5D);
    i_sep(r, 0x20);
    STA(c, ABS, 0x19d3);
    i_rep(r, 0x30);
    JSL(c, 0x72c5, 0xC073AC);
    if (r->c) goto L_C072CF;
    JSL(c, 0x72cb, 0xD0CF00);
    TAIL_CALL(c, 0xC0692D, SOM_RTS);
L_C072CF:;
    i_sep(r, 0x20);
    STA(c, ABS, 0x185b);
    STX(c, ABS, 0x182c);
    JSL(c, 0x72da, 0xD0DA60);
    if (r->z) goto L_C072E6;
    JSL(c, 0x72e0, 0xD0DB58);
    if (r->z) goto L_C072FD;
    TAIL_CALL(c, 0xC07275, SOM_RTS);
L_C072E6:;
    JSL(c, 0x72e9, 0xD0CF00);
L_C072EA:;
    i_rep(r, 0x20);
    JSR(c, 0x72ee, 0xC0695E);
    JSR(c, 0x72f1, 0xC06BF8);
    LDA(c, ABS, 0x1800);
    REQUIRE_M16(c);
    a_and(r, 0x8000);
    if (!r->z) goto L_C072EA;
    TAIL_CALL(c, 0xC07275, SOM_RTS);
L_C072FD:;
    JSL(c, 0x7300, 0xD0CF08);
    i_sep(r, 0x20);
    LDA(c, ABS, 0x1808);
    STA(c, ABS, 0x19f1);
    JSR(c, 0x730b, 0xC0787E);
    JSR(c, 0x730e, 0xC0731F);
    i_rep(r, 0x30);
    LDA(c, ABS, 0x1808);
    a_and(r, 0x3);
    i_xba(r);
    i_asla(r);
    i_tax(r);
    JSL(c, 0x731d, 0xC0001B);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC072B3, SOM_RTS, "hand", select_native_menu_spell_targets_and_validate_original_cast_request, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, -1, 0, 108, 39)
