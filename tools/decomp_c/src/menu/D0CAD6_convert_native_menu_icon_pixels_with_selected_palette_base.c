#include "som_c.h"

/* D0CAD6 convert_native_menu_icon_pixels_with_selected_palette_base   [class A, 59 bytes, 38 instructions]
 * Source: src/rom/convert_native_menu_icon_pixels_with_selected_palette_base.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: Y.
 */
static void convert_native_menu_icon_pixels_with_selected_palette_base(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    uint8_t a1 = 8;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0x18C0;
    for (;;) {
        RAM8(0x0000 + sp0) = a1;
        uint8_t a2 = 8;
        uint8_t a_hi2 = a_hi1;
        for (;;) {
            RAM8(0x0000 + sp0 - 1) = a2;
            uint8_t value = BUS8_RDP(c, (uint16_t)(x1 + 0x10));
            BUS8_SET(c, (uint16_t)(x1 + 0x10), (uint8_t)(value << 1));
            uint8_t value2 = BUS8_RDP(c, (uint16_t)(x1 + 1));
            BUS8_SET(c, (uint16_t)(x1 + 1), (uint8_t)(value2 << 1));
            uint8_t value3 = BUS8_RDP(c, x1);
            BUS8_SET(c, x1, (uint8_t)(value3 << 1));
            uint8_t a3;
            if (((((value >> 7 << 1) | (value2 >> 7)) << 1) | (value3 >> 7)) != 7) {
                a3 = (uint8_t)(((((value >> 7 << 1) | (value2 >> 7)) << 1) | (value3 >> 7)) + RAM8(0x1810));
            } else {
                a3 = 0;
            }
            uint8_t value5 = BUS8_RDP(c, (uint16_t)(x1 + 0x20));
            BUS8_SET(c, (uint16_t)(x1 + 0x20), (uint8_t)(value5 << 1 | (a3 & 1)));
            uint8_t value6 = BUS8_RDP(c, (uint16_t)(x1 + 0x21));
            BUS8_SET(c, (uint16_t)(x1 + 0x21), (uint8_t)(value6 << 1 | ((a3 >> 1) & 1)));
            uint8_t value7 = BUS8_RDP(c, (uint16_t)(x1 + 0x30));
            BUS8_SET(c, (uint16_t)(x1 + 0x30), (uint8_t)(value7 << 1 | ((a3 >> 2) & 1)));
            uint8_t value8 = BUS8_RDP(c, (uint16_t)(x1 + 0x31));
            BUS8_SET(c, (uint16_t)(x1 + 0x31), (uint8_t)(value8 << 1 | ((a3 >> 3) & 1)));
            a2 = (uint8_t)(RAM8(0x0000 + sp0 - 1) - 1);
            if (!(a2 != 0)) break;
        }
        a1 = (uint8_t)(RAM8(0x0000 + sp0) - 1);
        a_hi1 = a_hi2;
        x1 = (uint16_t)(x1 + 2);
        if (!(a1 != 0)) break;
    }
    r->y = y;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0CAD6, SOM_RTS, "gen", convert_native_menu_icon_pixels_with_selected_palette_base, 0, L_Y, 2, 1, 0, 59, 38)
