#include "som_c.h"

/* C76D17 append_native_menu_four_tile_icon_group   [class B, 25 bytes, 9 instructions]
 * Source: src/rom/append_native_menu_four_tile_icon_group.s
 * Documented in docs/event-menu-page-sprites.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void append_native_menu_four_tile_icon_group(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x6D19, 0xC76D30); /* append_native_menu_grid_icon_tile_from_rom */
    RAM8(0xA15A)++;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x6D1F, 0xC76D30); /* append_native_menu_grid_icon_tile_from_rom */
    RAM8(0xA15A)--;
    RAM8(0xA159)++;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x6D28, 0xC76D30); /* append_native_menu_grid_icon_tile_from_rom */
    RAM8(0xA15A)++;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x6D2E, 0xC76D30); /* append_native_menu_grid_icon_tile_from_rom */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76D17, SOM_RTS, "gen", append_native_menu_four_tile_icon_group, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 25, 9)
