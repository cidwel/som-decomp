#include "som_c.h"

/* C0B08C advance_complete_main_map_frame_and_finalize_native_oam   [class B, 104 bytes, 40 instructions]
 * Source: src/rom/advance_complete_main_map_frame_and_finalize_native_oam.s
 * Documented in docs/map-main-frame.md
 * Entry: M=8 bit X=any DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void advance_complete_main_map_frame_and_finalize_native_oam(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSL(c, 0xB08F, 0xC2C786); /* update_idle_party_message_queue_or_preempt_requested_dialogue */
    r->mf = 1; /* sep */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    uint8_t value = RAM8(0x00D0);
    uint8_t a2;
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    bool carry2;
    bool zero2;
    bool negative2;
    bool overflow2;
    if (value == 0) {
        a2 = value;
        a_hi2 = a_all >> 8;
        x2 = x_ret;
        y2 = y_ret;
        carry2 = carry_ret;
        zero2 = value == 0;
        negative2 = value & 0x80;
        overflow2 = overflow_ret;
    } else {
        uint8_t value2 = RAM8(0x0056);
        uint8_t a1;
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        bool carry1;
        bool zero1;
        bool negative1;
        bool overflow1;
        if (value2 != 3) {
            a1 = value2;
            a_hi1 = a_all >> 8;
            x1 = x_ret;
            y1 = y_ret;
            carry1 = value2 >= 3;
            zero1 = value2 == 3;
            negative1 = (uint8_t)(value2 - 3) & 0x80;
            overflow1 = overflow_ret;
        } else {
            r->a = (a_all >> 8 << 8) | value2;
            r->c = value2 >= 3;
            r->mf = 1;
            r->xf = 0;
            JSL(c, 0xB09F, 0xC1E8C7); /* dispatch_native_event_frame_with_saved_scene_data_bank */
            uint16_t a_all2 = r->a;
            uint16_t x_ret2 = r->x;
            uint16_t y_ret2 = r->y;
            bool carry_ret2 = r->c;
            bool zero_ret2 = r->z;
            bool negative_ret2 = r->n;
            bool overflow_ret2 = r->v;
            a1 = (uint8_t)a_all2;
            a_hi1 = a_all2 >> 8;
            x1 = x_ret2;
            y1 = y_ret2;
            carry1 = carry_ret2;
            zero1 = zero_ret2;
            negative1 = negative_ret2;
            overflow1 = overflow_ret2;
        }
        a2 = a1;
        a_hi2 = a_hi1;
        x2 = x1;
        y2 = y1;
        carry2 = carry1;
        zero2 = zero1;
        negative2 = negative1;
        overflow2 = overflow1;
    }
    r->y = y2;
    r->v = overflow2;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0xB0A2, 0xC0BCCC); /* initialize_software_oam_and_optional_spell_frames */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0xB0A5, 0xC0A462); /* advance_main_frame_menu_transition_and_native_wait */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0xB0A8, 0xC08B5E); /* update_complete_map_frame_screen_effects */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0xB0AB, 0xC0DB1E); /* advance_all_automatic_map_layer_motion */
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xB0AE, 0xC093B9); /* poll_three_controller_words_and_publish_pressed_edges */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0xB0B1, 0xC0B69C); /* schedule_three_controller_inputs_and_publish_actor_motion */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0xB0B4, 0xC0D5C0); /* scan_map_contacts_then_dispatch_hero_and_actor_motion */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0xB0B7, 0xC0B4FE); /* coordinate_map_screen_requests_doors_and_hero_tile_events */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0xB0BA, 0xC0C59F); /* detect_map_scroll_edges_and_prepare_both_layer_tile_buffers */
    r->mf = 1;
    r->xf = 0;
    JSL(c, 0xB0BE, 0xC1B033); /* advance_selected_graphics_offset_pattern_with_saved_data_bank */
    r->mf = 1;
    r->xf = 1;
    JSL(c, 0xB0C2, 0xC1BFE0); /* advance_timed_map_graphics_animation_records */
    r->mf = 1;
    r->xf = 1;
    JSL(c, 0xB0C6, 0xC2BAD6); /* advance_timed_menu_tile_records_on_even_frames */
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xB0C9, 0xC0EB06); /* advance_native_charge_and_partner_follow_frame */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0xB0CC, 0xC0B0D3); /* dispatch_five_phase_map_actor_animation_combat_and_menu_frame */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0xB0CF, 0xC0E38E); /* emit_complete_map_actor_and_hud_sprites */
    uint16_t y_ret16 = r->y;
    bool carry_ret17 = r->c;
    bool overflow_ret17 = r->v;
    uint16_t x3 = RAM16(0x007C);
    bool carry3 = carry_ret17;
    for (;;) {
        uint16_t value4 = RAM16(0x0120);
        uint16_t x4;
        bool carry4;
        if (x3 >= value4) {
            x4 = x3;
            carry4 = x3 >= value4;
        } else {
            RAM16_SET(0x0800 + x3, 0xE0FF);
            if ((uint16_t)(x3 + 4) < 0x01FC) {
                uint16_t x3_next = (uint16_t)(x3 + 4);
                bool carry3_next = (uint16_t)(x3 + 4) >= 0x01FC;
                x3 = x3_next;
                carry3 = carry3_next;
                continue;
            }
            x4 = (uint16_t)(x3 + 4);
            carry4 = (uint16_t)(x3 + 4) >= 0x01FC;
        }
        x3 = x4;
        carry3 = carry4;
        break;
    }
    RAM16_SET(0x0800 + x3, 0xE0FF);
    uint16_t value5 = RAM16(0x007C);
    RAM16_SET(0x0120, value5);
    r->a = value5;
    r->x = x3;
    r->y = y_ret16;
    r->c = carry3;
    r->v = overflow_ret17;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0B08C, SOM_RTS, "hand", advance_complete_main_map_frame_and_finalize_native_oam, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, -1, 3136, 40)
