#include "som_c.h"

/* C012FF dispatch_native_dialogue_window_completion_phase   [class C, 35 bytes, 17 instructions]
 * Source: src/rom/dispatch_native_dialogue_window_completion_phase.s
 * Documented in docs/event-dialogue-render-core.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void dispatch_native_dialogue_window_completion_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t value = RAM8(0x1D05);
    bool m_flag;
    bool x_flag;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool zero1;
    bool negative1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if (value == 7) {
        RAM8(0xA16F) = 1;
        uint8_t value2 = RAM8(0xA15C);
        r->a = (uint8_t)(value2 << 1);
        r->x = (uint8_t)(value2 << 1);
        r->c = value2 & 0x80;
        r->z = (uint8_t)(value2 << 1) == 0;
        r->n = (uint8_t)(value2 << 1) & 0x8000;
        { const uint16_t sp_call = r->sp;
        switch ((uint8_t)(value2 << 1)) {
        case 0x0000: JSR(c, 0x1320, 0xC00261); GUARD_JSR(c, sp_call, 0x1320); break; /* initialize_active_dialogue_window_geometry_and_style */
        case 0x0002: JSR(c, 0x1320, 0xC00348); GUARD_JSR(c, sp_call, 0x1320); break; /* publish_active_dialogue_window_raster_phase */
        case 0x0004: JSR(c, 0x1320, 0xC00348); GUARD_JSR(c, sp_call, 0x1320); break; /* publish_active_dialogue_window_raster_phase */
        case 0x0006: JSR(c, 0x1320, 0xC00348); GUARD_JSR(c, sp_call, 0x1320); break; /* publish_active_dialogue_window_raster_phase */
        case 0x0008: JSR(c, 0x1320, 0xC00348); GUARD_JSR(c, sp_call, 0x1320); break; /* publish_active_dialogue_window_raster_phase */
        case 0x000A: JSR(c, 0x1320, 0xC006A8); GUARD_JSR(c, sp_call, 0x1320); break; /* finish_dialogue_window_and_resume_script_cursor */
        case 0x000C: JSR(c, 0x1320, 0xC006DA); GUARD_JSR(c, sp_call, 0x1320); break; /* clear_controller_seven_dialogue_object_and_advance_close_phase */
        case 0x000E: JSR(c, 0x1320, 0xC008C3); GUARD_JSR(c, sp_call, 0x1320); break; /* finish_dialogue_window_closing_and_restore_suspended_context */
        case 0x0010: JSR(c, 0x1320, 0xC00261); GUARD_JSR(c, sp_call, 0x1320); break; /* initialize_active_dialogue_window_geometry_and_style */
        case 0x0012: JSR(c, 0x1320, 0xC002BD); GUARD_JSR(c, sp_call, 0x1320); break; /* publish_dialogue_window_tile_row_and_advance_frame_phase */
        case 0x0014: JSR(c, 0x1320, 0xC00348); GUARD_JSR(c, sp_call, 0x1320); break; /* publish_active_dialogue_window_raster_phase */
        case 0x0016: JSR(c, 0x1320, 0xC00348); GUARD_JSR(c, sp_call, 0x1320); break; /* publish_active_dialogue_window_raster_phase */
        case 0x0018: JSR(c, 0x1320, 0xC002BD); GUARD_JSR(c, sp_call, 0x1320); break; /* publish_dialogue_window_tile_row_and_advance_frame_phase */
        case 0x001A: JSR(c, 0x1320, 0xC002BD); GUARD_JSR(c, sp_call, 0x1320); break; /* publish_dialogue_window_tile_row_and_advance_frame_phase */
        case 0x001C: JSR(c, 0x1320, 0xC00348); GUARD_JSR(c, sp_call, 0x1320); break; /* publish_active_dialogue_window_raster_phase */
        case 0x001E: JSR(c, 0x1320, 0xC00348); GUARD_JSR(c, sp_call, 0x1320); break; /* publish_active_dialogue_window_raster_phase */
        case 0x0020: JSR(c, 0x1320, 0xC002BD); GUARD_JSR(c, sp_call, 0x1320); break; /* publish_dialogue_window_tile_row_and_advance_frame_phase */
        case 0x0022: JSR(c, 0x1320, 0xC0040F); GUARD_JSR(c, sp_call, 0x1320); break; /* advance_dialogue_primary_window_phase */
        case 0x0024: JSR(c, 0x1320, 0xC00D51); GUARD_JSR(c, sp_call, 0x1320); break; /* finish_dialogue_window_frame_and_restore_suspended_script */
        case 0x0026: JSR(c, 0x1320, 0xC0062A); GUARD_JSR(c, sp_call, 0x1320); break; /* begin_dialogue_window_erasure_at_saved_origin */
        case 0x0028: JSR(c, 0x1320, 0xC00638); GUARD_JSR(c, sp_call, 0x1320); break; /* begin_dialogue_window_erasure_at_current_cursor */
        case 0x002A: JSR(c, 0x1320, 0xC006A8); GUARD_JSR(c, sp_call, 0x1320); break; /* finish_dialogue_window_and_resume_script_cursor */
        case 0x002C: JSR(c, 0x1320, 0xC0090F); GUARD_JSR(c, sp_call, 0x1320); break; /* initialize_dialogue_window_font_buffer_and_style */
        case 0x002E: JSR(c, 0x1320, 0xC00A34); GUARD_JSR(c, sp_call, 0x1320); break; /* initialize_dialogue_window_corner_pairs */
        case 0x0030: JSR(c, 0x1320, 0xC00A8D); GUARD_JSR(c, sp_call, 0x1320); break; /* expand_dialogue_window_corners_in_four_steps */
        case 0x0032: JSR(c, 0x1320, 0xC00B4F); GUARD_JSR(c, sp_call, 0x1320); break; /* publish_native_dialogue_frame_border_rows */
        case 0x0034: JSR(c, 0x1320, 0xC00C2A); GUARD_JSR(c, sp_call, 0x1320); break; /* publish_native_dialogue_frame_side_pairs */
        case 0x0036: JSR(c, 0x1320, 0xC00D51); GUARD_JSR(c, sp_call, 0x1320); break; /* finish_dialogue_window_frame_and_restore_suspended_script */
        case 0x0038: JSR(c, 0x1320, 0xC006EA); GUARD_JSR(c, sp_call, 0x1320); break; /* collapse_dialogue_window_rows_and_publish_blank_tile */
        case 0x003A: JSR(c, 0x1320, 0xC007E0); GUARD_JSR(c, sp_call, 0x1320); break; /* restore_dialogue_style_or_publish_collapsed_window_band */
        case 0x003C: JSR(c, 0x1320, 0xC00844); GUARD_JSR(c, sp_call, 0x1320); break; /* collapse_dialogue_window_corner_pairs */
        case 0x003E: JSR(c, 0x1320, 0xC0089E); GUARD_JSR(c, sp_call, 0x1320); break; /* erase_final_dialogue_window_corner_cells */
        case 0x0040: JSR(c, 0x1320, 0xC008C3); GUARD_JSR(c, sp_call, 0x1320); break; /* finish_dialogue_window_closing_and_restore_suspended_context */
        case 0x0042: JSR(c, 0x1320, 0xC00229); GUARD_JSR(c, sp_call, 0x1320); break; /* dispatch_all_native_dialogue_window_construction_phases */
        case 0x0044: JSR(c, 0x1320, 0xC00611); GUARD_JSR(c, sp_call, 0x1320); break; /* dispatch_all_native_dialogue_window_closing_phases */
        case 0x0046: JSR(c, 0x1320, 0xC012FF); GUARD_JSR(c, sp_call, 0x1320); break; /* dispatch_native_dialogue_window_completion_phase */
        case 0x0048: JSR(c, 0x1320, 0xC0111A); GUARD_JSR(c, sp_call, 0x1320); break; /* dispatch_all_eleven_native_dialogue_render_phases */
        case 0x004A: JSR(c, 0x1320, 0xC0111A); GUARD_JSR(c, sp_call, 0x1320); break; /* dispatch_all_eleven_native_dialogue_render_phases */
        case 0x004C: JSR(c, 0x1320, 0xC0111A); GUARD_JSR(c, sp_call, 0x1320); break; /* dispatch_all_eleven_native_dialogue_render_phases */
        case 0x004E: JSR(c, 0x1320, 0xC0111A); GUARD_JSR(c, sp_call, 0x1320); break; /* dispatch_all_eleven_native_dialogue_render_phases */
        case 0x0050: JSR(c, 0x1320, 0xC0111A); GUARD_JSR(c, sp_call, 0x1320); break; /* dispatch_all_eleven_native_dialogue_render_phases */
        case 0x0052: JSR(c, 0x1320, 0xC0111A); GUARD_JSR(c, sp_call, 0x1320); break; /* dispatch_all_eleven_native_dialogue_render_phases */
        case 0x0054: JSR(c, 0x1320, 0xC0111A); GUARD_JSR(c, sp_call, 0x1320); break; /* dispatch_all_eleven_native_dialogue_render_phases */
        case 0x0056: JSR(c, 0x1320, 0xC01A46); GUARD_JSR(c, sp_call, 0x1320); break; /* dispatch_three_native_dialogue_numeric_selection_phases */
        case 0x0058: JSR(c, 0x1320, 0xC0111A); GUARD_JSR(c, sp_call, 0x1320); break; /* dispatch_all_eleven_native_dialogue_render_phases */
        case 0x005A: JSR(c, 0x1320, 0xC0111A); GUARD_JSR(c, sp_call, 0x1320); break; /* dispatch_all_eleven_native_dialogue_render_phases */
        case 0x005C: JSR(c, 0x1320, 0xC00F6C); GUARD_JSR(c, sp_call, 0x1320); break; /* request_dialogue_primary_window_pause */
        case 0x005E: JSR(c, 0x1320, 0xC00F59); GUARD_JSR(c, sp_call, 0x1320); break; /* request_dialogue_secondary_window_pause */
        case 0x0060: JSR(c, 0x1320, 0xC00F87); GUARD_JSR(c, sp_call, 0x1320); break; /* open_temporary_numeric_dialogue_window */
        case 0x0062: JSR(c, 0x1320, 0xC004E2); GUARD_JSR(c, sp_call, 0x1320); break; /* expand_dialogue_window_tile_forward_with_plane_mask */
        case 0x0064: JSR(c, 0x1320, 0xC0054D); GUARD_JSR(c, sp_call, 0x1320); break; /* expand_dialogue_window_tile_forward_with_reversed_bits */
        case 0x0066: JSR(c, 0x1320, 0xC00515); GUARD_JSR(c, sp_call, 0x1320); break; /* expand_dialogue_window_tile_backward */
        case 0x0068: JSR(c, 0x1320, 0xC00583); GUARD_JSR(c, sp_call, 0x1320); break; /* expand_dialogue_window_tile_backward_with_reversed_bits */
        default: JSR(c, 0x1320, 0xC00000 | BUS16(c, 0xC00000 + (uint16_t)(0x1098 + ((uint8_t)(value2 << 1))))); GUARD_JSR(c, sp_call, 0x1320);
        }
        }
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool zero_ret = r->z;
        bool negative_ret = r->n;
        bool overflow_ret = r->v;
        m_flag = m_ret;
        x_flag = x_ret;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        x1 = x_ret2;
        y1 = y_ret;
        carry1 = carry_ret;
        zero1 = zero_ret;
        negative1 = negative_ret;
        overflow1 = overflow_ret;
        data_bank = db_ret;
        direct_page = dp_ret;
    } else {
        uint8_t value3 = RAM8(0xA15F);
        r->a = (uint8_t)(value3 << 1);
        r->x = (uint8_t)(value3 << 1);
        r->c = value3 & 0x80;
        r->z = (uint8_t)(value3 << 1) == 0;
        r->n = (uint8_t)(value3 << 1) & 0x8000;
        { const uint16_t sp_call = r->sp;
        switch ((uint8_t)(value3 << 1)) {
        case 0x0000: JSR(c, 0x1311, 0xC0062A); GUARD_JSR(c, sp_call, 0x1311); break; /* begin_dialogue_window_erasure_at_saved_origin */
        case 0x0002: JSR(c, 0x1311, 0xC00638); GUARD_JSR(c, sp_call, 0x1311); break; /* begin_dialogue_window_erasure_at_current_cursor */
        case 0x0004: JSR(c, 0x1311, 0xC006A8); GUARD_JSR(c, sp_call, 0x1311); break; /* finish_dialogue_window_and_resume_script_cursor */
        case 0x0006: JSR(c, 0x1311, 0xC0090F); GUARD_JSR(c, sp_call, 0x1311); break; /* initialize_dialogue_window_font_buffer_and_style */
        case 0x0008: JSR(c, 0x1311, 0xC00A34); GUARD_JSR(c, sp_call, 0x1311); break; /* initialize_dialogue_window_corner_pairs */
        case 0x000A: JSR(c, 0x1311, 0xC00A8D); GUARD_JSR(c, sp_call, 0x1311); break; /* expand_dialogue_window_corners_in_four_steps */
        case 0x000C: JSR(c, 0x1311, 0xC00B4F); GUARD_JSR(c, sp_call, 0x1311); break; /* publish_native_dialogue_frame_border_rows */
        case 0x000E: JSR(c, 0x1311, 0xC00C2A); GUARD_JSR(c, sp_call, 0x1311); break; /* publish_native_dialogue_frame_side_pairs */
        case 0x0010: JSR(c, 0x1311, 0xC00D51); GUARD_JSR(c, sp_call, 0x1311); break; /* finish_dialogue_window_frame_and_restore_suspended_script */
        case 0x0012: JSR(c, 0x1311, 0xC006EA); GUARD_JSR(c, sp_call, 0x1311); break; /* collapse_dialogue_window_rows_and_publish_blank_tile */
        case 0x0014: JSR(c, 0x1311, 0xC007E0); GUARD_JSR(c, sp_call, 0x1311); break; /* restore_dialogue_style_or_publish_collapsed_window_band */
        case 0x0016: JSR(c, 0x1311, 0xC00844); GUARD_JSR(c, sp_call, 0x1311); break; /* collapse_dialogue_window_corner_pairs */
        case 0x0018: JSR(c, 0x1311, 0xC0089E); GUARD_JSR(c, sp_call, 0x1311); break; /* erase_final_dialogue_window_corner_cells */
        case 0x001A: JSR(c, 0x1311, 0xC008C3); GUARD_JSR(c, sp_call, 0x1311); break; /* finish_dialogue_window_closing_and_restore_suspended_context */
        case 0x001C: JSR(c, 0x1311, 0xC00229); GUARD_JSR(c, sp_call, 0x1311); break; /* dispatch_all_native_dialogue_window_construction_phases */
        case 0x001E: JSR(c, 0x1311, 0xC00611); GUARD_JSR(c, sp_call, 0x1311); break; /* dispatch_all_native_dialogue_window_closing_phases */
        case 0x0020: JSR(c, 0x1311, 0xC012FF); GUARD_JSR(c, sp_call, 0x1311); break; /* dispatch_native_dialogue_window_completion_phase */
        case 0x0022: JSR(c, 0x1311, 0xC0111A); GUARD_JSR(c, sp_call, 0x1311); break; /* dispatch_all_eleven_native_dialogue_render_phases */
        case 0x0024: JSR(c, 0x1311, 0xC0111A); GUARD_JSR(c, sp_call, 0x1311); break; /* dispatch_all_eleven_native_dialogue_render_phases */
        case 0x0026: JSR(c, 0x1311, 0xC0111A); GUARD_JSR(c, sp_call, 0x1311); break; /* dispatch_all_eleven_native_dialogue_render_phases */
        case 0x0028: JSR(c, 0x1311, 0xC0111A); GUARD_JSR(c, sp_call, 0x1311); break; /* dispatch_all_eleven_native_dialogue_render_phases */
        case 0x002A: JSR(c, 0x1311, 0xC0111A); GUARD_JSR(c, sp_call, 0x1311); break; /* dispatch_all_eleven_native_dialogue_render_phases */
        case 0x002C: JSR(c, 0x1311, 0xC0111A); GUARD_JSR(c, sp_call, 0x1311); break; /* dispatch_all_eleven_native_dialogue_render_phases */
        case 0x002E: JSR(c, 0x1311, 0xC0111A); GUARD_JSR(c, sp_call, 0x1311); break; /* dispatch_all_eleven_native_dialogue_render_phases */
        case 0x0030: JSR(c, 0x1311, 0xC01A46); GUARD_JSR(c, sp_call, 0x1311); break; /* dispatch_three_native_dialogue_numeric_selection_phases */
        case 0x0032: JSR(c, 0x1311, 0xC0111A); GUARD_JSR(c, sp_call, 0x1311); break; /* dispatch_all_eleven_native_dialogue_render_phases */
        case 0x0034: JSR(c, 0x1311, 0xC0111A); GUARD_JSR(c, sp_call, 0x1311); break; /* dispatch_all_eleven_native_dialogue_render_phases */
        case 0x0036: JSR(c, 0x1311, 0xC00F6C); GUARD_JSR(c, sp_call, 0x1311); break; /* request_dialogue_primary_window_pause */
        case 0x0038: JSR(c, 0x1311, 0xC00F59); GUARD_JSR(c, sp_call, 0x1311); break; /* request_dialogue_secondary_window_pause */
        case 0x003A: JSR(c, 0x1311, 0xC00F87); GUARD_JSR(c, sp_call, 0x1311); break; /* open_temporary_numeric_dialogue_window */
        case 0x003C: JSR(c, 0x1311, 0xC004E2); GUARD_JSR(c, sp_call, 0x1311); break; /* expand_dialogue_window_tile_forward_with_plane_mask */
        case 0x003E: JSR(c, 0x1311, 0xC0054D); GUARD_JSR(c, sp_call, 0x1311); break; /* expand_dialogue_window_tile_forward_with_reversed_bits */
        case 0x0040: JSR(c, 0x1311, 0xC00515); GUARD_JSR(c, sp_call, 0x1311); break; /* expand_dialogue_window_tile_backward */
        case 0x0042: JSR(c, 0x1311, 0xC00583); GUARD_JSR(c, sp_call, 0x1311); break; /* expand_dialogue_window_tile_backward_with_reversed_bits */
        default: JSR(c, 0x1311, 0xC00000 | BUS16(c, 0xC00000 + (uint16_t)(0x10BE + ((uint8_t)(value3 << 1))))); GUARD_JSR(c, sp_call, 0x1311);
        }
        }
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        bool m_ret2 = r->mf;
        bool x_ret3 = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t x_ret4 = r->x;
        uint16_t y_ret2 = r->y;
        bool carry_ret2 = r->c;
        bool zero_ret2 = r->z;
        bool negative_ret2 = r->n;
        bool overflow_ret2 = r->v;
        m_flag = m_ret2;
        x_flag = x_ret3;
        a1 = (uint8_t)a_all2;
        a_hi1 = a_all2 >> 8;
        x1 = x_ret4;
        y1 = y_ret2;
        carry1 = carry_ret2;
        zero1 = zero_ret2;
        negative1 = negative_ret2;
        overflow1 = overflow_ret2;
        data_bank = db_ret2;
        direct_page = dp_ret2;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = m_flag;
    r->xf = x_flag;
    r->db = data_bank;
    r->dp = direct_page;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC012FF, SOM_RTS, "gen", dispatch_native_dialogue_window_completion_phase, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 35, 17)
