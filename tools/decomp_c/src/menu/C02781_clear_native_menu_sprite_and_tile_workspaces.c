#include "som_c.h"

/* C02781 clear_native_menu_sprite_and_tile_workspaces   [class A, 29 bytes, 14 instructions]
 * Source: src/rom/clear_native_menu_sprite_and_tile_workspaces.s
 * Documented in docs/event-menu-graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void clear_native_menu_sprite_and_tile_workspaces(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t x1 = 0;
    uint16_t y1 = 0x0536;
    for (;;) {
        RAM8(0x9C00 + x1) = 0;
        x1 = (uint16_t)(x1 + 1);
        y1 = (uint16_t)(y1 - 1);
        if (!(y1 != 0)) break;
    }
    uint16_t x2 = 0x0800;
    uint16_t y2 = 0;
    for (;;) {
        RAM8(0x9000 + y2) = 0;
        x2 = (uint16_t)(x2 - 1);
        y2 = (uint16_t)(y2 + 1);
        if (!(x2 != 0)) break;
    }
    r->a = (a_hi << 8) | 0;
    r->x = x2;
    r->y = y2;
    r->c = carry;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02781, SOM_RTS, "gen", clear_native_menu_sprite_and_tile_workspaces, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 29, 14)
