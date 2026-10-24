#include "som_c.h"

/* C7695B append_native_party_status_remaining_experience_unless_level99   [class B, 29 bytes, 12 instructions]
 * Source: src/rom/append_native_party_status_remaining_experience_unless_level99.s
 * Documented in docs/ui-native-party-status-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void append_native_party_status_remaining_experience_unless_level99(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t value = RAM8(0xA16E);
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool zero1;
    bool overflow1;
    if (value == 0x63) {
        a1 = value;
        a_hi1 = a_hi;
        x1 = x;
        y1 = y;
        carry1 = value >= 0x63;
        zero1 = value == 0x63;
        overflow1 = overflow;
    } else {
        r->a = (a_hi << 8) | value;
        r->y = 0x7B41;
        r->c = value >= 0x63;
        JSR(c, 0x6967, 0xC76ABE); /* select_bank_C7_and_copy_native_terminated_tokens */
        uint16_t x_ret = r->x;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 2;
        JSR(c, 0x696B, 0xC76A7B); /* subtract_native_party_status_statistic_vectors_with_borrow */
        r->sp += 2;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 2;
        JSL(c, 0x696F, 0xC754DB); /* convert_24_bit_dialogue_quantity_to_seven_digit_fields */
        r->sp += 2;
        r->x = x_ret;
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0x6973, 0xC754B0); /* append_seven_native_decimal_quantity_glyphs_with_leading_spaces */
        uint16_t a_all4 = r->a;
        uint16_t x_ret4 = r->x;
        uint16_t y_ret4 = r->y;
        bool carry_ret3 = r->c;
        bool zero_ret4 = r->z;
        bool overflow_ret3 = r->v;
        a1 = (uint8_t)a_all4;
        a_hi1 = a_all4 >> 8;
        x1 = x_ret4;
        y1 = y_ret4;
        carry1 = carry_ret3;
        zero1 = zero_ret4;
        overflow1 = overflow_ret3;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    JSR(c, 0x6976, 0xC7538D); /* append_native_saved_slot_text_line_token */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC7695B, SOM_RTS, "gen", append_native_party_status_remaining_experience_unless_level99, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 2, 1, 0, 29, 12)
