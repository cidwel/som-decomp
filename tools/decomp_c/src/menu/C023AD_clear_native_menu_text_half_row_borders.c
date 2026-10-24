#include "som_c.h"

/* C023AD clear_native_menu_text_half_row_borders   [class A, 13 bytes, 7 instructions]
 * Source: src/rom/clear_native_menu_text_half_row_borders.s
 * Documented in docs/event-menu-graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXY.
 */
static void clear_native_menu_text_half_row_borders(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t a1 = 4;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    for (;;) {
        RAM8(0x9400 + x1) = 0;
        RAM8(0x942C + x1) = 0;
        a1 = (uint8_t)(a1 - 1);
        x1 = (uint16_t)(x1 + 1);
        if (!(a1 != 0)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC023AD, SOM_RTS, "gen", clear_native_menu_text_half_row_borders, 0, L_B | L_X | L_Y, 1, 1, 0, 13, 7)
