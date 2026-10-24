#include "som_c.h"
#include "som_hand_d.h"

/* C02B06 dispatch_twelve_native_menu_button_bits_and_copy_previous_pads   [class B, 148 bytes, 63 instructions]
 * Source: src/rom/dispatch_twelve_native_menu_button_bits_and_copy_previous_pads.s
 * Documented in docs/ui-native-loaded-game-input-dispatch.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void dispatch_twelve_native_menu_button_bits_and_copy_previous_pads(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    JSR(c, 0x2B08, 0xC03269); /* derive_native_menu_selected_pad_offset_preserving_accumulator_byte */
    i_phx(c);
    RAM8(0xA209) = 0; /* button index; the pad bytes at $42 and $43 are offset by the selected pad in X */
    a_lda(r, 0x80);
    a_and(r, dp_rd8(c, 0x42 + r->x));
    JSR(c, 0x2B13, 0xC02B9A); /* dispatch_pressed_native_menu_button_through_real_callback_table */
    REQUIRE_M8(c);
    RAM8(0xA209) = m_inc(r, RAM8(0xA209));
    a_lda(r, 0x40);
    a_and(r, dp_rd8(c, 0x42 + r->x));
    JSR(c, 0x2B1D, 0xC02B9A); /* dispatch_pressed_native_menu_button_through_real_callback_table */
    REQUIRE_M8(c);
    RAM8(0xA209) = m_inc(r, RAM8(0xA209));
    a_lda(r, 0x20);
    a_and(r, dp_rd8(c, 0x42 + r->x));
    JSR(c, 0x2B27, 0xC02B9A); /* dispatch_pressed_native_menu_button_through_real_callback_table */
    REQUIRE_M8(c);
    RAM8(0xA209) = m_inc(r, RAM8(0xA209));
    a_lda(r, 0x10);
    a_and(r, dp_rd8(c, 0x42 + r->x));
    JSR(c, 0x2B31, 0xC02B9A); /* dispatch_pressed_native_menu_button_through_real_callback_table */
    REQUIRE_M8(c);
    RAM8(0xA209) = m_inc(r, RAM8(0xA209));
    a_lda(r, 0x80);
    a_and(r, dp_rd8(c, 0x43 + r->x));
    JSR(c, 0x2B3B, 0xC02B9A); /* dispatch_pressed_native_menu_button_through_real_callback_table */
    REQUIRE_M8(c);
    RAM8(0xA209) = m_inc(r, RAM8(0xA209));
    a_lda(r, 0x40);
    a_and(r, dp_rd8(c, 0x43 + r->x));
    JSR(c, 0x2B45, 0xC02B9A); /* dispatch_pressed_native_menu_button_through_real_callback_table */
    REQUIRE_M8(c);
    RAM8(0xA209) = m_inc(r, RAM8(0xA209));
    a_lda(r, 0x20);
    a_and(r, dp_rd8(c, 0x43 + r->x));
    JSR(c, 0x2B4F, 0xC02B9A); /* dispatch_pressed_native_menu_button_through_real_callback_table */
    REQUIRE_M8(c);
    RAM8(0xA209) = m_inc(r, RAM8(0xA209));
    a_lda(r, 0x10);
    a_and(r, dp_rd8(c, 0x43 + r->x));
    JSR(c, 0x2B59, 0xC02B9A); /* dispatch_pressed_native_menu_button_through_real_callback_table */
    REQUIRE_M8(c);
    RAM8(0xA209) = m_inc(r, RAM8(0xA209));
    a_lda(r, 0x08);
    a_and(r, dp_rd8(c, 0x43 + r->x));
    JSR(c, 0x2B63, 0xC02B9A); /* dispatch_pressed_native_menu_button_through_real_callback_table */
    REQUIRE_M8(c);
    RAM8(0xA209) = m_inc(r, RAM8(0xA209));
    a_lda(r, 0x04);
    a_and(r, dp_rd8(c, 0x43 + r->x));
    JSR(c, 0x2B6D, 0xC02B9A); /* dispatch_pressed_native_menu_button_through_real_callback_table */
    REQUIRE_M8(c);
    RAM8(0xA209) = m_inc(r, RAM8(0xA209));
    a_lda(r, 0x02);
    a_and(r, dp_rd8(c, 0x43 + r->x));
    JSR(c, 0x2B77, 0xC02B9A); /* dispatch_pressed_native_menu_button_through_real_callback_table */
    REQUIRE_M8(c);
    RAM8(0xA209) = m_inc(r, RAM8(0xA209));
    a_lda(r, 0x01);
    a_and(r, dp_rd8(c, 0x43 + r->x));
    JSR(c, 0x2B81, 0xC02B9A); /* dispatch_pressed_native_menu_button_through_real_callback_table */
    REQUIRE_M8(c);
    RAM8(0xA209) = m_inc(r, RAM8(0xA209));
    JSR(c, 0x2B87, 0xC02BA5); /* dispatch_native_menu_idle_callback_when_selected_pad_is_empty */
    REQUIRE_M8X16(c);
    i_plx(c);
    a_lda(r, 0x06);
    a_ldx(r, 0x0000);
    do { /* copy the six pad bytes to the previous-pad block */
        i_xba(r);
        a_lda(r, dp_rd8(c, 0x42 + r->x));
        RAM8(0xA203 + r->x) = r->a;
        i_inx(r);
        i_xba(r);
        i_deca(r);
    } while (!r->z);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02B06, SOM_RTS, "hand", dispatch_twelve_native_menu_button_bits_and_copy_previous_pads, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 148, 63)
