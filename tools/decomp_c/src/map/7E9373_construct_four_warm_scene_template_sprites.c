#include "som_c.h"
#include "som_hand_d.h"
/* SOM_PLAIN_CALLS: every memory access below goes through the live DB / D registers, so a callee that returns with another data
 * bank is followed exactly and needs no data-bank check. */
#undef JSR
#undef JSL
#define JSR(c, retpc, target) CALL_JSR((c), (retpc), (target))
#define JSL(c, retpc, target) CALL_JSL((c), (retpc), (target))

/* 7E9373 construct_four_warm_scene_template_sprites   [class B, 129 bytes, 64 instructions]
 * Source: src/boot/construct_four_warm_scene_template_sprites.s
 * Documented in docs/boot-native-warm-cluster-setup.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: YCV.
 */
static void construct_four_warm_scene_template_sprites(SomCtx *c)
{
    Cpu *r = &c->cpu;
L_7E9373:;
    i_phd(c);
    i_php(c);
    i_rep(r, 0x30);
    i_tsc(r);
    r->c = 1;
    a_sbc(r, 0x6);
    i_tcd(r);
    i_tcs(r);
    a_lda(r, 0x4);
    STA(c, DP, 0x1);
    LDA(c, ABS, 0x7e);
    STA(c, DP, 0x5);
    a_lda(r, 0x3);
    JSR(c, 0x938d, 0x7EC288);
    STA(c, DP, 0x3);
    i_asla(r);
    r->c = 0;
    ADC(c, DP, 0x3);
    i_asla(r);
    i_asla(r);
    STA(c, DP, 0x3);
L_7E9398:;
    REQUIRE_M16(c);
    a_lda(r, 0xb);
    JSR(c, 0x939d, 0x7EB6D0);
    i_txa(r);
    LDY(c, DP, 0x5);
    STA(c, ABY, 0x0);
    i_iny(r);
    i_iny(r);
    STY(c, DP, 0x5);
    STZ(c, ABX, 0x0);
    STZ(c, ABX, 0x2);
    STZ(c, ABX, 0x4);
    STZ(c, ABX, 0x6);
    i_txy(r);
    LDX(c, DP, 0x3);
    i_sep(r, 0x20);
    LDA(c, ALX, 0x7e5eee);
    r->c = 0;
    a_adc(r, 0x38);
    STA(c, ABY, 0x2);
    i_inx(r);
    LDA(c, ALX, 0x7e5eee);
    STA(c, ABY, 0x4);
    i_inx(r);
    LDA(c, ALX, 0x7e5eee);
    a_and(r, 0x3f);
    STA(c, ABY, 0x6);
    LDA(c, ALX, 0x7e5eee);
    a_and(r, 0xc0);
    STA(c, ABY, 0x0);
    i_inx(r);
    STX(c, DP, 0x3);
    i_tyx(r);
    JSR(c, 0x93e4, 0x7EB7B9);
    i_rep(r, 0x20);
    DEC(c, DP, 0x1);
    if (!r->z) goto L_7E9398;
    i_tsc(r);
    r->c = 0;
    a_adc(r, 0x6);
    i_tcs(r);
    i_plp(c);
    i_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E9373, SOM_RTS, "hand", construct_four_warm_scene_template_sprites, 0, L_Y | L_C | L_V, 9, 1, 0, 129, 64)
