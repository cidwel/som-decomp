#include "som_c.h"

/* C02D27 confirm_native_title_selection_on_changed_pad_zero   [class A, 15 bytes, 6 instructions]
 * Source: src/rom/confirm_native_title_selection_on_changed_pad_zero.s
 * Documented in docs/ui-native-loaded-game-title-callbacks.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void confirm_native_title_selection_on_changed_pad_zero(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x0043);
    uint8_t value2 = RAM8(0xA204);
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if (value == value2) {
        a1 = value;
        a_hi1 = a_hi;
        x1 = x;
        y1 = y;
        carry1 = value >= value2;
        zero1 = value == value2;
        negative1 = (uint8_t)(value - value2) & 0x80;
        overflow1 = overflow;
    } else {
        r->a = (a_hi << 8) | value;
        r->c = value >= value2;
        JSR(c, 0x2D30, 0xC01BA5); /* preserve_accumulator_byte_and_request_fixed_local_audio_presets */
        r->mf = 1;
        r->xf = 0;
        JSL(c, 0x2D34, 0xC75F4A); /* select_title_load_or_new_game_page_and_initialize_save_records */
        uint16_t a_all2 = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret2 = r->y;
        bool carry_ret2 = r->c;
        bool zero_ret2 = r->z;
        bool negative_ret2 = r->n;
        bool overflow_ret2 = r->v;
        a1 = (uint8_t)a_all2;
        a_hi1 = a_all2 >> 8;
        x1 = x_ret2;
        y1 = y_ret2;
        carry1 = carry_ret2;
        zero1 = zero_ret2;
        negative1 = negative_ret2;
        overflow1 = overflow_ret2;
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
SOM_REGISTER(0xC02D27, SOM_RTS, "gen", confirm_native_title_selection_on_changed_pad_zero, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 15, 6)
