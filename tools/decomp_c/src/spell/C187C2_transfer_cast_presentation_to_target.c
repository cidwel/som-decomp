#include "som_c.h"
#include "som_hand_d.h"
/* SOM_PLAIN_CALLS: every memory access below goes through the live DB / D registers, so a callee that returns with another data
 * bank is followed exactly and needs no data-bank check. */
#undef JSR
#undef JSL
#define JSR(c, retpc, target) CALL_JSR((c), (retpc), (target))
#define JSL(c, retpc, target) CALL_JSL((c), (retpc), (target))

/* C187C2 transfer_cast_presentation_to_target   [class B, 214 bytes, 84 instructions]
 * Source: src/rom/transfer_cast_presentation_to_target.s
 * Documented in docs/actor-cast-coordinator.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCV.
 */
static void transfer_cast_presentation_to_target(SomCtx *c)
{
    Cpu *r = &c->cpu;
L_C187C2:;
    i_sep(r, 0x20);
    a_lda(r, 0x0);
    STA(c, ABY, 0xe121);
    STA(c, ABY, 0xe108);
    LDA(c, DP, 0xf1);
    if (r->n) goto L_C187E3;
    LDA(c, DP, 0xd0);
    if (r->z) goto L_C187E4;
    a_cpy(r, 0x600);
    if (!r->c) goto L_C187DF;
    CPY(c, DP, 0x3a);
    if (!r->z) goto L_C187E4;
    if (r->z) goto L_C187E3;
L_C187DF:;
    CPY(c, DP, 0xd4);
    if (!r->z) goto L_C187E4;
L_C187E3:;
    RETURN_RTS(c);
L_C187E4:;
    LDA(c, ABY, 0xe109);
    STA(c, ABY, 0xe110);
    LDA(c, ABY, 0xe10b);
    i_xba(r);
    LDA(c, ABY, 0xe10a);
    i_rep(r, 0x20);
    i_pha(c);
    i_tyx(r);
    JSR(c, 0x87f7, 0xC18654);
    i_txy(r);
    i_rep(r, 0x20);
    i_pla(c);
    JSR(c, 0x87fe, 0xC186DA);
    i_tax(r);
    i_sep(r, 0x20);
    LDA(c, ALX, 0xd02aa0);
    STA(c, ABY, 0xe04f);
    a_lda(r, 0xc0);
    STA(c, ABY, 0xe060);
    LDA(c, ABY, 0xe01c);
    STA(c, ABY, 0xe128);
    LDA(c, ABY, 0xe05d);
    STA(c, ABY, 0xe129);
    a_lda(r, 0x40);
    STA(c, ABY, 0xe01c);
    a_lda(r, 0x0);
    STA(c, ABY, 0xe114);
    STA(c, ABY, 0xe05d);
    STA(c, ABY, 0xe012);
    STA(c, ABY, 0xe00c);
    STA(c, ABY, 0xe025);
    STA(c, ABY, 0xe084);
    i_rep(r, 0x20);
    LDA(c, ABY, 0xe104);
    STA(c, ABY, 0xe12e);
    LDA(c, ABY, 0xe106);
    STA(c, ABY, 0xe124);
    LDA(c, ABY, 0xe05e);
    STA(c, ABY, 0xe12a);
    LDA(c, ABY, 0xe006);
    STA(c, ABY, 0xe134);
    LDA(c, ABY, 0xe008);
    STA(c, ABY, 0xe122);
    LDA(c, ALX, 0xd02aa6);
    STA(c, ABY, 0xe0fc);
    LDA(c, ALX, 0xd02aa2);
    STA(c, ABY, 0xe06a);
    a_lda(r, 0x0);
    STA(c, ABY, 0xe104);
    STA(c, ABY, 0xe006);
    STA(c, ABY, 0xe008);
    STA(c, ABY, 0xe118);
    STA(c, ABY, 0xe11a);
    STA(c, ABY, 0xe11c);
    STA(c, ABY, 0xe11e);
    i_sep(r, 0x20);
    LDA(c, ABY, 0xe110);
    a_cmp(r, 0x7);
    if (!r->z) goto L_C18891;
    a_lda(r, 0x0);
    STA(c, ABY, 0xe110);
    a_lda(r, 0xc0);
    STA(c, ABY, 0xe11a);
    a_lda(r, 0xff);
    STA(c, ABY, 0xe11b);
L_C18891:;
    LDA(c, ABY, 0xe04f);
    i_tyx(r);
    TAIL_CALL(c, 0xC1859B, SOM_RTS);
}
SOM_REGISTER(0xC187C2, SOM_RTS, "hand", transfer_cast_presentation_to_target, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 214, 84)
