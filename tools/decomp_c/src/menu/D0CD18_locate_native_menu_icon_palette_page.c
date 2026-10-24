#include "som_c.h"

/* D0CD18 locate_native_menu_icon_palette_page   [class A, 15 bytes, 8 instructions]
 * Source: src/rom/locate_native_menu_icon_palette_page.s
 * Documented in docs/event-menu-icon-palette.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: AV.
 */
static void locate_native_menu_icon_palette_page(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0x1802);
    r->a = (((((uint8_t)value << 8) | (value >> 8)) & 0x0100) >> 1) + 0x0700;
    r->v = (((((((uint8_t)value << 8) | (value >> 8)) & 0x0100) >> 1) ^ (((((uint8_t)value << 8) | (value >> 8)) & 0x0100) >> 1) + 0x0700) & ((((((uint8_t)value << 8) | (value >> 8)) & 0x0100) >> 1) + 0x0700 ^ 0x0700) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0CD18, SOM_RTS, "gen", locate_native_menu_icon_palette_page, 0, L_A | L_V, 1, 0, 0, 15, 8)
