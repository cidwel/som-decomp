#include "som_c.h"

/* D0D8C6 emit_one_menu_price_digit_by_repeated_word_subtraction   [class C, 24 bytes, 15 instructions]
 * Source: src/rom/emit_one_menu_price_digit_by_repeated_word_subtraction.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: XYCV.
 */
static void emit_one_menu_price_digit_by_repeated_word_subtraction(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t a1 = (uint8_t)y;
    uint8_t a_hi1 = y >> 8;
    uint16_t y1 = 0xFFFF;
    for (;;) {
        bool again = ((a_hi1 << 8) | a1) >= a;
        uint8_t a1_next = (uint8_t)(((a_hi1 << 8) | a1) - a);
        uint8_t a_hi1_next = (uint16_t)(((a_hi1 << 8) | a1) - a) >> 8;
        uint16_t y1_next = (uint16_t)(y1 + 1);
        a1 = a1_next;
        a_hi1 = a_hi1_next;
        y1 = y1_next;
        if (!again) break;
    }
    r->a = y1;
    r->x = x;
    r->y = (uint16_t)(((a_hi1 << 8) | a1) + a);
    r->c = ((a_hi1 << 8) | a1) + a > 0xFFFF;
    JSR(c, 0xD8DA, 0xD0D7FD); /* append_native_menu_digit_with_leading_zero_suppression */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0D8C6, SOM_RTS, "gen", emit_one_menu_price_digit_by_repeated_word_subtraction, 0, L_X | L_Y | L_C | L_V, 2, 0, 0, 24, 15)
