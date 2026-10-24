#include "som_c.h"
#include "som_hand_d.h"

/* 7ED2FC open_title_scanline_window   [class B, 76 bytes, 39 instructions]
 * Source: src/boot/open_title_scanline_window.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYV.
 */
static void open_title_scanline_window(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
L_7ED2FC:;
    i_phd(c);
    i_php(c);
    i_rep(r, 0x30);
    i_phb(c);
    i_phx(c);
    i_tsc(r);
    i_tcd(r);
    i_sep(r, 0x20);
    a_lda(r, 0xe);
    JSR(c, 0xd30a, 0x7EC030);
    REQUIRE_M8(c);
    a_lda(r, 0x2f);
    STA(c, ABX, 0x2);
    JSR(c, 0xd312, 0x7EC097);
    REQUIRE_X16(c);
    a_ldx(r, 0x5ea0);
    REQUIRE_M8(c);
    a_lda(r, 0x7e);
    JSR(c, 0xd31a, 0x7EAB88);
    STA(c, ABS, 0x312);
    REQUIRE_X16(c);
    a_ldx(r, 0x0);
    STX(c, DP, 0x2);
L_7ED323:;
    LDX(c, DP, 0x2);
    i_inx(r);
    i_inx(r);
    REQUIRE_X16(c);
    a_cpx(r, 0x40);
    if (r->z) goto L_7ED32E;
    if (r->c) goto L_7ED340;
L_7ED32E:;
    STX(c, DP, 0x2);
    REQUIRE_X16(c);
    a_ldy(r, 0x70);
    JSR(c, 0xd335, 0x7ECE6B);
    REQUIRE_X16(c);
    a_ldx(r, 0x3);
    JSR(c, 0xd33b, 0x7ED17F);
    REQUIRE_M8(c);
    a_cmp(r, 0x0);
    if (!r->z) goto L_7ED323;
L_7ED340:;
    STA(c, SR, 0x3);
    i_pla(c);
    i_pla(c);
    i_pla(c);
    i_plp(c);
    i_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0x7ED2FC, SOM_RTS, "hand", open_title_scanline_window, 0, L_A | L_B | L_X | L_Y | L_V, 6, 1, 0, 76, 39)
