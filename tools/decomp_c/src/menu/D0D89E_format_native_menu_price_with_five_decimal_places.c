#include "som_c.h"

/* D0D89E format_native_menu_price_with_five_decimal_places   [class B, 40 bytes, 16 instructions]
 * Source: src/rom/format_native_menu_price_with_five_decimal_places.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: XYCV.
 */
static void format_native_menu_price_with_five_decimal_places(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    RAM8(0x1802) &= 0xEF;
    r->a = 0x2710;
    r->y = a;
    JSR(c, 0xD8AF, 0xD0D8C6); /* emit_one_menu_price_digit_by_repeated_word_subtraction */
    r->a = 0x03E8;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0xD8B5, 0xD0D8C6); /* emit_one_menu_price_digit_by_repeated_word_subtraction */
    r->a = 0x64;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0xD8BB, 0xD0D8C6); /* emit_one_menu_price_digit_by_repeated_word_subtraction */
    r->a = 0x0A;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0xD8C1, 0xD0D8C6); /* emit_one_menu_price_digit_by_repeated_word_subtraction */
    uint16_t y_ret4 = r->y;
    r->a = y_ret4;
    r->mf = 0;
    r->xf = 0;
    TAIL_CALL(c, 0xD0D7FD, SOM_RTS); /* append_native_menu_digit_with_leading_zero_suppression */
}
SOM_REGISTER(0xD0D89E, SOM_RTS, "gen", format_native_menu_price_with_five_decimal_places, 0, L_X | L_Y | L_C | L_V, 1, 0, 0, 40, 16)
