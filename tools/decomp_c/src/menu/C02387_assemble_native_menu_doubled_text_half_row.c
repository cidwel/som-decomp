#include "som_c.h"

/* C02387 assemble_native_menu_doubled_text_half_row   [class A, 38 bytes, 22 instructions]
 * Source: src/rom/assemble_native_menu_doubled_text_half_row.s
 * Documented in docs/event-menu-graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXY.
 */
static void assemble_native_menu_doubled_text_half_row(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    JSR(c, 0x2389, 0xC023AD); /* clear_native_menu_text_half_row_borders */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint8_t a1 = 6;
    uint8_t a_hi1 = a_all >> 8;
    uint16_t x1 = x_ret;
    uint16_t y1 = y;
    for (;;) {
        uint8_t value = RAM8(0x9000 + y1);
        RAM8(0x9400 + x1) = value;
        RAM8(0x9401 + x1) = value;
        uint8_t value2 = RAM8(0x9006 + y1);
        RAM8(0x941C + x1) = value2;
        RAM8(0x941D + x1) = value2;
        a1 = (uint8_t)(a1 - 1);
        a_hi1 = value2;
        x1 = (uint16_t)(x1 + 2);
        y1 = (uint16_t)(y1 + 1);
        if (!(a1 != 0)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = (uint16_t)(y1 + 6);
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02387, SOM_RTS, "gen", assemble_native_menu_doubled_text_half_row, 0, L_B | L_X | L_Y, 1, 1, 0, 38, 22)
