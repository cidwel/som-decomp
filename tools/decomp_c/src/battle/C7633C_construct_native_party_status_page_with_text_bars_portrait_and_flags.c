#include "som_c.h"

/* C7633C construct_native_party_status_page_with_text_bars_portrait_and_flags   [class B, 43 bytes, 14 instructions]
 * Source: src/rom/construct_native_party_status_page_with_text_bars_portrait_and_flags.s
 * Documented in docs/ui-native-party-status-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void construct_native_party_status_page_with_text_bars_portrait_and_flags(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    RAM8(0xA20F) = 8;
    r->a = (a_hi << 8) | 8;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6343, 0xC76B55); GUARD_JSR(c, sp_call, 0x6343); } /* build_and_upload_sixteen_rotating_native_status_bar_patterns */
    { const uint16_t sp_call = r->sp; JSL(c, 0x6347, 0xC02ACB); GUARD_JSL(c, sp_call, 0x6347); } /* construct_native_menu_page_long_call_wrapper */
    { const uint16_t sp_call = r->sp; JSR(c, 0x634A, 0xC75DF9); GUARD_JSR(c, sp_call, 0x634A); } /* upload_native_party_page_tiles_and_three_palettes */
    { const uint16_t sp_call = r->sp; JSR(c, 0x634D, 0xC76ADF); GUARD_JSR(c, sp_call, 0x634D); } /* build_native_party_status_background_and_conditional_panels */
    { const uint16_t sp_call = r->sp; JSR(c, 0x6350, 0xC766E1); GUARD_JSR(c, sp_call, 0x6350); } /* collect_and_render_fifteen_native_party_status_statistics */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6353, 0xC76890); GUARD_JSR(c, sp_call, 0x6353); } /* compose_and_render_native_party_status_summary_rows */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6357, 0xC02ACF); GUARD_JSL(c, sp_call, 0x6357); } /* clear_native_menu_sprite_tables_long_wrapper */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x635A, 0xC76AD2); GUARD_JSR(c, sp_call, 0x635A); } /* dispatch_selected_native_party_status_portrait */
    { const uint16_t sp_call = r->sp; JSR(c, 0x635D, 0xC76367); GUARD_JSR(c, sp_call, 0x635D); } /* publish_eight_native_party_status_flag_icons_when_unrestricted */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6361, 0xC02AD3); GUARD_JSL(c, sp_call, 0x6361); } /* upload_native_menu_sprite_tables_long_wrapper */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6365, 0xC02AC7); GUARD_JSL(c, sp_call, 0x6365); } /* reset_native_menu_publication_long_wrapper */
    r->mf = 1;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC7633C, SOM_RTL, "gen", construct_native_party_status_page_with_text_bars_portrait_and_flags, 0, 0, 1, 1, 0, 43, 14)
