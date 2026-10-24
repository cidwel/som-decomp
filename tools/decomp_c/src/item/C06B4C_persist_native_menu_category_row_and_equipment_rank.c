#include "som_c.h"
#include "som_hand_d.h"
/* SOM_PLAIN_CALLS: every memory access below goes through the live DB / D registers, so a callee that returns with another data
 * bank is followed exactly and needs no data-bank check. */
#undef JSR
#undef JSL
#define JSR(c, retpc, target) CALL_JSR((c), (retpc), (target))
#define JSL(c, retpc, target) CALL_JSL((c), (retpc), (target))

/* C06B4C persist_native_menu_category_row_and_equipment_rank   [class B, 150 bytes, 66 instructions]
 * Source: src/rom/persist_native_menu_category_row_and_equipment_rank.s
 * Documented in docs/event-menu-navigation-icons.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void persist_native_menu_category_row_and_equipment_rank(SomCtx *c)
{
    Cpu *r = &c->cpu;
L_C06B4C:;
    i_rep(r, 0x30);
    LDA(c, ABS, 0x1808);
    a_and(r, 0xff);
    r->c = 0;
    a_adc(r, 0x1870);
    i_tax(r);
    i_sep(r, 0x20);
    a_lda(r, 0x8);
    BIT(c, ABS, 0x1803);
    if (r->z) goto L_C06B65;
    goto L_C06BD2;
L_C06B65:;
    LDA(c, ABS, 0x1809);
    STA(c, DPX, 0x0);
    JSL(c, 0x6b6d, 0xC06BE2);
    LDA(c, ABS, 0x1809);
    REQUIRE_M8(c);
    a_cmp(r, 0x3);
    if (r->c) goto L_C06BD2;
    REQUIRE_X16(c);
    a_ldx(r, 0x1873);
    REQUIRE_M8(c);
    a_ora(r, 0x0);
    if (r->z) goto L_C06BCD;
    REQUIRE_X16(c);
    a_ldx(r, 0x1876);
    i_deca(r);
    if (!r->z) goto L_C06BCD;
    LDA(c, ABS, 0x1808);
    REQUIRE_M8(c);
    a_cmp(r, 0x1);
    if (!r->z) goto L_C06BAA;
    REQUIRE_X16(c);
    a_ldx(r, 0x1874);
    LDA(c, ABS, 0x1803);
    if (!r->n) goto L_C06BCD;
    i_rep(r, 0x20);
    JSL(c, 0x6b96, 0xD0D0B0);
    i_sep(r, 0x20);
    LDA(c, ABS, 0x1835);
    a_and(r, 0x3);
    i_asla(r);
    i_asla(r);
    i_asla(r);
    i_asla(r);
    i_pha(c);
    LDA(c, ABX, 0x1878);
    a_and(r, 0x3);
    goto L_C06BC5;
L_C06BAA:;
    REQUIRE_X16(c);
    a_ldx(r, 0x1875);
    LDA(c, ABS, 0x1803);
    if (!r->n) goto L_C06BCD;
    i_rep(r, 0x20);
    JSL(c, 0x6bb7, 0xD0D0DA);
    i_sep(r, 0x20);
    LDA(c, ABS, 0x1835);
    a_and(r, 0x3);
    i_pha(c);
    LDA(c, ABX, 0x1878);
    a_and(r, 0x30);
L_C06BC5:;
    ORA(c, SR, 0x1);
    STA(c, ABX, 0x1878);
    i_pla(c);
    goto L_C06BD2;
L_C06BCD:;
    LDA(c, ABS, 0x1835);
    STA(c, DPX, 0x0);
L_C06BD2:;
    i_sep(r, 0x20);
    LDA(c, ABS, 0x1808);
    CMP(c, ABS, 0x1805);
    if (r->z) goto L_C06BDF;
    STA(c, ABS, 0x1877);
L_C06BDF:;
    i_rep(r, 0x20);
    RETURN_RTL(c);
}
SOM_REGISTER(0xC06B4C, SOM_RTL, "hand", persist_native_menu_category_row_and_equipment_rank, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 150, 66)
