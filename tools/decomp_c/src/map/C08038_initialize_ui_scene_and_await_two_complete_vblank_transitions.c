#include "som_c.h"

/* C08038 initialize_ui_scene_and_await_two_complete_vblank_transitions   [class D, 91 bytes, 37 instructions]
 * Source: src/rom/initialize_ui_scene_and_await_two_complete_vblank_transitions.s
 * Documented in docs/ui-native-ui-entry-prefix.md
 * Entry: M=8 bit X=8 bit DB=any D=any.  Callers read: ABXYCV.
 */
/* The routine resets S and never returns; the original code is cut at the first RTS taken at the entry S of this routine.  A
 * subroutine called while S is two above that value returns at exactly that RTS, so the routine ends there (not in an exit-address window,
 * where only the exit address ends the run). */
#undef I_JSR
#define I_JSR(c, retpc, target) do { const uint16_t s_cut_ = (c)->cpu.sp; push16(c, (retpc)); \
    if ((c)->stub_calls) { (c)->stub_n++; i_rts(c); } else { som_call_nested(c, (target), SOM_RTS); if ((c)->unwound) return; } \
    if (!(c)->fail && (c)->cpu.pc != (uint16_t)((retpc) + 1)) { (c)->fail = 3; return; } \
    if (!(c)->fail && !(c)->stub_calls && !(c)->exit_only && (uint16_t)(s_cut_ - 2) == sp_entry) return; } while (0)

static void initialize_ui_scene_and_await_two_complete_vblank_transitions(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 1)) return;
    const uint16_t sp_entry = r->sp;
    { const uint16_t sp_call = r->sp; JSL(c, 0x803B, 0x02B0D7); GUARD_JSL(c, sp_call, 0x803B); } /* derive_ui_scene_entry_coordinates_from_carried_counter */
    r->sp = 0x01FF;
    c->routine_ret = 0; /* S was reset: the entry S says nothing about the returns of the callees */
    r->x = 0x01FF;
    r->xf = 0; /* REP #$10 */
    { const uint16_t sp_call = r->sp; JSR(c, 0x8044, 0xC087C4); GUARD_JSR(c, sp_call, 0x8044); } /* blank_display_disable_interrupts_and_clear_windows_for_map_entry */
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8047, 0xC082C4); GUARD_JSR(c, sp_call, 0x8047); } /* initialize_complete_ui_scene_constructor_and_row_publication */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    uint16_t a_all3 = r->a;
    uint16_t y_ret = r->y;
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    BUS8_SET(c, (db_ret << 0x10) + 0x2105, 7);
    uint8_t x1 = 2;
    bool overflow1 = overflow_ret2;
    for (;;) {
        uint8_t value = BUS8(c, (db_ret << 0x10) + 0x4210);
        if (!(value & 0x80)) {
            overflow1 = value & 0x40;
            continue;
        }
        bool overflow2 = value & 0x40;
        for (;;) {
            uint8_t value2 = BUS8(c, (db_ret << 0x10) + 0x4210);
            overflow2 = value2 & 0x40;
            if (!(value2 & 0x80)) break;
        }
        x1 = (uint8_t)(x1 - 1);
        overflow1 = overflow2;
        if (!(x1 != 0)) break;
    }
    BUS8_SET(c, (db_ret << 0x10) + 0x4200, 0xB1);
    uint8_t a1 = 7;
    uint8_t a_hi1 = a_all3 >> 8;
    uint8_t x2 = 0xB1;
    uint8_t y1 = (uint8_t)y_ret;
    bool carry1 = carry_ret2;
    bool overflow3 = overflow1;
    uint8_t data_bank = db_ret;
    uint16_t direct_page = dp_ret;
    for (;;) {
        r->a = (a_hi1 << 8) | a1;
        r->x = x2;
        r->y = y1;
        r->c = carry1;
        r->v = overflow3;
        r->mf = 1;
        r->xf = 1;
        r->db = data_bank;
        r->dp = direct_page;
        r->i = 0;
        if (som_spin_exit(c, 0xC08064)) return; /* exit=C08064@2: the loop head, reached again after the loop-back BRA has run once */
        { const uint16_t sp_call = r->sp; JSR(c, 0x8068, 0xC08B5E); GUARD_JSR(c, sp_call, 0x8068); } /* update_complete_map_frame_screen_effects */
        { const uint16_t sp_call = r->sp; JSR(c, 0x806B, 0xC083A8); GUARD_JSR(c, sp_call, 0x806B); } /* dispatch_complete_manual_or_automatic_ui_motion_and_publish_focus */
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x806E, 0xC0983A); GUARD_JSR(c, sp_call, 0x806E); } /* prepare_complete_ui_frame_tile_row_and_column */
        uint16_t dp_ret3 = r->dp;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8071, 0xC0908B); GUARD_JSR(c, sp_call, 0x8071); } /* derive_ui_frame_matrix_and_select_hdma_record_bank */
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8074, 0xC095A0); GUARD_JSR(c, sp_call, 0x8074); } /* build_scaled_ui_raster_window_records_and_request_native_publication */
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8077, 0xC09AB8); GUARD_JSR(c, sp_call, 0x8077); } /* publish_ui_frame_sprites */
        uint8_t db_ret4 = r->db;
        { const uint16_t sp_call = r->sp; JSL(c, 0x807B, 0x01FDE4); GUARD_JSL(c, sp_call, 0x807B); } /* publish_ui_angular_icons_and_focus_marker_then_hide_unused_sprites */
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x807E, 0xC087E0); GUARD_JSR(c, sp_call, 0x807E); } /* poll_selected_hero_controller_and_restore_ui_input_word */
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8081, 0xC08272); GUARD_JSR(c, sp_call, 0x8081); } /* advance_ui_visibility_zoom_state_and_sprite_coordinate_transition */
        r->mf = 1;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8084, 0xC08093); GUARD_JSR(c, sp_call, 0x8084); } /* advance_ui_tile_buffers_and_native_transition_or_sound_requests */
        bool x_ret16 = r->xf;
        uint16_t a_all13 = r->a;
        uint16_t x_ret17 = r->x;
        uint16_t y_ret10 = r->y;
        bool carry_ret12 = r->c;
        bool overflow_ret12 = r->v;
        RAM8(0x00EC + dp_ret3) = 0x81;
        bool overflow4 = overflow_ret12;
        for (;;) {
            uint8_t value3 = RAM8(0x00EC + dp_ret3);
            overflow4 = value3 & 0x40;
            if (!((value3 & 1) != 0)) break;
        }
        if (x_ret16 != 1) { c->fail = 3; return; }
        /* exit-address window at the loop-back BRA (C0:8091): the state the original has there */
        r->a = (uint16_t)((a_all13 & 0xFF00) | 1);
        r->x = x_ret17;
        r->y = y_ret10;
        r->c = carry_ret12;
        r->v = overflow4;
        r->mf = 1;
        r->xf = 1;
        r->i = 0;
        if (som_spin_exit(c, 0xC08091)) return;
        a1 = 1;
        a_hi1 = a_all13 >> 8;
        x2 = x_ret17;
        y1 = y_ret10;
        carry1 = carry_ret12;
        overflow3 = overflow4;
        data_bank = db_ret4;
        direct_page = dp_ret3;
    }
}
SOM_REGISTER(0xC08038, SOM_RTS, "hand", initialize_ui_scene_and_await_two_complete_vblank_transitions, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 91, 37)
