#include "som_c.h"

/* C75FFD construct_native_settings_page_and_snapshot_its_selectors   [class B, 46 bytes, 14 instructions]
 * Source: src/rom/construct_native_settings_page_and_snapshot_its_selectors.s
 * Documented in docs/ui-native-settings-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void construct_native_settings_page_and_snapshot_its_selectors(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    RAM8(0xA20F) = 2;
    r->a = (a_hi << 8) | 2;
    JSL(c, 0x6005, 0xC76FC2); /* external */
    r->mf = true;
    r->xf = false;
    JSL(c, 0x6009, 0xC76170); /* render_native_shop_item_tile_frame */
    r->mf = true;
    r->xf = false;
    JSL(c, 0x600D, 0xC02ACB); /* construct_native_menu_page_long_call_wrapper */
    r->mf = true;
    r->xf = false;
    JSR(c, 0x6010, 0xC760C7); /* prepare_native_shop_tile_graphics_palettes_and_publication_flag */
    r->mf = true;
    r->xf = false;
    JSL(c, 0x6014, 0xC02AFA); /* long_call_native_menu_actor_text_and_palette */
    r->mf = true;
    r->xf = false;
    JSL(c, 0x6018, 0xC02ACF); /* clear_native_menu_sprite_tables_long_wrapper */
    r->mf = true;
    r->xf = false;
    JSR(c, 0x601B, 0xC76081); /* publish_three_native_shop_five_bit_icon_selectors */
    r->mf = true;
    r->xf = false;
    JSR(c, 0x601E, 0xC76057); /* publish_three_native_settings_color_cursor_coordinates */
    r->mf = true;
    r->xf = false;
    JSL(c, 0x6022, 0xC02AD3); /* upload_native_menu_sprite_tables_long_wrapper */
    r->mf = true;
    r->xf = false;
    JSL(c, 0x6026, 0xC02AC7); /* reset_native_menu_publication_long_wrapper */
    r->mf = true;
    r->xf = false;
    JSR(c, 0x6029, 0xC7602B); /* snapshot_native_settings_selector_and_eight_icon_variants */
    r->mf = true;
    r->xf = false;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC75FFD, SOM_RTL, "hand", construct_native_settings_page_and_snapshot_its_selectors, 0, 0, 1, 1, 0, 46, 14)
