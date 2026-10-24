#include "som_c.h"

/* C06977 publish_native_menu_icons_and_palette_between_real_vblank_frames   [class B, 15 bytes, 5 instructions]
 * Source: src/rom/publish_native_menu_icons_and_palette_between_real_vblank_frames.s
 * Documented in docs/event-menu-icon-grid.md
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: V.
 */
static void publish_native_menu_icons_and_palette_between_real_vblank_frames(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6979, 0xC06943); GUARD_JSR(c, sp_call, 0x6979); } /* await_vblank_edge_and_run_complete_menu_text_frame */
    { const uint16_t sp_call = r->sp; JSL(c, 0x697D, 0xD0C8FB); GUARD_JSL(c, sp_call, 0x697D); } /* publish_native_menu_icon_grid_or_equipment_preview */
    { const uint16_t sp_call = r->sp; JSR(c, 0x6980, 0xC06943); GUARD_JSR(c, sp_call, 0x6980); } /* await_vblank_edge_and_run_complete_menu_text_frame */
    { const uint16_t sp_call = r->sp; JSL(c, 0x6984, 0xD0CB1F); GUARD_JSL(c, sp_call, 0x6984); } /* choose_native_icon_palette_page_from_menu_mode */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC06977, SOM_RTS, "hand", publish_native_menu_icons_and_palette_between_real_vblank_frames, 0, L_V, 1, 0, 0, 15, 5)
