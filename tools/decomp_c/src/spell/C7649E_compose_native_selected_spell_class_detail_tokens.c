#include "som_c.h"
#include "som_hand_d.h"

/* C7649E compose_native_selected_spell_class_detail_tokens   [class B, 116 bytes, 58 instructions]
 * Source: src/rom/compose_native_selected_spell_class_detail_tokens.s
 * Documented in docs/ui-native-spell-item-detail.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: nothing.
 */
static void compose_native_selected_spell_class_detail_tokens(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
L_C7649E:;
    JSR(c, 0x64a0, 0xC76BCF);
    LDA(c, ABS, 0xa211);
    STA(c, ABS, 0xa175);
    JSR(c, 0x64a9, 0xC76661);
    REQUIRE_M8(c);
    a_and(r, 0x3f);
    if (r->z) goto L_C7650E;
    i_pha(c);
    i_rep(r, 0x20);
    LDA(c, ABS, 0xa211);
    a_and(r, 0xff);
    i_asla(r);
    STA(c, ABS, 0xa173);
    i_asla(r);
    r->c = 0;
    ADC(c, ABS, 0xa173);
    i_sep(r, 0x20);
    REQUIRE_X16(c);
    a_ldy(r, 0x6);
    REQUIRE_X16(c);
    a_ldx(r, 0x0);
    STA(c, ABS, 0xa1d0);
    i_pla(c);
L_C764CC:;
    i_lsra(r);
    if (!r->c) goto L_C76508;
    i_pha(c);
    a_lda(r, 0x56);
    STA(c, ABX, 0x9c00);
    i_inx(r);
    LDA(c, ABS, 0xa1d0);
    a_cmp(r, 0x2a);
    if (!r->c) goto L_C764E0;
    r->c = 1;
    a_sbc(r, 0x6);
L_C764E0:;
    STA(c, ABX, 0x9c00);
    i_pha(c);
    i_inx(r);
    a_lda(r, 0x8);
    JSR(c, 0x64e9, 0xC759E0);
    REQUIRE_M8(c);
    a_lda(r, 0xc5);
    STA(c, ABX, 0x9c00);
    i_inx(r);
    REQUIRE_M8(c);
    a_lda(r, 0x0);
    i_xba(r);
    i_pla(c);
    i_rep(r, 0x20);
    i_asla(r);
    i_phx(c);
    i_tax(r);
    LDA(c, ALX, 0xca0b2e);
    i_tay(r);
    i_sep(r, 0x20);
    i_plx(c);
    JSR(c, 0x6503, 0xC76AB7);
    JSR(c, 0x6506, 0xC7538D);
    i_pla(c);
L_C76508:;
    INC(c, ABS, 0xa1d0);
    i_dey(r);
    if (!r->z) goto L_C764CC;
L_C7650E:;
    JSR(c, 0x6510, 0xC76512);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC7649E, SOM_RTS, "hand", compose_native_selected_spell_class_detail_tokens, 0, 0, 4, 1, 0, 116, 58)
