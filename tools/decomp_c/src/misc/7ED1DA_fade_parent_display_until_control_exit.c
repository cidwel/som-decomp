#include "som_c.h"
#include "som_hand_d.h"
/* The callee yields to the parent task (stack switch): the plain call protocol returns at once, like the CPU. */
#undef JSR
#undef JSL
#define JSR(c, retpc, target) I_JSR((c), (retpc), (target))
#define JSL(c, retpc, target) I_JSL((c), (retpc), (target))

/* 7ED1DA fade_parent_display_until_control_exit   [class B, 51 bytes, 26 instructions]
 * Source: src/boot/fade_parent_display_until_control_exit.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7F D=$02EE.  Callers read: ABXYCV.
 */
static void fade_parent_display_until_control_exit(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x02EE) { c->fail = 3; return; }
L_7ED1DA:;
    i_phd(c);
    i_php(c);
    i_rep(r, 0x30);
    i_sep(r, 0x20);
L_7ED1E0:;
    a_ldx(r, 0x4);
    JSR(c, 0xd1e5, 0x7ED17F);
    REQUIRE_M8(c);
    a_cmp(r, 0x0);
    if (r->z) goto L_7ED20A;
    LDA(c, ABS, 0x314);
    if (!r->z) goto L_7ED1E0;
    REQUIRE_M8(c);
    a_lda(r, 0x0);
    JSR(c, 0xd1f3, 0x7EC030);
    LDA(c, ABX, 0x2);
    REQUIRE_M8(c);
    a_cmp(r, 0x0);
    if (r->z) goto L_7ED208;
    i_deca(r);
    STA(c, ABX, 0x2);
    i_pha(c);
    JSR(c, 0xd202, 0x7EC097);
    i_pla(c);
    REQUIRE_M8(c);
    a_cmp(r, 0x0);
    if (!r->z) goto L_7ED1E0;
L_7ED208:;
    REQUIRE_M8(c);
    a_lda(r, 0x1);
L_7ED20A:;
    i_plp(c);
    i_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0x7ED1DA, SOM_RTS, "hand", fade_parent_display_until_control_exit, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 4, 1, 0, 51, 26)
