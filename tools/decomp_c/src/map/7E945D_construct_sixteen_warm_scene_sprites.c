#include "som_c.h"
#include "som_hand_d.h"

/* 7E945D construct_sixteen_warm_scene_sprites   [class B, 98 bytes, 49 instructions]
 * Source: src/boot/construct_sixteen_warm_scene_sprites.s
 * Documented in docs/boot-native-warm-sprite-setup.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: XYCZNV.
 */
#define ABSX(off) ((((uint32_t)r->db << 16) + (off) + r->x) & 0xFFFFFF)
#define ABS(off) ((((uint32_t)r->db << 16) + (off)) & 0xFFFFFF)
/* The code after each call is assembled for 16-bit A and index registers. */
#define CALL_WIDE(retpc, target) do { const uint16_t sp_call = r->sp; JSR(c, (retpc), (target)); GUARD_JSR_DB(c, sp_call, (retpc), 0x7E); HAND_REQUIRE_WIDE(c); } while (0)

static void construct_sixteen_warm_scene_sprites(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, -1, -1)) return;
L_7E945D:;
    i_phd(c);
    i_php(c);
    i_rep(r, 0x30);
    i_tsc(r);
    r->c = 1;
    a_sbc(r, 0x4);
    i_tcd(r);
    i_tcs(r);
    a_lda(r, 0x10);
    STA(c, DP, 0x1);
L_7E946D:;
    a_lda(r, 0xb);
    JSR(c, 0x9472, 0x7EB6D0);
    STX(c, DP, 0x3);
    REQUIRE_M16(c);
    a_lda(r, 0x0);
    JSR(c, 0x947a, 0x7EC288);
    LDX(c, DP, 0x3);
    STA(c, ABX, 0x4);
    REQUIRE_M16(c);
    a_lda(r, 0x68);
    JSR(c, 0x9485, 0x7EC288);
    r->c = 0;
    REQUIRE_M16(c);
    a_adc(r, 0x38);
    LDX(c, DP, 0x3);
    STA(c, ABX, 0x2);
    REQUIRE_M16(c);
    a_lda(r, 0x4);
    JSR(c, 0x9494, 0x7EC288);
    r->c = 0;
    REQUIRE_M16(c);
    a_adc(r, 0x1c);
    LDX(c, DP, 0x3);
    STA(c, ABX, 0x6);
    STZ(c, ABX, 0x0);
    JSR(c, 0x94a3, 0x7EB7B9);
    LDA(c, DP, 0x1);
    i_deca(r);
    i_asla(r);
    r->c = 0;
    ADC(c, ABS, 0x7c);
    i_tax(r);
    LDA(c, DP, 0x3);
    STA(c, ABX, 0x0);
    DEC(c, DP, 0x1);
    if (!r->z) goto L_7E946D;
    i_sep(r, 0x20);
    i_pla(c);
    i_pla(c);
    i_pla(c);
    i_pla(c);
    i_plp(c);
    i_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E945D, SOM_RTS, "hand", construct_sixteen_warm_scene_sprites, 0, L_X | L_Y | L_C | L_Z | L_N | L_V, 7, 1, 0, 98, 49)
