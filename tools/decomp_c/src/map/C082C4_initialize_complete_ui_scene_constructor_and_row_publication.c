#include "som_c.h"

/* C082C4 initialize_complete_ui_scene_constructor_and_row_publication   [class D, 140 bytes, 55 instructions]
 * Source: src/rom/initialize_complete_ui_scene_constructor_and_row_publication.s
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BYC.
 */
static void initialize_complete_ui_scene_constructor_and_row_publication(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    { const uint16_t sp_call = r->sp; JSL(c, 0x82C7, 0x01FDB8); GUARD_JSL(c, sp_call, 0x82C7); } /* upload_scene_cursor_graphic_to_vram */
    uint8_t x1 = 0xCE;
    for (;;) {
        RAM16_SET(0x0000 + x1, 0);
        x1 = (uint8_t)(x1 - 2);
        if (!(x1 != 0)) break;
    }
    RAM16_SET(0x00C2, 0x2000);
    BUS8_SET(c, 0x00210B, 0x44);
    BUS8_SET(c, 0x002107, 0x51);
    BUS8_SET(c, 0x002108, 0x59);
    RAM16_SET(0x005C, 0x8024);
    RAM8(0x005E) = 0xFF;
    RAM16_SET(0x00F5, RAM16(0x00F5) | 1);
    RAM16_SET(0x00A4, 0x2C00);
    RAM16_SET(0x00A2, 0xF000);
    RAM16_SET(0x0092, 0xEC00);
    RAM16_SET(0x0094, 0x2800);
    BUS8_SET(c, 0x004207, 0x84);
    BUS8_SET(c, 0x004208, 0);
    BUS8_SET(c, 0x004209, 0x60);
    BUS8_SET(c, 0x00420A, 0);
    r->a = 0x2800;
    r->x = 0;
    r->y = y;
    r->c = carry;
    r->z = 1;
    r->n = 0;
    r->v = overflow;
    r->mf = 0;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8325, 0xC08266); GUARD_JSR(c, sp_call, 0x8325); } /* consume_pending_scene_target_initialization */
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8328, 0xC08566); GUARD_JSR(c, sp_call, 0x8328); } /* compute_scene_attribute_scroll_weights_with_multiplier */
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x832B, 0xC08366); GUARD_JSR(c, sp_call, 0x832B); } /* initialize_scene_centers_color_math_and_hdma */
    { const uint16_t sp_call = r->sp; JSL(c, 0x832F, 0x02AF7D); GUARD_JSL(c, sp_call, 0x832F); } /* initialize_scene_quadratic_curve_hdma_bytes */
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x8333, 0x01F828); GUARD_JSL(c, sp_call, 0x8333); } /* construct_complete_scene_graphics_palette_and_vram */
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8336, 0xC09996); GUARD_JSR(c, sp_call, 0x8336); } /* initialize_scene_one_hundred_twenty_eight_tile_rows_and_attributes */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8339, 0xC09CEF); GUARD_JSR(c, sp_call, 0x8339); } /* initialize_scene_object_cursor_control_words */
    r->mf = 0;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x833C, 0xC08350); GUARD_JSR(c, sp_call, 0x833C); } /* install_scene_frame_jump_vectors */
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x833F, 0xC09550); GUARD_JSR(c, sp_call, 0x833F); } /* initialize_scene_window_curve_and_channel_seven_hdma */
    r->x = 0x0F00;
    r->y = 0x0401;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x834A, 0xC08B30); GUARD_JSR(c, sp_call, 0x834A); } /* request_map_entry_fade */
    { const uint16_t sp_call = r->sp; JSL(c, 0x834E, 0x02A914); GUARD_JSL(c, sp_call, 0x834E); } /* request_guarded_area_theme_from_status_bits */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC082C4, SOM_RTS, "gen", initialize_complete_ui_scene_constructor_and_row_publication, 0, L_B | L_Y | L_C, 1, 1, 1, 140, 55)
