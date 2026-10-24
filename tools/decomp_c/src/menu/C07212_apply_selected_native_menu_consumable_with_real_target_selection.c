#include "som_c.h"
#include "som_hand_d.h"

/* C07212 apply_selected_native_menu_consumable_with_real_target_selection   [class C, 161 bytes, 66 instructions]
 * Source: src/rom/apply_selected_native_menu_consumable_with_real_target_selection.s
 * Documented in docs/event-menu-consumable-action.md
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: BXYCV.
 */
static void apply_selected_native_menu_consumable_with_real_target_selection(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, 0)) return;
L_C07212:;
    i_sep(r, 0x30);
    LDA(c, ABS, 0x1808);
    STA(c, ABS, 0x19f2);
    LDX(c, ABS, 0x1873);
    LDA(c, ALX, 0x7ecc48);
    a_and(r, 0x1f);
    STA(c, ABS, 0x19f1);
    a_cmp(r, 0x6);
    if (r->z) goto L_C0727F;
    a_cmp(r, 0x7);
    if (r->z) goto L_C0727F;
    i_sep(r, 0x30);
    a_lda(r, 0x0);
    STA(c, ABS, 0x1842);
    JSL(c, 0x7238, 0xD0DA60);
    if (r->z) goto L_C07271;
    JSL(c, 0x723e, 0xD0DB58);
    if (!r->z) goto L_C07275;
    JSL(c, 0x7244, 0xD0CF08);
    JSR(c, 0x7247, 0xC0787E);
    i_rep(r, 0x30);
    LDX(c, ABS, 0x1822);
    LDA(c, DPX, 0x0);
    a_and(r, 0xe00);
    i_tax(r);
    LDA(c, ABS, 0x19f1);
    JSL(c, 0x7259, 0xC0002A);
    i_sep(r, 0x30);
    LDA(c, ABS, 0x19f1);
    a_cmp(r, 0x8);
    if (r->z) goto L_C07270;
    a_cmp(r, 0x9);
    if (r->z) goto L_C07270;
    LDX(c, ABS, 0x1873);
    a_lda(r, 0xff);
    JSL(c, 0x726f, 0xC078C3);
L_C07270:;
    RETURN_RTS(c);
L_C07271:;
    JSL(c, 0x7274, 0xD0CF00);
L_C07275:;
    i_sep(r, 0x20);
    a_lda(r, 0x10);
    TSB(c, ABS, 0x1804);
    TAIL_CALL(c, 0xC0692D, SOM_RTS);
L_C0727F:;
    i_sep(r, 0x30);
    LDX(c, ABS, 0x19f1);
    a_lda(r, 0x80);
    a_cpx(r, 0x7);
    if (r->z) goto L_C07291;
    i_lsra(r);
    a_cpx(r, 0x6);
    if (r->z) goto L_C07291;
    goto L_C07296;
L_C07291:;
    BIT(c, ABS, 0x11f);
    if (r->z) goto L_C0729B;
L_C07296:;
    JSL(c, 0x7299, 0xD0CF08);
    RETURN_RTS(c);
L_C0729B:;
    LDA(c, ABS, 0x19f1);
    r->c = 0;
    REQUIRE_M8(c);
    a_adc(r, 0x38);
    i_asla(r);
    i_tax(r);
    i_rep(r, 0x30);
    LDA(c, ALX, 0xca0b82);
    i_tax(r);
    a_lda(r, 0xca);
    JSL(c, 0x72b0, 0xD0D5B5);
    goto L_C07271;
}
SOM_REGISTER(0xC07212, SOM_RTS, "hand", apply_selected_native_menu_consumable_with_real_target_selection, 0, L_B | L_X | L_Y | L_C | L_V, 1, -1, 0, 161, 66)
