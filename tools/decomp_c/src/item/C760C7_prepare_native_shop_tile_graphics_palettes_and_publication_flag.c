#include "som_c.h"

/* C760C7 prepare_native_shop_tile_graphics_palettes_and_publication_flag   [class B, 16 bytes, 6 instructions]
 * Source: src/rom/prepare_native_shop_tile_graphics_palettes_and_publication_flag.s
 * Documented in docs/event-menu-shop-publication.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCZV.
 */
static void prepare_native_shop_tile_graphics_palettes_and_publication_flag(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x60C9, 0xC76125); /* copy_native_shop_item_tile_row_and_eight_background_rows */
    r->mf = 1;
    r->xf = 0;
    JSL(c, 0x60CD, 0xC02AFE); /* native_menu_glyph_grid_expansion_long_wrapper */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x60D0, 0xC760D7); /* select_native_shop_two_palette_records_and_shared_color_word */
    uint8_t value = RAM8(0xA212);
    RAM8(0xA212) |= 0x80;
    r->z = (value & 0x80) == 0;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC760C7, SOM_RTS, "gen", prepare_native_shop_tile_graphics_palettes_and_publication_flag, 0, L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 16, 6)
