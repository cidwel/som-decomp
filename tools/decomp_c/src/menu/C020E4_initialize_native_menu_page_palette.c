#include "som_c.h"

/* C020E4 initialize_native_menu_page_palette   [class D, 75 bytes, 32 instructions]
 * Source: src/rom/initialize_native_menu_page_palette.s
 * Documented in docs/event-menu-constructor.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: CV.
 */
static void initialize_native_menu_page_palette(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const bool overflow = r->v;
    uint8_t value = BUS8(c, 0xC7FBE0);
    RAM8(0x9000) = value;
    uint8_t value2 = BUS8(c, 0xC7FBE1);
    RAM8(0x9001) = value2;
    RAM8(0xA171) = 0x0A;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    uint16_t y1 = 2;
    do {
        uint8_t a1 = 6;
        uint8_t a_hi2 = a_hi1;
        uint16_t x2 = x1;
        uint16_t y2 = y1;
        for (;;) {
            uint8_t value3 = BUS8(c, 0xD2DBC0 + x2);
            RAM8(0x9000 + y2) = value3;
            a1 = (uint8_t)(a1 - 1);
            a_hi2 = value3;
            x2 = (uint16_t)(x2 + 1);
            y2 = (uint16_t)(y2 + 1);
            if (!(a1 != 0)) break;
        }
        RAM8(0xA171)--;
        a_hi1 = a_hi2;
        x1 = x2;
        y1 = (uint16_t)(y2 + 2);
    } while (RAM8(0xA171) != 0);
    r->a = (a_hi1 << 8) | a;
    r->y = y1;
    r->v = overflow;
    JSR(c, 0x2118, 0xC0212F); /* override_native_menu_page_four_five_colors */
    BUS8_SET(c, 0x002121, 0);
    RAM16_SET(0xA194, 0x9000);
    RAM16_SET(0xA191, 0x40);
    r->x = 0x40;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x212D, 0xC025FB); /* select_wram_source_for_native_menu_palette_dma */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC020E4, SOM_RTS, "gen", initialize_native_menu_page_palette, 0, L_C | L_V, 1, 1, 0, 75, 32)
