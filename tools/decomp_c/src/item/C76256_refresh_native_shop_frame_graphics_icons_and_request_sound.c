#include "som_c.h"

/* C76256 refresh_native_shop_frame_graphics_icons_and_request_sound   [class B, 20 bytes, 7 instructions]
 * Source: src/rom/refresh_native_shop_frame_graphics_icons_and_request_sound.s
 * Documented in docs/event-menu-shop-actions.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void refresh_native_shop_frame_graphics_icons_and_request_sound(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSL(c, 0x6259, 0xC76170); GUARD_JSL(c, sp_call, 0x6259); } /* render_native_shop_item_tile_frame */
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x625C, 0xC760C7); GUARD_JSR(c, sp_call, 0x625C); } /* prepare_native_shop_tile_graphics_palettes_and_publication_flag */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x625F, 0xC76081); GUARD_JSR(c, sp_call, 0x625F); } /* publish_three_native_shop_five_bit_icon_selectors */
    uint16_t a_all3 = r->a;
    RAM8(0xA20A) |= 6;
    r->a = (a_all3 >> 8 << 8) | 6;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6268, 0xC02AF2); GUARD_JSL(c, sp_call, 0x6268); } /* native_menu_change_sound_long_wrapper */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC76256, SOM_RTL, "gen", refresh_native_shop_frame_graphics_icons_and_request_sound, 0, 0, 1, 1, 0, 20, 7)
