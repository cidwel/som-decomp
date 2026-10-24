#include "som_c.h"

/* C76D30 append_native_menu_grid_icon_tile_from_rom   [class A, 39 bytes, 21 instructions]
 * Source: src/rom/append_native_menu_grid_icon_tile_from_rom.s
 * Documented in docs/event-menu-page-sprites.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void append_native_menu_grid_icon_tile_from_rom(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM8(0x9C00 + y) = (uint8_t)(RAM8(0xA15A) << 3);
    uint8_t value2 = RAM8(0xA159);
    RAM8(0x9C00 + (uint16_t)(y + 1)) = (uint8_t)(value2 << 3);
    uint8_t value3 = BUS8(c, 0xC70000 + x);
    RAM8(0x9C00 + (uint16_t)(y + 2)) = value3;
    uint8_t value4 = BUS8(c, 0xC70000 + (uint16_t)(x + 1));
    RAM8(0x9C00 + (uint16_t)(y + 3)) = value4;
    r->x = (uint16_t)(x + 2);
    r->y = (uint16_t)(y + 4);
    r->c = (uint8_t)(value2 << 2) & 0x80;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76D30, SOM_RTS, "gen", append_native_menu_grid_icon_tile_from_rom, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 39, 21)
