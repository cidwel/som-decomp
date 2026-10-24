#include "som_c.h"

/* D0CBD6 cache_selected_native_menu_icon_palette_page   [class A, 32 bytes, 15 instructions]
 * Source: src/rom/cache_selected_native_menu_icon_palette_page.s
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: YV.
 */
static void cache_selected_native_menu_icon_palette_page(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0x1810, 0);
    RAM16_SET(0x1820, 0);
    { const uint16_t sp_call = r->sp; JSR(c, 0xCBE0, 0xD0CD18); GUARD_JSR(c, sp_call, 0xCBE0); } /* locate_native_menu_icon_palette_page */
    uint16_t a_all = r->a;
    bool overflow_ret = r->v;
    uint8_t a_hi1 = a_all >> 8;
    uint16_t x1 = 0;
    uint16_t y1 = a_all;
    for (;;) {
        uint16_t value = BUS16(c, 0x000000 + y1);
        RAM16_SET(0x8100 + x1, value);
        a_hi1 = value >> 8;
        x1 = (uint16_t)(x1 + 2);
        y1 = (uint16_t)(y1 + 2);
        if (!(x1 < 0x80)) break;
    }
    r->y = y1;
    r->v = overflow_ret;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0CBD6, SOM_RTS, "gen", cache_selected_native_menu_icon_palette_page, 0, L_Y | L_V, 1, 0, 0, 32, 15)
