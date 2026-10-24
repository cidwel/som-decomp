#include "som_c.h"

/* C75979 render_four_native_saved_slot_descriptions   [class B, 103 bytes, 37 instructions]
 * Source: src/rom/render_four_native_saved_slot_descriptions.s
 * Documented in docs/ui-native-loaded-game-slot-descriptions.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void render_four_native_saved_slot_descriptions(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    RAM8(0xA162) = 0;
    r->a = (a_hi << 8) | 0;
    JSR(c, 0x5980, 0xC75BCA); /* validate_four_native_save_slot_signatures_copies_and_checksums */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    RAM8(0xA216) = RAM8(0xA215);
    uint8_t a_hi1 = a_all >> 8;
    uint16_t x1 = x_ret;
    uint16_t y1 = y_ret;
    bool carry1 = carry_ret;
    bool overflow1 = overflow_ret;
    for (;;) {
        RAM8(0xA1D4) = 0;
        r->a = (a_hi1 << 8) | a;
        r->y = y1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        JSR(c, 0x598C, 0xC759EC); /* append_valid_native_saved_slot_level */
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0x598F, 0xC75AAB); /* append_native_saved_slot_name_or_empty_label */
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0x5992, 0xC7538D); /* append_native_saved_slot_text_line_token */
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0x5995, 0xC75386); /* append_two_native_saved_slot_text_space_tokens */
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0x5998, 0xC75389); /* append_native_saved_slot_text_space_token */
        RAM8(0xA177) = 0;
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0x599E, 0xC759FC); /* append_two_valid_native_saved_slot_statistics */
        RAM16_SET(0xA199, 0);
        r->y = 0;
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0x59A7, 0xC75D68); /* configure_and_render_two_native_saved_slot_text_rows */
        uint16_t a_all8 = r->a;
        r->a = (a_all8 >> 8 << 8) | 5;
        r->x = 0;
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0x59AF, 0xC759E0); /* append_native_saved_slot_format_pair */
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0x59B2, 0xC75A32); /* append_native_saved_slot_location_name */
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0x59B5, 0xC7538D); /* append_native_saved_slot_text_line_token */
        uint16_t a_all11 = r->a;
        r->a = (a_all11 >> 8 << 8) | 3;
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0x59BA, 0xC759E0); /* append_native_saved_slot_format_pair */
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0x59BD, 0xC75389); /* append_native_saved_slot_text_space_token */
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0x59C0, 0xC75A8A); /* append_native_saved_slot_seven_bit_value */
        RAM16_SET(0xA199, 0x02A0);
        r->y = 0x02A0;
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0x59C9, 0xC75D68); /* configure_and_render_two_native_saved_slot_text_rows */
        uint16_t a_all15 = r->a;
        uint16_t x_ret15 = r->x;
        uint16_t y_ret8 = r->y;
        bool overflow_ret8 = r->v;
        RAM8(0xA216) >>= 1;
        RAM8(0xA216) >>= 1;
        RAM8(0xA162)++;
        uint8_t value4 = RAM8(0xA162);
        a_hi1 = a_all15 >> 8;
        x1 = x_ret15;
        y1 = y_ret8;
        carry1 = value4 <= 4;
        overflow1 = overflow_ret8;
        if (!(value4 != 4)) break;
    }
    RAM8(0xA20A) &= 0xFD;
    r->a = (a_hi1 << 8) | 2;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC75979, SOM_RTL, "gen", render_four_native_saved_slot_descriptions, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 103, 37)
