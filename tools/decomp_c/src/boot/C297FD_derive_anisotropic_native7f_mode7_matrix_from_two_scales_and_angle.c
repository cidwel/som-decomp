#include "som_c.h"
#include "som_hand_b.h"

/* C297FD derive_anisotropic_native7f_mode7_matrix_from_two_scales_and_angle   [class B, 112 bytes, hand written]
 * Source: src/rom/derive_anisotropic_native7f_mode7_matrix_from_two_scales_and_angle.s
 * Documented in docs/boss-native7f-setup.md
 *
 * Derives the four Mode 7 matrix words from two scales ($B0/$B2,X) and an angle ($B4,X) of the boss record the
 * pointer $87 selects:   $9D = cos * scale1   $9F = sin * scale1   $A1 = -sin * scale2   $A3 = cos * scale2
 * and publishes them at $02CD..$02D3.  Every load and store takes the accumulator width the code runs in (the
 * entry width, then whatever the sine, cosine and multiply helpers return), so one body serves M=8 and M=16.
 */
static void derive_anisotropic_native7f_mode7_matrix_from_two_scales_and_angle(SomCtx *c)
{
    Cpu *r = &c->cpu;
    const uint32_t bank = (uint32_t)r->db << 16;
    hand_ldx_dp(c, 0x87);                        /* LDX $87 */
    if (!hand_lda_abs(c, bank + 0x00B0 + r->x)) return; hand_sta_dp(c, 0x95);   /* LDA $00B0,X ; STA $95 */
    if (!hand_lda_abs(c, bank + 0x00B2 + r->x)) return; hand_sta_dp(c, 0x97);   /* LDA $00B2,X ; STA $97 */
    if (!hand_lda_abs(c, bank + 0x00B4 + r->x)) return;       /* LDA $00B4,X */
    { const uint16_t sp_call = r->sp; JSR(c, 0x980E, 0xC22A60); GUARD_JSR(c, sp_call, 0x980E); }   /* mask_angle_and_derive_native_sine */
    hand_sta_dp(c, 0x99);                        /* STA $99 */
    hand_ldx_dp(c, 0x87);                        /* LDX $87 */
    if (!hand_lda_abs(c, ((uint32_t)r->db << 16) + 0x00B4 + r->x)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9818, 0xC22A59); GUARD_JSR(c, sp_call, 0x9818); }   /* derive_cosine_by_adding_quarter_turn */
    hand_sta_dp(c, 0x9B); hand_sta_dp(c, 0x46);  /* STA $9B ; STA $46 */
    hand_lda_dp(c, 0x95); hand_sta_dp(c, 0x4E);  /* LDA $95 ; STA $4E */
    { const uint16_t sp_call = r->sp; JSR(c, 0x9823, 0xC22B94); GUARD_JSR(c, sp_call, 0x9823); }   /* multiply_signed_words_to_double_word */
    hand_lda_dp(c, 0x57); hand_sta_dp(c, 0x9D);  /* LDA $57 ; STA $9D */
    hand_lda_dp(c, 0x99); hand_sta_dp(c, 0x46);
    hand_lda_dp(c, 0x95); hand_sta_dp(c, 0x4E);
    { const uint16_t sp_call = r->sp; JSR(c, 0x9832, 0xC22B94); GUARD_JSR(c, sp_call, 0x9832); }   /* multiply_signed_words_to_double_word */
    hand_lda_dp(c, 0x57); hand_sta_dp(c, 0x9F);  /* LDA $57 ; STA $9F */
    hand_lda_dp(c, 0x99);                        /* LDA $99 ; EOR $C7 ; INC */
    { uint16_t m = r->mf ? dp_rd8(c, 0xC7) : dp_rd16(c, 0xC7); a_eor(r, m); }
    { uint16_t v = m_inc(r, r->a); r->a = r->mf ? ((r->a & 0xFF00) | (v & 0xFF)) : v; }
    hand_sta_dp(c, 0x46);                        /* STA $46 */
    hand_lda_dp(c, 0x97); hand_sta_dp(c, 0x4E);
    { const uint16_t sp_call = r->sp; JSR(c, 0x9844, 0xC22B94); GUARD_JSR(c, sp_call, 0x9844); }   /* multiply_signed_words_to_double_word */
    hand_lda_dp(c, 0x57); hand_sta_dp(c, 0xA1);  /* LDA $57 ; STA $A1 */
    hand_lda_dp(c, 0x9B); hand_sta_dp(c, 0x46);
    hand_lda_dp(c, 0x97); hand_sta_dp(c, 0x4E);
    { const uint16_t sp_call = r->sp; JSR(c, 0x9853, 0xC22B94); GUARD_JSR(c, sp_call, 0x9853); }   /* multiply_signed_words_to_double_word */
    hand_lda_dp(c, 0x57); hand_sta_dp(c, 0xA3);  /* LDA $57 ; STA $A3 */
    hand_lda_dp(c, 0x9D); hand_sta_abs(c, ((uint32_t)r->db << 16) + 0x02CD);   /* LDA $9D ; STA $02CD */
    hand_lda_dp(c, 0x9F); hand_sta_abs(c, ((uint32_t)r->db << 16) + 0x02CF);
    hand_lda_dp(c, 0xA1); hand_sta_abs(c, ((uint32_t)r->db << 16) + 0x02D1);
    hand_lda_dp(c, 0xA3); hand_sta_abs(c, ((uint32_t)r->db << 16) + 0x02D3);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC297FD, SOM_RTS, "hand", derive_anisotropic_native7f_mode7_matrix_from_two_scales_and_angle, 0, 0, 1, -1, -1, 112, 50)
