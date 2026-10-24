#include "som_c.h"

/* C1F828 construct_complete_scene_graphics_palette_and_vram   [class B, 20 bytes, 7 instructions]
 * Source: src/rom/construct_complete_scene_graphics_palette_and_vram.s
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BYCV.
 */
static void construct_complete_scene_graphics_palette_and_vram(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0xF82A, 0xC1F83C); GUARD_JSR(c, sp_call, 0xF82A); } /* expand_packed_scene_tile_attributes_and_snapshot_vram */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xF82D, 0xC1F8A7); GUARD_JSR(c, sp_call, 0xF82D); } /* choose_shared_or_party_character_graphics_upload */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xF830, 0xC1F8E9); GUARD_JSR(c, sp_call, 0xF830); } /* copy_scene_palette_templates_and_refresh_special_palette_rows */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF834, 0x02B75E); GUARD_JSL(c, sp_call, 0xF834); } /* conditionally_upload_scene_overlay_graphics_and_palette */
    { const uint16_t sp_call = r->sp; JSR(c, 0xF837, 0xC1F944); GUARD_JSR(c, sp_call, 0xF837); } /* publish_current_palette_buffer_through_dma_channel_seven */
    r->mf = 0;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xF83A, 0xC1F96A); GUARD_JSR(c, sp_call, 0xF83A); } /* initialize_scene_vram_and_apply_fixed_attribute_fill_records */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1F828, SOM_RTL, "gen", construct_complete_scene_graphics_palette_and_vram, 0, L_B | L_Y | L_C | L_V, 1, 1, 1, 20, 7)
