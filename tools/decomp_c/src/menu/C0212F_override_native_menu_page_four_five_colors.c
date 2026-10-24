#include "som_c.h"

/* C0212F override_native_menu_page_four_five_colors   [class A, 58 bytes, 30 instructions]
 * Source: src/rom/override_native_menu_page_four_five_colors.s
 * Documented in docs/event-menu-constructor.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: YCV.
 */
static void override_native_menu_page_four_five_colors(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t y6;
    bool carry1;
    if (a == 4) {
        uint8_t a1 = 6;
        uint8_t a_hi1 = a_hi;
        uint16_t x1 = 0x0C;
        uint16_t y1 = 2;
        for (;;) {
            uint8_t value = BUS8(c, 0xD2DBC0 + x1);
            RAM8(0x9018 + y1) = value;
            RAM8(0x9028 + y1) = value;
            a1 = (uint8_t)(a1 - 1);
            a_hi1 = value;
            x1 = (uint16_t)(x1 + 1);
            y1 = (uint16_t)(y1 + 1);
            if (!(a1 != 0)) break;
        }
        uint8_t a2 = 6;
        uint8_t a_hi2 = a_hi1;
        uint16_t x2 = 0x24;
        uint16_t y2 = 2;
        for (;;) {
            uint8_t value2 = BUS8(c, 0xD2DBC0 + x2);
            RAM8(0x9010 + y2) = value2;
            RAM8(0x9020 + y2) = value2;
            a2 = (uint8_t)(a2 - 1);
            a_hi2 = value2;
            x2 = (uint16_t)(x2 + 1);
            y2 = (uint16_t)(y2 + 1);
            if (!(a2 != 0)) break;
        }
        y6 = y2;
        carry1 = a >= 4;
    } else {
        uint16_t y5;
        if (a != 5) {
            y5 = y;
        } else {
            uint8_t a3 = 6;
            uint8_t a_hi3 = a_hi;
            uint16_t x3 = 0x0C;
            uint16_t y3 = 2;
            for (;;) {
                uint8_t value3 = BUS8(c, 0xD2DBC0 + x3);
                RAM8(0x9018 + y3) = value3;
                RAM8(0x9028 + y3) = value3;
                a3 = (uint8_t)(a3 - 1);
                a_hi3 = value3;
                x3 = (uint16_t)(x3 + 1);
                y3 = (uint16_t)(y3 + 1);
                if (!(a3 != 0)) break;
            }
            uint8_t a4 = 6;
            uint8_t a_hi4 = a_hi3;
            uint16_t x4 = 0x24;
            uint16_t y4 = 2;
            for (;;) {
                uint8_t value4 = BUS8(c, 0xD2DBC0 + x4);
                RAM8(0x9010 + y4) = value4;
                RAM8(0x9020 + y4) = value4;
                a4 = (uint8_t)(a4 - 1);
                a_hi4 = value4;
                x4 = (uint16_t)(x4 + 1);
                y4 = (uint16_t)(y4 + 1);
                if (!(a4 != 0)) break;
            }
            y5 = y4;
        }
        y6 = y5;
        carry1 = a >= 5;
    }
    r->y = y6;
    r->c = carry1;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0212F, SOM_RTS, "gen", override_native_menu_page_four_five_colors, 0, L_Y | L_C | L_V, 2, 1, 0, 58, 30)
