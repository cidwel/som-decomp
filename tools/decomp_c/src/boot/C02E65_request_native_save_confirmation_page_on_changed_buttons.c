#include "som_c.h"

/* C02E65 request_native_save_confirmation_page_on_changed_buttons   [class A, 24 bytes, 10 instructions]
 * Source: src/rom/request_native_save_confirmation_page_on_changed_buttons.s
 * Documented in docs/ui-native-loaded-game-save-callbacks.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void request_native_save_confirmation_page_on_changed_buttons(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    JSR(c, 0x2E67, 0xC0325A); /* compare_selected_pad_buttons_against_native_previous_buttons */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    bool zero_ret = r->z;
    bool negative_ret = r->n;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if (zero_ret) {
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        y1 = y;
        carry1 = carry_ret;
        zero1 = zero_ret;
        negative1 = negative_ret;
        overflow1 = overflow;
    } else {
        RAM8(0xA210) = 0x0A;
        RAM8(0xA20A) |= 1;
        RAM8(0xA212) &= 0xDF;
        r->a = (a_all >> 8 << 8) | 0x20;
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0x2E7B, 0xC01BA5); /* preserve_accumulator_byte_and_request_fixed_local_audio_presets */
        uint16_t a_all2 = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret2 = r->c;
        bool zero_ret2 = r->z;
        bool negative_ret2 = r->n;
        bool overflow_ret = r->v;
        a1 = (uint8_t)a_all2;
        a_hi1 = a_all2 >> 8;
        x1 = x_ret2;
        y1 = y_ret;
        carry1 = carry_ret2;
        zero1 = zero_ret2;
        negative1 = negative_ret2;
        overflow1 = overflow_ret;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02E65, SOM_RTS, "gen", request_native_save_confirmation_page_on_changed_buttons, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 24, 10)
