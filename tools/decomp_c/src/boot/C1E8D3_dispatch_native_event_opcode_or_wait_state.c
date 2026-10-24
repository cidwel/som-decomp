#include "som_c.h"

static void event_return_and_resume_native_dispatch(SomCtx *c);
static void event_release_party_freeze(SomCtx *c);
static void event_clear_remembered_map_destination(SomCtx *c);
static void event_transition_to_remembered_map(SomCtx *c);
static void open_event_weapon_upgrade_ring_and_restore_native_sprite_context(SomCtx *c);
static void event_jump_to_numeric_event_and_resume_dispatch(SomCtx *c);
static void event_transition_to_ten_bit_map_operand(SomCtx *c);
static void event_request_scroll_operand_then_end_script(SomCtx *c);
static void event_request_fade_operand_and_update_transition_flag(SomCtx *c);
static void event_insert_inventory_operand_then_continue_script(SomCtx *c);
static void advance_party_command_cursor(SomCtx *c);
static void event_call_numeric_event_with_single_saved_return(SomCtx *c);
static void event_increment_flag_nibble_or_restore_party_scene(SomCtx *c);
static void event_decrement_flag_nibble_and_resume_dispatch(SomCtx *c);
static void event_request_scene_palette_and_brightness_transition(SomCtx *c);
static void open_event_buy_ring_with_literal_script_operand(SomCtx *c);
static void event_restore_selected_actor_health_mana_or_combat_state(SomCtx *c);
static void event_set_actor_motion_and_resume_dispatch(SomCtx *c);
static void event_set_actor_cardinal_velocity_and_presentation(SomCtx *c);
static void event_store_two_byte_scene_parameter(SomCtx *c);
static void event_set_actor_motion_and_pause_its_execution(SomCtx *c);
static void event_branch_on_current_actor_slot(SomCtx *c);
static void event_branch_on_controller_binding_mask(SomCtx *c);
static void event_branch_on_leading_assigned_controller_count(SomCtx *c);
static void event_branch_on_inclusive_flag_nibble_range(SomCtx *c);
static void event_update_or_test_flag_nibble_then_resume_dispatch(SomCtx *c);
static void event_combine_indexed_flag_nibble_and_execute_operation(SomCtx *c);
static void event_branch_on_selected_actor_byte_field(SomCtx *c);
static void event_wait_for_party_gather(SomCtx *c);
static void event_wait_for_text_then_resume_script(SomCtx *c);
static void event_wait_for_frame_count(SomCtx *c);
static void event_wait_for_selected_actor_pad_press(SomCtx *c);
static void event_resume_dispatch_immediately(SomCtx *c);
static void event_wait_for_all_active_actors_idle(SomCtx *c);
static void event_wait_for_camera_center(SomCtx *c);
static void event_reserved_state_resume_dispatch(SomCtx *c);

/* C1E8D3 dispatch_native_event_opcode_or_wait_state   [class C, 1410 bytes, 693 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Documented in docs/event-vm-control.md
 * Entry: M=any X=any DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void dispatch_native_event_opcode_or_wait_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t value = RAM8(0x00E2);
    uint8_t value2 = RAM8(0x00FF);
    uint8_t value3 = RAM8(0x0052);
    if (((value & 1) | value2 | value3) == 0) {
        uint8_t value4 = RAM8(0x00E8);
        if ((value4 & 4) != 0) {
            SET_A8(r, value4 & 4);
            r->x = (uint8_t)x;
            r->y = (uint8_t)y;
            r->z = (value4 & 4) == 0;
            r->n = value4 & 4 & 0x80;
            r->mf = 1;
            r->xf = 1;
            RETURN_RTS(c);
        }
        uint8_t value5 = RAM8(0x00D0);
        if (!(value5 & 0x80)) {
            uint16_t value6 = BUS16_RDL(c, (RAM8(0x00D3) << 0x10) + RAM16(0x00D1), RAM8(0x00D3));
            RAM16_SET(0x0004, value6);
            uint8_t a1;
            if ((uint8_t)value6 < 0x50) {
                a1 = (uint8_t)value6;
            } else {
                a1 = 0x50;
            }
            r->a = (value6 >> 8 << 8) | (uint8_t)(a1 << 1);
            r->x = (uint8_t)((value6 >> 8 << 8) | (uint8_t)(a1 << 1));
            r->y = (uint8_t)y;
            r->c = a1 & 0x80;
            r->z = (uint8_t)((value6 >> 8 << 8) | (uint8_t)(a1 << 1)) == 0;
            r->n = (uint8_t)((value6 >> 8 << 8) | (uint8_t)(a1 << 1)) & 0x80;
            r->mf = 1;
            r->xf = 1;
            switch ((uint8_t)((value6 >> 8 << 8) | (uint8_t)(a1 << 1))) {
            case 0x0000: TAIL_CALL_DYN(c, 0xC1E9C4, SOM_RTS); /* event_end_and_release_party_controls */
            case 0x0002: TAIL_CALL_DYN(c, 0xC1E9E7, SOM_RTS); /* event_noop_advance_script */
            case 0x0004: event_return_and_resume_native_dispatch(c); return;
            case 0x0006: TAIL_CALL_DYN(c, 0xC1E9FB, SOM_RTS); /* event_gather_party_and_stop_other_heroes */
            case 0x0008: TAIL_CALL_DYN(c, 0xC1EA26, SOM_RTS); /* event_toggle_hero_visibility */
            case 0x000A: TAIL_CALL_DYN(c, 0xC1EA26, SOM_RTS); /* event_toggle_hero_visibility */
            case 0x000C: TAIL_CALL_DYN(c, 0xC1EA43, SOM_RTS); /* event_request_party_freeze_until_ready */
            case 0x000E: event_release_party_freeze(c); return;
            case 0x0010: TAIL_CALL_DYN(c, 0xC1EA59, SOM_RTS); /* event_yield_until_all_actors_idle */
            case 0x0012: TAIL_CALL_DYN(c, 0xC1EA62, SOM_RTS); /* event_refresh_all_map_object_slots */
            case 0x0014: TAIL_CALL_DYN(c, 0xC1EA99, SOM_RTS); /* event_reload_map_pieces_and_redraw */
            case 0x0016: TAIL_CALL_DYN(c, 0xC1EAA3, SOM_RTS); /* event_remember_current_map_destination */
            case 0x0018: event_clear_remembered_map_destination(c); return;
            case 0x001A: event_transition_to_remembered_map(c); return;
            case 0x001C: TAIL_CALL_DYN(c, 0xC1EAC1, SOM_RTS); /* open_event_sale_ring_and_restore_native_sprite_context */
            case 0x001E: open_event_weapon_upgrade_ring_and_restore_native_sprite_context(c); return;
            case 0x0020: event_jump_to_numeric_event_and_resume_dispatch(c); return;
            case 0x0022: event_jump_to_numeric_event_and_resume_dispatch(c); return;
            case 0x0024: event_jump_to_numeric_event_and_resume_dispatch(c); return;
            case 0x0026: event_jump_to_numeric_event_and_resume_dispatch(c); return;
            case 0x0028: event_jump_to_numeric_event_and_resume_dispatch(c); return;
            case 0x002A: event_jump_to_numeric_event_and_resume_dispatch(c); return;
            case 0x002C: event_jump_to_numeric_event_and_resume_dispatch(c); return;
            case 0x002E: event_jump_to_numeric_event_and_resume_dispatch(c); return;
            case 0x0030: event_transition_to_ten_bit_map_operand(c); return;
            case 0x0032: event_transition_to_ten_bit_map_operand(c); return;
            case 0x0034: event_transition_to_ten_bit_map_operand(c); return;
            case 0x0036: event_transition_to_ten_bit_map_operand(c); return;
            case 0x0038: event_request_scroll_operand_then_end_script(c); return;
            case 0x003A: event_request_fade_operand_and_update_transition_flag(c); return;
            case 0x003C: event_insert_inventory_operand_then_continue_script(c); return;
            case 0x003E: advance_party_command_cursor(c); return;
            case 0x0040: event_call_numeric_event_with_single_saved_return(c); return;
            case 0x0042: event_call_numeric_event_with_single_saved_return(c); return;
            case 0x0044: event_call_numeric_event_with_single_saved_return(c); return;
            case 0x0046: event_call_numeric_event_with_single_saved_return(c); return;
            case 0x0048: event_call_numeric_event_with_single_saved_return(c); return;
            case 0x004A: event_call_numeric_event_with_single_saved_return(c); return;
            case 0x004C: event_call_numeric_event_with_single_saved_return(c); return;
            case 0x004E: event_call_numeric_event_with_single_saved_return(c); return;
            case 0x0050: TAIL_CALL_DYN(c, 0xC1EC1A, SOM_RTS); /* event_wait_for_ticks_or_selected_controller */
            case 0x0052: event_increment_flag_nibble_or_restore_party_scene(c); return;
            case 0x0054: event_decrement_flag_nibble_and_resume_dispatch(c); return;
            case 0x0056: TAIL_CALL_DYN(c, 0xC1ECA0, SOM_RTS); /* event_activate_actor_and_rebuild_party_hud */
            case 0x0058: TAIL_CALL_DYN(c, 0xC1ED01, SOM_RTS); /* event_remove_actor_and_reassign_controller */
            case 0x005A: event_request_scene_palette_and_brightness_transition(c); return;
            case 0x005C: open_event_buy_ring_with_literal_script_operand(c); return;
            case 0x005E: event_restore_selected_actor_health_mana_or_combat_state(c); return;
            case 0x0060: TAIL_CALL_DYN(c, 0xC1EE8C, SOM_RTS); /* event_assign_flag_byte_preserving_previous_upper_nibble */
            case 0x0062: event_set_actor_motion_and_resume_dispatch(c); return;
            case 0x0064: event_set_actor_cardinal_velocity_and_presentation(c); return;
            case 0x0066: event_store_two_byte_scene_parameter(c); return;
            case 0x0068: event_set_actor_motion_and_pause_its_execution(c); return;
            case 0x006A: TAIL_CALL_DYN(c, 0xC1EFDF, SOM_RTS); /* advance_event_cursor_wait_for_nmi_and_publish_party_hud */
            case 0x006C: TAIL_CALL_DYN(c, 0xC1EFE7, SOM_RTS); /* consume_event_gold_word_and_add_or_spend_with_native_cap */
            case 0x006E: TAIL_CALL_DYN(c, 0xC1EFE7, SOM_RTS); /* consume_event_gold_word_and_add_or_spend_with_native_cap */
            case 0x0070: event_branch_on_current_actor_slot(c); return;
            case 0x0072: TAIL_CALL_DYN(c, 0xC1F010, SOM_RTS); /* event_assign_selected_actor_secondary_byte_field */
            case 0x0074: TAIL_CALL_DYN(c, 0xC1F04B, SOM_RTS); /* event_assign_selected_actor_primary_word_field */
            case 0x0076: event_branch_on_controller_binding_mask(c); return;
            case 0x0078: event_branch_on_leading_assigned_controller_count(c); return;
            case 0x007A: TAIL_CALL_DYN(c, 0xC1F0E9, SOM_RTS); /* event_reserved_3d_stall */
            case 0x007C: TAIL_CALL_DYN(c, 0xC1F0EA, SOM_RTS); /* event_reserved_3e_stall */
            case 0x007E: TAIL_CALL_DYN(c, 0xC1F0EB, SOM_RTS); /* event_reserved_3f_stall */
            case 0x0080: TAIL_CALL_DYN(c, 0xC1F0EC, SOM_RTS); /* event_read_audio_request_and_dispatch_native_sender */
            case 0x0082: TAIL_CALL_DYN(c, 0xC1F10E, SOM_RTS); /* event_decode_individual_map_piece_and_redraw */
            case 0x0084: event_branch_on_inclusive_flag_nibble_range(c); return;
            case 0x0086: event_update_or_test_flag_nibble_then_resume_dispatch(c); return;
            case 0x0088: TAIL_CALL_DYN(c, 0xC1F1CB, SOM_RTS); /* event_reserved_44_stall */
            case 0x008A: TAIL_CALL_DYN(c, 0xC1F1CC, SOM_RTS); /* event_reserved_45_stall */
            case 0x008C: TAIL_CALL_DYN(c, 0xC1F1CD, SOM_RTS); /* event_reserved_46_stall */
            case 0x008E: TAIL_CALL_DYN(c, 0xC1F1CE, SOM_RTS); /* event_reserved_47_stall */
            case 0x0090: event_combine_indexed_flag_nibble_and_execute_operation(c); return;
            case 0x0092: event_branch_on_selected_actor_byte_field(c); return;
            case 0x0094: event_branch_on_selected_actor_byte_field(c); return;
            case 0x0096: event_branch_on_selected_actor_byte_field(c); return;
            case 0x0098: event_branch_on_selected_actor_byte_field(c); return;
            case 0x009A: event_branch_on_selected_actor_byte_field(c); return;
            case 0x009C: event_branch_on_selected_actor_byte_field(c); return;
            case 0x009E: TAIL_CALL_DYN(c, 0xC1F279, SOM_RTS); /* event_reserved_4f_stall */
            case 0x00A0: TAIL_CALL_DYN(c, 0xC1F27A, SOM_RTS); /* event_enqueue_text_and_yield_to_text_state */
            default: { const uint16_t dyn_target = BUS16(c, 0xC10000 + (uint16_t)(0xE922 + ((uint8_t)((value6 >> 8 << 8) | (uint8_t)(a1 << 1))))); c->open_bus = (uint8_t)(dyn_target >> 8); TAIL_CALL_DYN(c, 0xC10000 | dyn_target, SOM_RTS); }
            }
        }
        r->a = (a >> 8 << 8) | (uint8_t)(value5 << 1);
        r->x = (uint8_t)((a >> 8 << 8) | (uint8_t)(value5 << 1));
        r->y = (uint8_t)y;
        r->c = value5 & 0x80;
        r->z = (uint8_t)((a >> 8 << 8) | (uint8_t)(value5 << 1)) == 0;
        r->n = (uint8_t)((a >> 8 << 8) | (uint8_t)(value5 << 1)) & 0x80;
        r->mf = 1;
        r->xf = 1;
        switch ((uint8_t)((a >> 8 << 8) | (uint8_t)(value5 << 1))) {
        case 0x0000: event_wait_for_party_gather(c); return;
        case 0x0002: event_wait_for_text_then_resume_script(c); return;
        case 0x0004: event_wait_for_frame_count(c); return;
        case 0x0006: event_wait_for_selected_actor_pad_press(c); return;
        case 0x0008: event_resume_dispatch_immediately(c); return;
        case 0x000A: event_wait_for_all_active_actors_idle(c); return;
        case 0x000C: event_wait_for_camera_center(c); return;
        case 0x000E: event_reserved_state_resume_dispatch(c); return;
        case 0x0010: event_reserved_state_resume_dispatch(c); return;
        case 0x0012: event_reserved_state_resume_dispatch(c); return;
        case 0x0014: event_reserved_state_resume_dispatch(c); return;
        case 0x0016: event_reserved_state_resume_dispatch(c); return;
        case 0x0018: event_reserved_state_resume_dispatch(c); return;
        case 0x001A: event_reserved_state_resume_dispatch(c); return;
        case 0x001C: event_reserved_state_resume_dispatch(c); return;
        case 0x001E: event_reserved_state_resume_dispatch(c); return;
        case 0x0020: TAIL_CALL_DYN(c, 0xC1E9C4, SOM_RTS); /* event_end_and_release_party_controls */
        case 0x0022: TAIL_CALL_DYN(c, 0xC1E9E7, SOM_RTS); /* event_noop_advance_script */
        case 0x0024: event_return_and_resume_native_dispatch(c); return;
        case 0x0026: TAIL_CALL_DYN(c, 0xC1E9FB, SOM_RTS); /* event_gather_party_and_stop_other_heroes */
        case 0x0028: TAIL_CALL_DYN(c, 0xC1EA26, SOM_RTS); /* event_toggle_hero_visibility */
        case 0x002A: TAIL_CALL_DYN(c, 0xC1EA26, SOM_RTS); /* event_toggle_hero_visibility */
        case 0x002C: TAIL_CALL_DYN(c, 0xC1EA43, SOM_RTS); /* event_request_party_freeze_until_ready */
        case 0x002E: event_release_party_freeze(c); return;
        case 0x0030: TAIL_CALL_DYN(c, 0xC1EA59, SOM_RTS); /* event_yield_until_all_actors_idle */
        case 0x0032: TAIL_CALL_DYN(c, 0xC1EA62, SOM_RTS); /* event_refresh_all_map_object_slots */
        case 0x0034: TAIL_CALL_DYN(c, 0xC1EA99, SOM_RTS); /* event_reload_map_pieces_and_redraw */
        case 0x0036: TAIL_CALL_DYN(c, 0xC1EAA3, SOM_RTS); /* event_remember_current_map_destination */
        case 0x0038: event_clear_remembered_map_destination(c); return;
        case 0x003A: event_transition_to_remembered_map(c); return;
        case 0x003C: TAIL_CALL_DYN(c, 0xC1EAC1, SOM_RTS); /* open_event_sale_ring_and_restore_native_sprite_context */
        case 0x003E: open_event_weapon_upgrade_ring_and_restore_native_sprite_context(c); return;
        case 0x0040: event_jump_to_numeric_event_and_resume_dispatch(c); return;
        case 0x0042: event_jump_to_numeric_event_and_resume_dispatch(c); return;
        case 0x0044: event_jump_to_numeric_event_and_resume_dispatch(c); return;
        case 0x0046: event_jump_to_numeric_event_and_resume_dispatch(c); return;
        case 0x0048: event_jump_to_numeric_event_and_resume_dispatch(c); return;
        case 0x004A: event_jump_to_numeric_event_and_resume_dispatch(c); return;
        case 0x004C: event_jump_to_numeric_event_and_resume_dispatch(c); return;
        case 0x004E: event_jump_to_numeric_event_and_resume_dispatch(c); return;
        case 0x0050: event_transition_to_ten_bit_map_operand(c); return;
        case 0x0052: event_transition_to_ten_bit_map_operand(c); return;
        case 0x0054: event_transition_to_ten_bit_map_operand(c); return;
        case 0x0056: event_transition_to_ten_bit_map_operand(c); return;
        case 0x0058: event_request_scroll_operand_then_end_script(c); return;
        case 0x005A: event_request_fade_operand_and_update_transition_flag(c); return;
        case 0x005C: event_insert_inventory_operand_then_continue_script(c); return;
        case 0x005E: advance_party_command_cursor(c); return;
        case 0x0060: event_call_numeric_event_with_single_saved_return(c); return;
        case 0x0062: event_call_numeric_event_with_single_saved_return(c); return;
        case 0x0064: event_call_numeric_event_with_single_saved_return(c); return;
        case 0x0066: event_call_numeric_event_with_single_saved_return(c); return;
        case 0x0068: event_call_numeric_event_with_single_saved_return(c); return;
        case 0x006A: event_call_numeric_event_with_single_saved_return(c); return;
        case 0x006C: event_call_numeric_event_with_single_saved_return(c); return;
        case 0x006E: event_call_numeric_event_with_single_saved_return(c); return;
        case 0x0070: TAIL_CALL_DYN(c, 0xC1EC1A, SOM_RTS); /* event_wait_for_ticks_or_selected_controller */
        case 0x0072: event_increment_flag_nibble_or_restore_party_scene(c); return;
        case 0x0074: event_decrement_flag_nibble_and_resume_dispatch(c); return;
        case 0x0076: TAIL_CALL_DYN(c, 0xC1ECA0, SOM_RTS); /* event_activate_actor_and_rebuild_party_hud */
        case 0x0078: TAIL_CALL_DYN(c, 0xC1ED01, SOM_RTS); /* event_remove_actor_and_reassign_controller */
        case 0x007A: event_request_scene_palette_and_brightness_transition(c); return;
        case 0x007C: open_event_buy_ring_with_literal_script_operand(c); return;
        case 0x007E: event_restore_selected_actor_health_mana_or_combat_state(c); return;
        case 0x0080: TAIL_CALL_DYN(c, 0xC1EE8C, SOM_RTS); /* event_assign_flag_byte_preserving_previous_upper_nibble */
        case 0x0082: event_set_actor_motion_and_resume_dispatch(c); return;
        case 0x0084: event_set_actor_cardinal_velocity_and_presentation(c); return;
        case 0x0086: event_store_two_byte_scene_parameter(c); return;
        case 0x0088: event_set_actor_motion_and_pause_its_execution(c); return;
        case 0x008A: TAIL_CALL_DYN(c, 0xC1EFDF, SOM_RTS); /* advance_event_cursor_wait_for_nmi_and_publish_party_hud */
        case 0x008C: TAIL_CALL_DYN(c, 0xC1EFE7, SOM_RTS); /* consume_event_gold_word_and_add_or_spend_with_native_cap */
        case 0x008E: TAIL_CALL_DYN(c, 0xC1EFE7, SOM_RTS); /* consume_event_gold_word_and_add_or_spend_with_native_cap */
        case 0x0090: event_branch_on_current_actor_slot(c); return;
        case 0x0092: TAIL_CALL_DYN(c, 0xC1F010, SOM_RTS); /* event_assign_selected_actor_secondary_byte_field */
        case 0x0094: TAIL_CALL_DYN(c, 0xC1F04B, SOM_RTS); /* event_assign_selected_actor_primary_word_field */
        case 0x0096: event_branch_on_controller_binding_mask(c); return;
        case 0x0098: event_branch_on_leading_assigned_controller_count(c); return;
        case 0x009A: TAIL_CALL_DYN(c, 0xC1F0E9, SOM_RTS); /* event_reserved_3d_stall */
        case 0x009C: TAIL_CALL_DYN(c, 0xC1F0EA, SOM_RTS); /* event_reserved_3e_stall */
        case 0x009E: TAIL_CALL_DYN(c, 0xC1F0EB, SOM_RTS); /* event_reserved_3f_stall */
        case 0x00A0: TAIL_CALL_DYN(c, 0xC1F0EC, SOM_RTS); /* event_read_audio_request_and_dispatch_native_sender */
        case 0x00A2: TAIL_CALL_DYN(c, 0xC1F10E, SOM_RTS); /* event_decode_individual_map_piece_and_redraw */
        case 0x00A4: event_branch_on_inclusive_flag_nibble_range(c); return;
        case 0x00A6: event_update_or_test_flag_nibble_then_resume_dispatch(c); return;
        case 0x00A8: TAIL_CALL_DYN(c, 0xC1F1CB, SOM_RTS); /* event_reserved_44_stall */
        case 0x00AA: TAIL_CALL_DYN(c, 0xC1F1CC, SOM_RTS); /* event_reserved_45_stall */
        case 0x00AC: TAIL_CALL_DYN(c, 0xC1F1CD, SOM_RTS); /* event_reserved_46_stall */
        case 0x00AE: TAIL_CALL_DYN(c, 0xC1F1CE, SOM_RTS); /* event_reserved_47_stall */
        case 0x00B0: event_combine_indexed_flag_nibble_and_execute_operation(c); return;
        case 0x00B2: event_branch_on_selected_actor_byte_field(c); return;
        case 0x00B4: event_branch_on_selected_actor_byte_field(c); return;
        case 0x00B6: event_branch_on_selected_actor_byte_field(c); return;
        case 0x00B8: event_branch_on_selected_actor_byte_field(c); return;
        case 0x00BA: event_branch_on_selected_actor_byte_field(c); return;
        case 0x00BC: event_branch_on_selected_actor_byte_field(c); return;
        case 0x00BE: TAIL_CALL_DYN(c, 0xC1F279, SOM_RTS); /* event_reserved_4f_stall */
        case 0x00C0: TAIL_CALL_DYN(c, 0xC1F27A, SOM_RTS); /* event_enqueue_text_and_yield_to_text_state */
        default: { const uint16_t dyn_target = BUS16(c, 0xC10000 + (uint16_t)(0xE902 + ((uint8_t)((a >> 8 << 8) | (uint8_t)(value5 << 1))))); c->open_bus = (uint8_t)(dyn_target >> 8); TAIL_CALL_DYN(c, 0xC10000 | dyn_target, SOM_RTS); }
        }
    }
    SET_A8(r, (value & 1) | value2 | value3);
    r->x = (uint8_t)x;
    r->y = (uint8_t)y;
    r->z = ((value & 1) | value2 | value3) == 0;
    r->n = ((value & 1) | value2 | value3) & 0x80;
    r->mf = 1;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1E8D3, SOM_RTS, "hand", dispatch_native_event_opcode_or_wait_state, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 145, -1, -1, 2749, 693)

/* C1E9EC event_return_and_resume_native_dispatch   [class A, 15 bytes, 7 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=any DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_return_and_resume_native_dispatch(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    RAM8(0x00D1) = RAM8(0x00D6);
    RAM8(0x00D2) = RAM8(0x00D7);
    uint8_t value3 = RAM8(0x00D8);
    RAM8(0x00D3) = value3;
    r->a = (a_hi << 8) | value3;
    r->z = value3 == 0;
    r->n = value3 & 0x80;
    TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
}

/* C1EA4E event_release_party_freeze   [class A, 11 bytes, 6 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=any DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_release_party_freeze(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0x00F1);
    RAM8(0x00F1) = value & 0x7F;
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    r->a = a_hi << 8 | (value & 0x7F);
    r->z = RAM16(0x00D1) == 0;
    r->n = RAM16(0x00D1) & 0x8000;
    r->mf = 0;
    RETURN_RTS(c);
}

/* C1EAAD event_clear_remembered_map_destination   [class A, 12 bytes, 6 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=any X=any DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_clear_remembered_map_destination(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t db = r->db;
    BUS16_SET(c, (db << 0x10) + 0x0108, 0);
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    r->z = RAM16(0x00D1) == 0;
    r->n = RAM16(0x00D1) & 0x8000;
    r->mf = 0;
    RETURN_RTS(c);
}

/* C1EAB4 event_transition_to_remembered_map   [class A, 13 bytes, 5 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=any X=any DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_transition_to_remembered_map(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t db = r->db;
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    uint16_t value = BUS16_RDP(c, (db << 0x10) + 0x0108);
    r->a = value | 0x0800;
    r->z = (value | 0x0800) == 0;
    r->n = (value | 0x0800) & 0x8000;
    r->mf = 0;
    TAIL_CALL(c, 0xC1E77B, SOM_RTS); /* accept_numeric_event_request */
}

/* C1EAD6 open_event_weapon_upgrade_ring_and_restore_native_sprite_context   [class A, 30 bytes, 11 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=any X=any DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void open_event_weapon_upgrade_ring_and_restore_native_sprite_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    r->x = RAM16(0x003A);
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xEADE, 0xC1F3F3); GUARD_JSR(c, sp_call, 0xEADE); } /* stage_event_menu_sprites_and_preserve_actor_context */
    uint16_t dp_ret = r->dp;
    uint16_t value2 = RAM16(0x0099 + dp_ret);
    r->a = value2 & 0xFF;
    r->z = (value2 & 0xFF) == 0;
    r->n = value2 & 0xFF & 0x8000;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xEAE7, 0xC0004E); GUARD_JSL(c, sp_call, 0xEAE7); } /* public_weapon_upgrade_ring_menu_alias */
    { const uint16_t sp_call = r->sp; JSL(c, 0xF3ED, 0xC0E351); GUARD_JSL(c, sp_call, 0xF3ED); } /* initialize_sprite_workspace_long */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF3F1, 0xC2AB30); GUARD_JSL(c, sp_call, 0xF3F1); } /* restore_event_sprite_palette_from_shadow */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}

/* C1EAF0 event_jump_to_numeric_event_and_resume_dispatch   [class A, 23 bytes, 11 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=8 bit DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_jump_to_numeric_event_and_resume_dispatch(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0x00D0) = 0;
    uint16_t value = RAM16(0x0004);
    r->a = (((uint8_t)value << 8) | (value >> 8)) & 0x07FF;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xEAFC, 0xC1E77B); GUARD_JSR(c, sp_call, 0xEAFC); } /* accept_numeric_event_request */
    uint16_t a_all = r->a;
    uint8_t value2 = RAM8(0x00D0);
    if (value2 != 0) {
        r->a = (a_all >> 8 << 8) | value2;
        r->z = value2 == 0;
        r->n = value2 & 0x80;
        r->mf = 1;
        TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
    }
    SET_A8(r, value2);
    r->z = value2 == 0;
    r->n = value2 & 0x80;
    r->mf = 1;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}

/* C1EB07 event_transition_to_ten_bit_map_operand   [class A, 18 bytes, 8 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=any X=any DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_transition_to_ten_bit_map_operand(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    uint16_t value = RAM16(0x0004);
    r->a = ((((uint8_t)value << 8) | (value >> 8)) & 0x03FF) | 0x0800;
    r->z = (((((uint8_t)value << 8) | (value >> 8)) & 0x03FF) | 0x0800) == 0;
    r->n = (((((uint8_t)value << 8) | (value >> 8)) & 0x03FF) | 0x0800) & 0x8000;
    r->mf = 0;
    TAIL_CALL(c, 0xC1E77B, SOM_RTS); /* accept_numeric_event_request */
}

/* C1EB19 event_request_scroll_operand_then_end_script   [class A, 22 bytes, 9 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=any X=8 bit DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_request_scroll_operand_then_end_script(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    r->a = (RAM16(0x0005) & 0xFF) | 0x0C00;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xEB29, 0xC1E77B); GUARD_JSR(c, sp_call, 0xEB29); } /* accept_numeric_event_request */
    r->mf = 1;
    TAIL_CALL(c, 0xC1E9C4, SOM_RTS); /* event_end_and_release_party_controls */
}

/* C1EB2F event_request_fade_operand_and_update_transition_flag   [class A, 33 bytes, 15 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=any X=any DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_request_fade_operand_and_update_transition_flag(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    uint8_t value = RAM8(0x00E3);
    uint8_t value2 = RAM8(0x0005);
    uint8_t a1;
    if (!(value2 & 0x40)) {
        a1 = value & 0xF0;
    } else {
        a1 = (value & 0xF0) | 1;
    }
    RAM8(0x00E3) = a1;
    uint16_t value3 = RAM16(0x0005);
    r->a = (value3 & 0x3F) | 0x0D00;
    r->z = ((value3 & 0x3F) | 0x0D00) == 0;
    r->n = ((value3 & 0x3F) | 0x0D00) & 0x8000;
    r->v = value2 & 0x40;
    r->mf = 0;
    TAIL_CALL(c, 0xC1E77B, SOM_RTS); /* accept_numeric_event_request */
}

/* C1EB50 event_insert_inventory_operand_then_continue_script   [class A, 19 bytes, 9 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=any DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_insert_inventory_operand_then_continue_script(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 2));
    uint16_t value2 = RAM16(0x00D4);
    uint8_t value3 = RAM8(0x0005);
    r->a = (a_hi << 8) | value3;
    r->x = value2;
    r->z = value3 == 0;
    r->n = value3 & 0x80;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xEB5F, 0xC00051); GUARD_JSL(c, sp_call, 0xEB5F); } /* jump_public_event_inventory_command */
    TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
}

/* C1EB63 advance_party_command_cursor   [class A, 143 bytes, 63 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=any X=8 bit DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void advance_party_command_cursor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint8_t db = r->db;
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    uint8_t value = RAM8(0x0005);
    if (value >= 3) {
        if (value >= 5) {
            if (value != 5) {
                if (value != 6) {
                    if (value != 7) {
                        if (value >= 0x0C) {
                            if (value != 0x0C) {
                                if (value != 0x10) {
                                    r->a = (a >> 8 << 8) | value;
                                    r->c = value >= 0x10;
                                    r->z = value == 0x10;
                                    r->n = (uint8_t)(value - 0x10) & 0x80;
                                    r->mf = 1;
                                    TAIL_CALL(c, 0xC00075, SOM_RTS); /* jump_public_warm_restart */
                                }
                                uint16_t value2 = RAM16(0x00D4);
                                r->c = value >= 0x10;
                                r->z = value2 == 0;
                                r->n = value2 & 0x8000;
                                r->mf = 0;
                                r->xf = 0;
                                { const uint16_t sp_call = r->sp; JSL(c, 0xEBEC, 0xC00072); GUARD_JSL(c, sp_call, 0xEBEC); } /* jump_public_controlled_party_world_snapshot */
                                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                                RETURN_RTS(c);
                            }
                            uint16_t value3 = RAM16(0x00D4);
                            uint16_t value4 = RAM16(0x003A);
                            r->a = value3;
                            r->x = value4;
                            r->c = value >= 0x0C;
                            r->z = value4 == 0;
                            r->n = value4 & 0x8000;
                            r->mf = 0;
                            r->xf = 0;
                            { const uint16_t sp_call = r->sp; JSL(c, 0xEBDF, 0xC00066); GUARD_JSL(c, sp_call, 0xEBDF); } /* jump_public_chest_reward_command */
                            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                            RETURN_RTS(c);
                        }
                        r->c = value >= 0x0C;
                        r->z = value == 0x0C;
                        r->n = (uint8_t)(value - 0x0C) & 0x80;
                        r->mf = 1;
                        { const uint16_t sp_call = r->sp; JSL(c, 0xEBD2, 0xC0005A); GUARD_JSL(c, sp_call, 0xEBD2); } /* jump_public_party_weapon_inventory_refresh */
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    }
                    r->a = (a >> 8 << 8) | value;
                    r->c = value >= 7;
                    r->z = value == 7;
                    r->n = (uint8_t)(value - 7) & 0x80;
                    r->mf = 1;
                    TAIL_CALL(c, 0xC08004, SOM_RTS); /* enter_native_reset_mode */
                }
                uint16_t value5 = BUS16_RDP(c, (db << 0x10) + 0x010E);
                r->a = value5;
                r->c = value >= 6;
                r->z = value5 == 0;
                r->n = value5 & 0x8000;
                r->mf = 0;
                { const uint16_t sp_call = r->sp; JSL(c, 0xEBBE, 0xC0000C); GUARD_JSL(c, sp_call, 0xEBBE); } /* public_saved_game_menu_request_alias */
                { const uint16_t sp_call = r->sp; JSR(c, 0xEBC1, 0xC1FF3A); GUARD_JSR(c, sp_call, 0xEBC1); } /* restore_event_screen_and_reenable_frame_interrupts */
                r->mf = 1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            SET_A8(r, value);
            r->c = value >= 5;
            r->z = value == 5;
            r->n = (uint8_t)(value - 5) & 0x80;
            r->mf = 1;
            RETURN_RTS(c);
        }
        uint8_t a1;
        if (value != 3) {
            RAM16_SET(0x00FA, 0x0D80);
            RAM16_SET(0x00FC, 0x0D80);
            a1 = 0x84;
        } else {
            RAM16_SET(0x00FA, 0x0D80);
            RAM16_SET(0x00FC, 0x0D80);
            a1 = 2;
        }
        RAM8(0x00E3) = a1;
        r->a = (0x0D << 8) | a1;
        r->c = value >= 3;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0xEBAB, 0xC0BC01); GUARD_JSL(c, sp_call, 0xEBAB); } /* request_destination_fade */
        r->mf = 1;
        r->xf = 0;
        TAIL_CALL(c, 0xC1E9C4, SOM_RTS); /* event_end_and_release_party_controls */
    }
    r->a = (a >> 8 << 8) | 0;
    r->x = (uint8_t)((a >> 8 << 8) | value);
    r->c = value >= 3;
    r->z = 1;
    r->n = 0;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0xEB77, 0xC0000F); GUARD_JSL(c, sp_call, 0xEB77); } /* jump_public_native_name_menu */
    { const uint16_t sp_call = r->sp; JSR(c, 0xEB7A, 0xC1FF3A); GUARD_JSR(c, sp_call, 0xEB7A); } /* restore_event_screen_and_reenable_frame_interrupts */
    r->mf = 1;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}

/* C1EBF2 event_call_numeric_event_with_single_saved_return   [class A, 40 bytes, 20 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=8 bit DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_call_numeric_event_with_single_saved_return(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0x00D8) = RAM8(0x00D3);
    RAM8(0x00D0) = 0xFF;
    uint16_t value2 = RAM16(0x00D1);
    RAM16_SET(0x00D6, (uint16_t)(value2 + 2));
    r->a = ((RAM8(0x0004) & 7) << 8) | RAM8(0x0005);
    r->v = ((value2 ^ (uint16_t)(value2 + 2)) & ((uint16_t)(value2 + 2) ^ 2) & 0x8000) != 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xEC0F, 0xC1E77B); GUARD_JSR(c, sp_call, 0xEC0F); } /* accept_numeric_event_request */
    uint16_t a_all = r->a;
    uint8_t value5 = RAM8(0x00D0);
    if (value5 != 0) {
        r->a = (a_all >> 8 << 8) | value5;
        r->z = value5 == 0;
        r->n = value5 & 0x80;
        r->mf = 1;
        TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
    }
    SET_A8(r, value5);
    r->z = value5 == 0;
    r->n = value5 & 0x80;
    r->mf = 1;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}

/* C1EC46 event_increment_flag_nibble_or_restore_party_scene   [class A, 76 bytes, 34 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=8 bit DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_increment_flag_nibble_or_restore_party_scene(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint8_t db = r->db;
    uint8_t value = RAM8(0x0005);
    if (value == 0) {
        uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0xCF00 + value);
        if (value2 != 0) {
            uint8_t a1;
            if (((uint8_t)(value2 + 1) & 0x0F) != 0) {
                a1 = (uint8_t)(value2 + 1) & 0x0F;
            } else {
                a1 = 0x0F;
            }
            RAM8(0x0000) = a1;
            uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0xCF00 + value);
            uint8_t value4 = RAM8(0x0000);
            BUS8_SET(c, (db << 0x10) + 0xCF00 + value, (value3 & 0xF0) | value4);
            RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
            RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
            r->a = (a_hi << 8) | ((value3 & 0xF0) | value4);
            r->x = value;
            r->z = RAM16(0x00D1) == 0;
            r->n = RAM16(0x00D1) & 0x8000;
            r->mf = 0;
            TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
        }
        uint8_t value5 = RAM8(0x00ED);
        if (value5 & 0x80) {
            uint8_t value6 = BUS8_RDP(c, (db << 0x10) + 0xCF00 + value);
            BUS8_SET(c, (db << 0x10) + 0xCF00 + value, (uint8_t)(value6 + 1));
            RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
            RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
            r->a = (a_hi << 8) | value5;
            r->x = value;
            r->mf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0xEC7B, 0xC2C976); GUARD_JSL(c, sp_call, 0xEC7B); } /* prepare_and_animate_event_radial_transition */
            r->mf = 1;
            r->xf = 0;
            TAIL_CALL(c, 0xC1E0DB, SOM_RTS); /* restore_party_hud_across_two_native_frames */
        }
        RAM8(0x00ED) = value5 ^ 0x80;
        RAM8(0x00CC) = 0;
        RAM8(0x00CD) = 0;
        RAM8(0x00CE) = 0;
        RAM8(0x0000) = 0;
        uint8_t value8 = BUS8_RDP(c, (db << 0x10) + 0xCF00 + value);
        uint8_t value9 = RAM8(0x0000);
        BUS8_SET(c, (db << 0x10) + 0xCF00 + value, (value8 & 0xF0) | value9);
        RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
        RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
        r->a = (a_hi << 8) | ((value8 & 0xF0) | value9);
        r->x = value;
        r->z = RAM16(0x00D1) == 0;
        r->n = RAM16(0x00D1) & 0x8000;
        r->mf = 0;
        TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
    }
    uint8_t value10 = BUS8_RDP(c, (db << 0x10) + 0xCF00 + value);
    uint8_t a2;
    if (((uint8_t)(value10 + 1) & 0x0F) != 0) {
        a2 = (uint8_t)(value10 + 1) & 0x0F;
    } else {
        a2 = 0x0F;
    }
    RAM8(0x0000) = a2;
    uint8_t value11 = BUS8_RDP(c, (db << 0x10) + 0xCF00 + value);
    uint8_t value12 = RAM8(0x0000);
    BUS8_SET(c, (db << 0x10) + 0xCF00 + value, (value11 & 0xF0) | value12);
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    r->a = (a_hi << 8) | ((value11 & 0xF0) | value12);
    r->x = value;
    r->z = RAM16(0x00D1) == 0;
    r->n = RAM16(0x00D1) & 0x8000;
    r->mf = 0;
    TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
}

/* C1EC7F event_decrement_flag_nibble_and_resume_dispatch   [class A, 33 bytes, 15 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=8 bit DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_decrement_flag_nibble_and_resume_dispatch(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint8_t db = r->db;
    uint8_t value = RAM8(0x0005);
    uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0xCF00 + value);
    uint8_t a1;
    if (!((uint8_t)((value2 & 0x0F) - 1) & 0x80)) {
        a1 = (uint8_t)((value2 & 0x0F) - 1);
    } else {
        a1 = 0;
    }
    RAM8(0x0000) = a1;
    uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0xCF00 + value);
    uint8_t value4 = RAM8(0x0000);
    BUS8_SET(c, (db << 0x10) + 0xCF00 + value, (value3 & 0xF0) | value4);
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    r->a = (a_hi << 8) | ((value3 & 0xF0) | value4);
    r->x = value;
    r->z = RAM16(0x00D1) == 0;
    r->n = RAM16(0x00D1) & 0x8000;
    r->mf = 0;
    TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
}

/* C1ED35 event_request_scene_palette_and_brightness_transition   [class A, 157 bytes, 76 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=8 bit DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_request_scene_palette_and_brightness_transition(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t db = r->db;
    uint8_t value = RAM8(0x0005);
    if (!(value & 0x80)) {
        if (value != 0) {
            if (value != 1) {
                if (value != 2) {
                    if (value != 3) {
                        if (value != 4) {
                            if (value != 5) {
                                if (value != 6) {
                                    if (value != 7) {
                                        if (value != 8) {
                                            RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
                                            RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
                                            r->a = (a_hi << 8) | value;
                                            r->c = value >= 8;
                                            r->z = RAM16(0x00D1) == 0;
                                            r->n = RAM16(0x00D1) & 0x8000;
                                            r->mf = 0;
                                            TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
                                        }
                                        RAM8(0x00E2) |= 8;
                                        RAM8(0x00D0) = 0x86;
                                        RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
                                        RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
                                        r->a = (a_hi << 8) | 0x86;
                                        r->c = value >= 8;
                                        r->z = RAM16(0x00D1) == 0;
                                        r->n = RAM16(0x00D1) & 0x8000;
                                        r->mf = 0;
                                        RETURN_RTS(c);
                                    }
                                    uint8_t value3 = RAM8(0x002A);
                                    if (value3 == 0) {
                                        RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
                                        RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
                                        r->a = (a_hi << 8) | value3;
                                        r->c = value >= 7;
                                        r->z = RAM16(0x00D1) == 0;
                                        r->n = RAM16(0x00D1) & 0x8000;
                                        r->mf = 0;
                                        TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
                                    }
                                    RAM8(0x002A) = value3 | 0x80;
                                    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
                                    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
                                    r->a = (a_hi << 8) | (value3 | 0x80);
                                    r->c = value >= 7;
                                    r->z = RAM16(0x00D1) == 0;
                                    r->n = RAM16(0x00D1) & 0x8000;
                                    r->mf = 0;
                                    RETURN_RTS(c);
                                }
                                RAM8(0x0000 + sp0) = 0x60;
                                r->sp -= 1;
                                { const uint16_t sp_call = r->sp; JSL(c, 0xED8F, 0xC2C806); GUARD_JSL(c, sp_call, 0xED8F); } /* snapshot_palette_for_event_color_transition */
                                r->sp += 1;
                                RAM8(0x002A) = RAM8(0x0000 + sp0);
                                uint16_t value5 = BUS16_RDL(c, (RAM8(0x00D3) << 0x10) + RAM16(0x00D1) + 2, RAM8(0x00D3));
                                BUS16_SET(c, (db << 0x10) + 0x010C, value5);
                                BUS16_SET(c, (db << 0x10) + 0x010A, 0);
                                uint16_t value6 = RAM16(0x00D1);
                                RAM16_SET(0x00D1, (uint16_t)(value6 + 4));
                                r->a = (uint16_t)(value6 + 4);
                                r->y = 2;
                                r->c = value6 + 4 > 0xFFFF;
                                r->z = (uint16_t)(value6 + 4) == 0;
                                r->n = (uint16_t)(value6 + 4) & 0x8000;
                                r->v = ((value6 ^ (uint16_t)(value6 + 4)) & ((uint16_t)(value6 + 4) ^ 4) & 0x8000) != 0;
                                r->mf = 0;
                                r->xf = 1;
                                RETURN_RTS(c);
                            }
                            RAM8(0x0000 + sp0) = 0x20;
                            r->sp -= 1;
                            { const uint16_t sp_call = r->sp; JSL(c, 0xED8F, 0xC2C806); GUARD_JSL(c, sp_call, 0xED8F); } /* snapshot_palette_for_event_color_transition */
                            r->sp += 1;
                            RAM8(0x002A) = RAM8(0x0000 + sp0);
                            uint16_t value8 = BUS16_RDL(c, (RAM8(0x00D3) << 0x10) + RAM16(0x00D1) + 2, RAM8(0x00D3));
                            BUS16_SET(c, (db << 0x10) + 0x010C, value8);
                            BUS16_SET(c, (db << 0x10) + 0x010A, 0);
                            uint16_t value9 = RAM16(0x00D1);
                            RAM16_SET(0x00D1, (uint16_t)(value9 + 4));
                            r->a = (uint16_t)(value9 + 4);
                            r->y = 2;
                            r->c = value9 + 4 > 0xFFFF;
                            r->z = (uint16_t)(value9 + 4) == 0;
                            r->n = (uint16_t)(value9 + 4) & 0x8000;
                            r->v = ((value9 ^ (uint16_t)(value9 + 4)) & ((uint16_t)(value9 + 4) ^ 4) & 0x8000) != 0;
                            r->mf = 0;
                            r->xf = 1;
                            RETURN_RTS(c);
                        }
                        RAM8(0x0049) = 0;
                        RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
                        RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
                        r->a = (a_hi << 8) | value;
                        r->c = value >= 4;
                        r->z = RAM16(0x00D1) == 0;
                        r->n = RAM16(0x00D1) & 0x8000;
                        r->mf = 0;
                        TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
                    }
                    RAM8(0x0049) = 0x60;
                    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
                    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
                    r->a = (a_hi << 8) | 0x60;
                    r->c = value >= 3;
                    r->z = RAM16(0x00D1) == 0;
                    r->n = RAM16(0x00D1) & 0x8000;
                    r->mf = 0;
                    TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
                }
                RAM8(0x0049) = 0xE0;
                RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
                RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
                r->a = (a_hi << 8) | 0xE0;
                r->c = value >= 2;
                r->z = RAM16(0x00D1) == 0;
                r->n = RAM16(0x00D1) & 0x8000;
                r->mf = 0;
                TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
            }
            BUS8_SET(c, (db << 0x10) + 0x1057, 1);
            RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
            RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
            r->a = (a_hi << 8) | 1;
            r->c = value >= 1;
            r->z = RAM16(0x00D1) == 0;
            r->n = RAM16(0x00D1) & 0x8000;
            r->mf = 0;
            TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
        }
        BUS8_SET(c, (db << 0x10) + 0x1057, 0);
        BUS8_SET(c, (db << 0x10) + 0x1058, RAM8(0x00E6));
        RAM8(0x00E2) |= 4;
        RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
        RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
        r->a = (a_hi << 8) | 4;
        r->z = RAM16(0x00D1) == 0;
        r->n = RAM16(0x00D1) & 0x8000;
        r->mf = 0;
        TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
    }
    if (value >= 0x90) {
        RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
        RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
        r->a = (a_hi << 8) | value;
        r->c = value >= 0x90;
        r->z = RAM16(0x00D1) == 0;
        r->n = RAM16(0x00D1) & 0x8000;
        r->mf = 0;
        TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
    }
    RAM8(0x0000 + sp0) = value & 0x0F;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0xED8F, 0xC2C806); GUARD_JSL(c, sp_call, 0xED8F); } /* snapshot_palette_for_event_color_transition */
    r->sp += 1;
    RAM8(0x002A) = RAM8(0x0000 + sp0);
    uint16_t value13 = BUS16_RDL(c, (RAM8(0x00D3) << 0x10) + RAM16(0x00D1) + 2, RAM8(0x00D3));
    BUS16_SET(c, (db << 0x10) + 0x010C, value13);
    BUS16_SET(c, (db << 0x10) + 0x010A, 0);
    uint16_t value14 = RAM16(0x00D1);
    RAM16_SET(0x00D1, (uint16_t)(value14 + 4));
    r->a = (uint16_t)(value14 + 4);
    r->y = 2;
    r->c = value14 + 4 > 0xFFFF;
    r->z = (uint16_t)(value14 + 4) == 0;
    r->n = (uint16_t)(value14 + 4) & 0x8000;
    r->v = ((value14 ^ (uint16_t)(value14 + 4)) & ((uint16_t)(value14 + 4) ^ 4) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 1;
    RETURN_RTS(c);
}

/* C1EDD2 open_event_buy_ring_with_literal_script_operand   [class A, 38 bytes, 15 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=any X=any DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void open_event_buy_ring_with_literal_script_operand(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    uint16_t value = RAM16(0x0005);
    uint16_t value2 = RAM16(0x003A);
    r->a = value & 0xFF;
    r->x = value2;
    r->y = value & 0xFF;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xEDE2, 0xC1F3F3); GUARD_JSR(c, sp_call, 0xEDE2); } /* stage_event_menu_sprites_and_preserve_actor_context */
    uint16_t dp_ret = r->dp;
    uint16_t value3 = RAM16(0x0099 + dp_ret);
    r->a = value3 & 0xFF;
    r->z = (value3 & 0xFF) == 0;
    r->n = value3 & 0xFF & 0x8000;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xEDEB, 0xC00048); GUARD_JSL(c, sp_call, 0xEDEB); } /* public_buy_ring_menu_alias */
    { const uint16_t sp_call = r->sp; JSL(c, 0xF3ED, 0xC0E351); GUARD_JSL(c, sp_call, 0xF3ED); } /* initialize_sprite_workspace_long */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF3F1, 0xC2AB30); GUARD_JSL(c, sp_call, 0xF3F1); } /* restore_event_sprite_palette_from_shadow */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}

/* C1EDEF event_restore_selected_actor_health_mana_or_combat_state   [class A, 148 bytes, 68 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=any DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_restore_selected_actor_health_mana_or_combat_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint8_t db = r->db;
    uint16_t value = RAM16(0x00D1);
    RAM16_SET(0x00D1, (uint16_t)(value + 2));
    uint16_t value2 = RAM16(0x00D4);
    uint8_t value3 = RAM8(0x0005);
    if (value3 & 0x80) {
        if ((value3 & 0x7F) == 0) {
            uint8_t value4 = BUS8_RDP(c, (db << 0x10) + 0xE187 + value2);
            BUS8_SET(c, (db << 0x10) + 0xE186 + value2, value4);
        } else {
            if ((value3 & 0x7F) >= 4) {
                uint8_t value5 = BUS8_RDP(c, (db << 0x10) + 0xE187);
                BUS8_SET(c, (db << 0x10) + 0xE186, value5);
                uint8_t value6 = BUS8_RDP(c, (db << 0x10) + 0xE387);
                BUS8_SET(c, (db << 0x10) + 0xE386, value6);
                uint8_t value7 = BUS8_RDP(c, (db << 0x10) + 0xE587);
                BUS8_SET(c, (db << 0x10) + 0xE586, value7);
            } else {
                uint8_t value8 = BUS8_RDP(c, (db << 0x10) + 0xE187 + (((uint8_t)((uint8_t)((value3 & 0x7F) - 1) << 1) << 8) | 0));
                BUS8_SET(c, (db << 0x10) + 0xE186 + (((uint8_t)((uint8_t)((value3 & 0x7F) - 1) << 1) << 8) | 0), value8);
            }
        }
        r->y = (uint16_t)(value + 2);
        r->xf = 0;
        TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
    }
    if (value3 >= 0x40) {
        if ((value3 & 0x3F) == 0) {
            r->a = a_hi << 8 | (value3 & 0x3F);
            r->x = value2;
            r->y = (uint16_t)(value + 2);
            r->c = value3 >= 0x40;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xEE6A, 0xC1EE83); GUARD_JSR(c, sp_call, 0xEE6A); } /* event_initialize_actor_combat_state */
            TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
        }
        if ((value3 & 0x3F) >= 4) {
            r->a = a_hi << 8 | (value3 & 0x3F);
            r->x = 0;
            r->y = (uint16_t)(value + 2);
            r->c = (value3 & 0x3F) >= 4;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xEE73, 0xC1EE83); GUARD_JSR(c, sp_call, 0xEE73); } /* event_initialize_actor_combat_state */
            r->x = 0x0200;
            { const uint16_t sp_call = r->sp; JSR(c, 0xEE79, 0xC1EE83); GUARD_JSR(c, sp_call, 0xEE79); } /* event_initialize_actor_combat_state */
            r->x = 0x0400;
            { const uint16_t sp_call = r->sp; JSR(c, 0xEE7F, 0xC1EE83); GUARD_JSR(c, sp_call, 0xEE7F); } /* event_initialize_actor_combat_state */
            TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
        }
        r->a = ((uint8_t)((uint8_t)((value3 & 0x3F) - 1) << 1) << 8) | 0;
        r->x = ((uint8_t)((uint8_t)((value3 & 0x3F) - 1) << 1) << 8) | 0;
        r->y = (uint16_t)(value + 2);
        r->c = (uint8_t)((value3 & 0x3F) - 1) & 0x80;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xEE6A, 0xC1EE83); GUARD_JSR(c, sp_call, 0xEE6A); } /* event_initialize_actor_combat_state */
        TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
    }
    if ((value3 & 0x3F) == 0) {
        uint16_t value9 = BUS16_RDP(c, (db << 0x10) + 0xE184 + value2);
        BUS16_SET(c, (db << 0x10) + 0xE182 + value2, value9);
    } else {
        if ((value3 & 0x3F) >= 4) {
            uint16_t value10 = BUS16_RDP(c, (db << 0x10) + 0xE184);
            BUS16_SET(c, (db << 0x10) + 0xE182, value10);
            uint16_t value11 = BUS16_RDP(c, (db << 0x10) + 0xE384);
            BUS16_SET(c, (db << 0x10) + 0xE382, value11);
            uint16_t value12 = BUS16_RDP(c, (db << 0x10) + 0xE584);
            BUS16_SET(c, (db << 0x10) + 0xE582, value12);
        } else {
            uint16_t value13 = BUS16_RDP(c, (db << 0x10) + 0xE184 + (((uint8_t)((uint8_t)((value3 & 0x3F) - 1) << 1) << 8) | 0));
            BUS16_SET(c, (db << 0x10) + 0xE182 + (((uint8_t)((uint8_t)((value3 & 0x3F) - 1) << 1) << 8) | 0), value13);
        }
    }
    r->y = (uint16_t)(value + 2);
    r->mf = 0;
    r->xf = 0;
    TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
}

/* C1EEA9 event_set_actor_motion_and_resume_dispatch   [class A, 6 bytes, 2 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=8 bit DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_set_actor_motion_and_resume_dispatch(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0xEEAB, 0xC1EEAF); GUARD_JSR(c, sp_call, 0xEEAB); } /* set_event_actor_motion_after_charge_and_palette_cleanup */
    r->mf = 1;
    TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
}

/* C1EEEA event_set_actor_cardinal_velocity_and_presentation   [class A, 206 bytes, 93 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=any DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_set_actor_cardinal_velocity_and_presentation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t db = r->db;
    uint8_t value = BUS8_RDL(c, (RAM8(0x00D3) << 0x10) + RAM16(0x00D1) + 2, RAM8(0x00D3));
    RAM8(0x0000) = value;
    uint16_t value2 = RAM16(0x00D1);
    RAM16_SET(0x00D1, (uint16_t)(value2 + 3));
    uint16_t value3 = RAM16(0x00D4);
    uint8_t value4 = RAM8(0x0005);
    uint8_t a_hi2;
    uint16_t x2;
    if (value4 == 0) {
        a_hi2 = a_hi;
        x2 = value3;
    } else {
        uint8_t a_hi1;
        uint16_t x1;
        if (!(value4 & 0x80)) {
            a_hi1 = (uint8_t)((uint8_t)(value4 - 1) << 1);
            x1 = ((uint8_t)((uint8_t)(value4 - 1) << 1) << 8) | 0;
        } else {
            uint16_t value5 = RAM16(0x003A);
            a_hi1 = a_hi;
            x1 = value5;
        }
        a_hi2 = a_hi1;
        x2 = x1;
    }
    BUS8_SET(c, (db << 0x10) + 0xE01C + x2, 0);
    BUS8_SET(c, (db << 0x10) + 0xE013 + x2, 0);
    RAM8(0x0001) = 0xFF;
    uint8_t value6 = RAM8(0x0000);
    uint8_t a1;
    if ((value6 & 0x3F) != 0) {
        a1 = value6 & 0x3F;
    } else {
        RAM8(0x0001) = 0;
        a1 = 1;
    }
    BUS8_SET(c, (db << 0x10) + 0xE00A + x2, a1);
    BUS8_SET(c, (db << 0x10) + 0xE067 + x2, 0);
    BUS8_SET(c, (db << 0x10) + 0xE042 + x2, 1);
    uint8_t value7 = RAM8(0x0000);
    if ((value7 & 0xC0) == 0) {
        BUS8_SET(c, (db << 0x10) + 0xE006 + x2, 0);
        BUS8_SET(c, (db << 0x10) + 0xE007 + x2, RAM8(0x0001) & 0x82);
        BUS8_SET(c, (db << 0x10) + 0xE010 + x2, 0);
        if (x2 >= 0x0600) {
            BUS8_SET(c, (db << 0x10) + 0xE030 + x2, 0xFF);
            uint8_t value9 = BUS8_RDP(c, (db << 0x10) + 0xE071 + x2);
            uint8_t a2;
            if ((value9 & 0x60) == 0) {
                a2 = RAM8(0x0001) & 1;
            } else {
                if ((value9 & 0x40) != 0) {
                    BUS8_SET(c, (db << 0x10) + 0xE010 + x2, 0);
                }
                a2 = 0;
            }
            BUS8_SET(c, (db << 0x10) + 0xE011 + x2, a2);
        }
    } else {
        if ((value7 & 0xC0) == 0x40) {
            BUS8_SET(c, (db << 0x10) + 0xE006 + x2, 0);
            BUS8_SET(c, (db << 0x10) + 0xE007 + x2, RAM8(0x0001) & 2);
            BUS8_SET(c, (db << 0x10) + 0xE010 + x2, 1);
            if (x2 >= 0x0600) {
                BUS8_SET(c, (db << 0x10) + 0xE030 + x2, 0xFF);
                uint8_t value12 = BUS8_RDP(c, (db << 0x10) + 0xE071 + x2);
                uint8_t a3;
                if ((value12 & 0x60) == 0) {
                    a3 = RAM8(0x0001) & 1;
                } else {
                    if ((value12 & 0x40) != 0) {
                        BUS8_SET(c, (db << 0x10) + 0xE010 + x2, 0);
                    }
                    a3 = 0;
                }
                BUS8_SET(c, (db << 0x10) + 0xE011 + x2, a3);
            }
        } else {
            if ((value7 & 0xC0) == 0x80) {
                BUS8_SET(c, (db << 0x10) + 0xE006 + x2, RAM8(0x0001) & 2);
                BUS8_SET(c, (db << 0x10) + 0xE007 + x2, 0);
                BUS8_SET(c, (db << 0x10) + 0xE010 + x2, 2);
                if (x2 >= 0x0600) {
                    BUS8_SET(c, (db << 0x10) + 0xE030 + x2, 0xFF);
                    uint8_t value15 = BUS8_RDP(c, (db << 0x10) + 0xE071 + x2);
                    uint8_t a4;
                    if ((value15 & 0x60) == 0) {
                        a4 = RAM8(0x0001) & 1;
                    } else {
                        if ((value15 & 0x40) != 0) {
                            BUS8_SET(c, (db << 0x10) + 0xE010 + x2, 0);
                        }
                        a4 = 0;
                    }
                    BUS8_SET(c, (db << 0x10) + 0xE011 + x2, a4);
                }
            } else {
                BUS8_SET(c, (db << 0x10) + 0xE006 + x2, RAM8(0x0001) & 0x82);
                BUS8_SET(c, (db << 0x10) + 0xE007 + x2, 0);
                BUS8_SET(c, (db << 0x10) + 0xE010 + x2, 0x82);
                if (x2 >= 0x0600) {
                    BUS8_SET(c, (db << 0x10) + 0xE030 + x2, 0xFF);
                    uint8_t value18 = BUS8_RDP(c, (db << 0x10) + 0xE071 + x2);
                    uint8_t a5;
                    if ((value18 & 0x60) == 0) {
                        a5 = RAM8(0x0001) & 1;
                    } else {
                        if ((value18 & 0x40) != 0) {
                            BUS8_SET(c, (db << 0x10) + 0xE010 + x2, 0);
                        }
                        a5 = 0;
                    }
                    BUS8_SET(c, (db << 0x10) + 0xE011 + x2, a5);
                }
            }
        }
    }
    r->a = (a_hi2 << 8) | a;
    r->x = x2;
    r->y = (uint16_t)(value2 + 3);
    r->c = x2 >= 0x0600;
    r->xf = 0;
    TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
}

/* C1EFB8 event_store_two_byte_scene_parameter   [class A, 25 bytes, 13 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=any DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_store_two_byte_scene_parameter(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t db = r->db;
    uint8_t value = BUS8_RDL(c, (RAM8(0x00D3) << 0x10) + RAM16(0x00D1) + 2, RAM8(0x00D3));
    uint16_t value2 = RAM16(0x00D1);
    RAM16_SET(0x00D1, (uint16_t)(value2 + 3));
    uint8_t value3 = RAM8(0x0005);
    BUS16_SET(c, (db << 0x10) + 0x0600, (value << 8) | value3);
    r->a = (value << 8) | value3;
    r->y = (uint16_t)(value2 + 3);
    r->z = value3 == 0;
    r->n = value3 & 0x80;
    r->mf = 0;
    r->xf = 0;
    TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
}

/* C1EFD1 event_set_actor_motion_and_pause_its_execution   [class A, 14 bytes, 5 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=8 bit DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_set_actor_motion_and_pause_its_execution(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t db = r->db;
    { const uint16_t sp_call = r->sp; JSR(c, 0xEFD3, 0xC1EEAF); GUARD_JSR(c, sp_call, 0xEFD3); } /* set_event_actor_motion_after_charge_and_palette_cleanup */
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    BUS8_SET(c, (db << 0x10) + 0xE01C + x_ret2, 0x30);
    BUS8_SET(c, (db << 0x10) + 0xE042 + x_ret2, 0);
    r->a = (a_all >> 8 << 8) | 0x30;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
}

/* C1EFFA event_branch_on_current_actor_slot   [class A, 22 bytes, 13 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=any DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_branch_on_current_actor_slot(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    RAM8(0x0000) = a;
    uint16_t value = RAM16(0x00D1);
    uint8_t value2 = RAM8(0x00D5);
    uint8_t value3 = RAM8(0x0005);
    uint16_t y1;
    if (value2 >> 1 == value3) {
        y1 = (uint16_t)(value + 2);
    } else {
        y1 = (uint16_t)(value + 4);
    }
    RAM16_SET(0x00D1, y1);
    r->a = (a_hi << 8) | (value2 >> 1);
    r->y = y1;
    r->c = value2 >> 1 >= value3;
    r->xf = 0;
    TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
}

/* C1F06F event_branch_on_controller_binding_mask   [class A, 87 bytes, 46 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=any DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_branch_on_controller_binding_mask(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t value = RAM8(0x0005);
    uint8_t a1;
    if ((value & 0x0F) != 3) {
        a1 = value & 0x0F;
    } else {
        a1 = 4;
    }
    uint8_t a2 = a1;
    uint8_t a_hi1 = a_hi;
    for (;;) {
        RAM8(0x0002) = a2;
        uint8_t value2 = RAM8(0x0005);
        uint8_t a5;
        if (value2 >> 4 != 0) {
            uint8_t a4;
            if ((uint8_t)((value2 >> 4) - 1) != 0) {
                uint8_t a3;
                if ((uint8_t)((value2 >> 4) - 2) != 0) {
                    a3 = RAM8(0x00DB);
                } else {
                    a3 = RAM8(0x00DA);
                }
                a4 = a3;
            } else {
                a4 = RAM8(0x00D9);
            }
            a5 = a4;
        } else {
            uint8_t value6 = RAM8(0x00D9);
            if (value6 & 0x80) {
                a2 = value6;
                continue;
            }
            uint8_t value7 = RAM8(0x00DA);
            if (value7 & 0x80) {
                a2 = value7;
                continue;
            }
            a5 = RAM8(0x00DB);
        }
        a2 = a5;
        break;
    }
    RAM8(0x0003) = a2;
    uint8_t value9 = RAM8(0x0002);
    uint8_t a10;
    uint8_t a_hi6;
    if (value9 == 0) {
        uint8_t value10 = RAM8(0x0003);
        uint8_t a6;
        uint8_t a_hi2;
        if (value10 == 0) {
            uint16_t value11 = RAM16(0x00D1);
            a6 = (uint8_t)(value11 + 2);
            a_hi2 = (uint16_t)(value11 + 2) >> 8;
        } else {
            uint16_t value12 = RAM16(0x00D1);
            a6 = (uint8_t)(value12 + 4);
            a_hi2 = (uint16_t)(value12 + 4) >> 8;
        }
        a10 = a6;
        a_hi6 = a_hi2;
    } else {
        uint8_t value13 = RAM8(0x0003);
        uint8_t a9;
        uint8_t a_hi5;
        if ((value9 & value13) != 0) {
            uint16_t value14 = RAM16(0x00D1);
            a9 = (uint8_t)(value14 + 2);
            a_hi5 = (uint16_t)(value14 + 2) >> 8;
        } else {
            uint8_t a8;
            uint8_t a_hi4;
            if ((value9 & value13) == 0) {
                uint16_t value15 = RAM16(0x00D1);
                a8 = (uint8_t)(value15 + 4);
                a_hi4 = (uint16_t)(value15 + 4) >> 8;
            } else {
                uint8_t a7;
                uint8_t a_hi3;
                if (value13 == 0) {
                    uint16_t value16 = RAM16(0x00D1);
                    a7 = (uint8_t)(value16 + 2);
                    a_hi3 = (uint16_t)(value16 + 2) >> 8;
                } else {
                    uint16_t value17 = RAM16(0x00D1);
                    a7 = (uint8_t)(value17 + 4);
                    a_hi3 = (uint16_t)(value17 + 4) >> 8;
                }
                a8 = a7;
                a_hi4 = a_hi3;
            }
            a9 = a8;
            a_hi5 = a_hi4;
        }
        a10 = a9;
        a_hi6 = a_hi5;
    }
    RAM16_SET(0x00D1, (a_hi6 << 8) | a10);
    r->a = (a_hi6 << 8) | a10;
    r->x = x;
    r->y = y;
    r->mf = 0;
    TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
}

/* C1F0C6 event_branch_on_leading_assigned_controller_count   [class A, 35 bytes, 21 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=8 bit DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_branch_on_leading_assigned_controller_count(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0x00D9);
    uint8_t x3;
    if (value == 0) {
        x3 = 0;
    } else {
        uint8_t value2 = RAM8(0x00DA);
        uint8_t x2;
        if (value2 == 0) {
            x2 = 1;
        } else {
            uint8_t value3 = RAM8(0x00DB);
            uint8_t x1;
            if (value3 == 0) {
                x1 = 2;
            } else {
                x1 = 3;
            }
            x2 = x1;
        }
        x3 = x2;
    }
    uint16_t value4 = RAM16(0x00D1);
    uint8_t value5 = RAM8(0x0005);
    uint16_t y1;
    if (x3 == value5) {
        y1 = (uint16_t)(value4 + 2);
    } else {
        y1 = (uint16_t)(value4 + 4);
    }
    RAM16_SET(0x00D1, y1);
    r->a = (a_hi << 8) | x3;
    r->x = x3;
    r->y = y1;
    r->c = x3 >= value5;
    r->xf = 0;
    TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
}

/* C1F140 event_branch_on_inclusive_flag_nibble_range   [class A, 47 bytes, 27 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=8 bit DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_branch_on_inclusive_flag_nibble_range(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint8_t db = r->db;
    uint8_t value = BUS8_RDL(c, (RAM8(0x00D3) << 0x10) + RAM16(0x00D1) + 2, RAM8(0x00D3));
    RAM8(0x0001) = value;
    RAM8(0x0000) = value & 0x0F;
    RAM8(0x0001) = RAM8(0x0001) >> 4;
    uint8_t value3 = RAM8(0x0005);
    uint16_t value4 = RAM16(0x00D1);
    uint8_t value5 = BUS8_RDP(c, (db << 0x10) + 0xCF00 + value3);
    uint8_t value6 = RAM8(0x0001);
    uint16_t y3;
    if (value5 < value6) {
        y3 = (uint16_t)(value4 + 5);
    } else {
        uint8_t value7 = RAM8(0x0000);
        uint16_t y2;
        if (value5 == value7) {
            y2 = (uint16_t)(value4 + 3);
        } else {
            uint16_t y1;
            if (value5 < value7) {
                y1 = (uint16_t)(value4 + 3);
            } else {
                y1 = (uint16_t)(value4 + 5);
            }
            y2 = y1;
        }
        y3 = y2;
    }
    RAM16_SET(0x00D1, y3);
    r->a = (a_hi << 8) | value5;
    r->x = value3;
    r->y = y3;
    r->xf = 0;
    TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
}

/* C1F16F event_update_or_test_flag_nibble_then_resume_dispatch   [class A, 84 bytes, 44 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=8 bit DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_update_or_test_flag_nibble_then_resume_dispatch(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t db = r->db;
    uint8_t value = BUS8_RDL(c, (RAM8(0x00D3) << 0x10) + RAM16(0x00D1) + 2, RAM8(0x00D3));
    RAM8(0x0004) = value;
    uint8_t value2 = RAM8(0x0004);
    uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0xCF00 + value2);
    RAM8(0x0002) = value3 & 0x0F;
    uint8_t value4 = RAM8(0x0005);
    bool carry2;
    if (value4 >> 4 & 0x01) {
        RAM8(0x0002) = (value4 | RAM8(0x0002)) & 0x0F;
        carry2 = value4 >> 4 & 0x01;
    } else {
        bool carry1;
        if (value4 >> 5 & 0x01) {
            RAM8(0x0002) = (value4 | RAM8(0x0002)) & 0x0F;
            carry1 = value4 >> 5 & 0x01;
        } else {
            if (value4 >> 6 & 0x01) {
                RAM8(0x0002) = (value4 ^ RAM8(0x0002)) & 0x0F;
            }
            carry1 = value4 >> 6 & 0x01;
        }
        carry2 = carry1;
    }
    if (value4 & 0x80) {
        uint8_t value8 = BUS8_RDP(c, (db << 0x10) + 0xCF00 + value2);
        BUS8_SET(c, (db << 0x10) + 0xCF00 + value2, (value8 & 0xF0) | RAM8(0x0002));
    }
    uint8_t value10 = RAM8(0x0002);
    if (value10 == 0) {
        SET_A8(r, value10);
        r->x = value2;
        r->y = 2;
        r->c = carry2;
        r->z = value10 == 0;
        r->n = value10 & 0x80;
        RETURN_RTS(c);
    }
    uint16_t value11 = RAM16(0x00D1);
    RAM16_SET(0x00D1, (uint16_t)(value11 + 3));
    r->a = (uint16_t)(value11 + 3);
    r->x = value2;
    r->y = 2;
    r->c = value11 + 3 > 0xFFFF;
    r->z = (uint16_t)(value11 + 3) == 0;
    r->n = (uint16_t)(value11 + 3) & 0x8000;
    r->v = ((value11 ^ (uint16_t)(value11 + 3)) & ((uint16_t)(value11 + 3) ^ 3) & 0x8000) != 0;
    r->mf = 0;
    TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
}

/* C1F1CF event_combine_indexed_flag_nibble_and_execute_operation   [class A, 112 bytes, 58 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=8 bit DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_combine_indexed_flag_nibble_and_execute_operation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint8_t db = r->db;
    uint8_t value = BUS8_RDL(c, (RAM8(0x00D3) << 0x10) + RAM16(0x00D1) + 2, RAM8(0x00D3));
    RAM8(0x0004) = value;
    uint8_t value2 = BUS8_RDL(c, (RAM8(0x00D3) << 0x10) + RAM16(0x00D1) + 3, RAM8(0x00D3));
    RAM8(0x0005) &= 0xF0;
    uint8_t value4 = BUS8_RDP(c, (db << 0x10) + 0xCF00 + (uint8_t)((a_hi << 8) | value2));
    RAM8(0x0005) = (value4 & 0x0F) | RAM8(0x0005);
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    uint8_t value6 = RAM8(0x0004);
    uint8_t value7 = BUS8_RDP(c, (db << 0x10) + 0xCF00 + value6);
    RAM8(0x0002) = value7 & 0x0F;
    uint8_t value8 = RAM8(0x0005);
    bool carry2;
    if (value8 >> 4 & 0x01) {
        RAM8(0x0002) = (value8 | RAM8(0x0002)) & 0x0F;
        carry2 = value8 >> 4 & 0x01;
    } else {
        bool carry1;
        if (value8 >> 5 & 0x01) {
            RAM8(0x0002) = (value8 | RAM8(0x0002)) & 0x0F;
            carry1 = value8 >> 5 & 0x01;
        } else {
            if (value8 >> 6 & 0x01) {
                RAM8(0x0002) = (value8 ^ RAM8(0x0002)) & 0x0F;
            }
            carry1 = value8 >> 6 & 0x01;
        }
        carry2 = carry1;
    }
    if (value8 & 0x80) {
        uint8_t value12 = BUS8_RDP(c, (db << 0x10) + 0xCF00 + value6);
        BUS8_SET(c, (db << 0x10) + 0xCF00 + value6, (value12 & 0xF0) | RAM8(0x0002));
    }
    uint8_t value14 = RAM8(0x0002);
    if (value14 == 0) {
        SET_A8(r, value14);
        r->x = value6;
        r->y = 3;
        r->c = carry2;
        r->z = value14 == 0;
        r->n = value14 & 0x80;
        RETURN_RTS(c);
    }
    uint16_t value15 = RAM16(0x00D1);
    RAM16_SET(0x00D1, (uint16_t)(value15 + 3));
    r->a = (uint16_t)(value15 + 3);
    r->x = value6;
    r->y = 3;
    r->c = value15 + 3 > 0xFFFF;
    r->z = (uint16_t)(value15 + 3) == 0;
    r->n = (uint16_t)(value15 + 3) & 0x8000;
    r->v = ((value15 ^ (uint16_t)(value15 + 3)) & ((uint16_t)(value15 + 3) ^ 3) & 0x8000) != 0;
    r->mf = 0;
    TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
}

/* C1F1F1 event_branch_on_selected_actor_byte_field   [class A, 136 bytes, 71 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=any X=8 bit DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_branch_on_selected_actor_byte_field(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t db = r->db;
    uint16_t value = BUS16_RDL(c, (RAM8(0x00D3) << 0x10) + RAM16(0x00D1) + 2, RAM8(0x00D3));
    RAM16_SET(0x0002, value);
    uint16_t value2 = RAM16(0x00D4);
    uint16_t value3 = RAM16(0x0005);
    uint8_t a_hi2;
    uint16_t x2;
    if ((value3 & 0xFF) == 0) {
        a_hi2 = 0;
        x2 = value2;
    } else {
        uint16_t value4 = RAM16(0x003A);
        uint8_t a_hi1;
        uint16_t x1;
        if ((value3 & 0xFF) >= 0x80) {
            a_hi1 = 0;
            x1 = value4;
        } else {
            a_hi1 = (uint8_t)((uint16_t)((value3 & 0xFF) - 1) << 1);
            x1 = ((uint8_t)((uint16_t)((value3 & 0xFF) - 1) << 1) << 8) | ((uint16_t)((uint16_t)((value3 & 0xFF) - 1) << 1) >> 8);
        }
        a_hi2 = a_hi1;
        x2 = x1;
    }
    uint8_t value5 = RAM8(0x0002);
    uint8_t value6 = BUS8_RDP(c, (db << 0x10) + 0xE000 + (((x2 | 0x0100) >> 8 << 8) | value5));
    RAM8(0x0002) = value6;
    uint8_t value7 = RAM8(0x0004);
    uint8_t a34;
    uint8_t a_hi36;
    if ((uint8_t)((value7 & 7) - 1) == 0) {
        uint8_t value8 = RAM8(0x0002);
        uint8_t value9 = RAM8(0x0003);
        uint8_t a8;
        uint8_t a_hi10;
        if (value8 >= value9) {
            uint16_t value10 = RAM16(0x00D1);
            a8 = (uint8_t)(value10 + 4);
            a_hi10 = (uint16_t)(value10 + 4) >> 8;
        } else {
            uint8_t a7;
            uint8_t a_hi9;
            if (value8 < value9) {
                uint16_t value11 = RAM16(0x00D1);
                RAM16_SET(0x00D1, (uint16_t)(value11 + 6));
                a7 = (uint8_t)(value11 + 6);
                a_hi9 = (uint16_t)(value11 + 6) >> 8;
            } else {
                uint8_t a6;
                uint8_t a_hi8;
                if (value8 == value9) {
                    uint16_t value12 = RAM16(0x00D1);
                    a6 = (uint8_t)(value12 + 4);
                    a_hi8 = (uint16_t)(value12 + 4) >> 8;
                } else {
                    uint8_t a5;
                    uint8_t a_hi7;
                    if (value8 >= value9) {
                        uint16_t value13 = RAM16(0x00D1);
                        RAM16_SET(0x00D1, (uint16_t)(value13 + 6));
                        a5 = (uint8_t)(value13 + 6);
                        a_hi7 = (uint16_t)(value13 + 6) >> 8;
                    } else {
                        uint8_t a4;
                        uint8_t a_hi6;
                        if (value8 < value9) {
                            uint16_t value14 = RAM16(0x00D1);
                            a4 = (uint8_t)(value14 + 4);
                            a_hi6 = (uint16_t)(value14 + 4) >> 8;
                        } else {
                            uint8_t a3;
                            uint8_t a_hi5;
                            if ((value8 & value9) != 0) {
                                uint16_t value15 = RAM16(0x00D1);
                                a3 = (uint8_t)(value15 + 4);
                                a_hi5 = (uint16_t)(value15 + 4) >> 8;
                            } else {
                                uint8_t a2;
                                uint8_t a_hi4;
                                if ((value8 & value9) == 0) {
                                    uint16_t value16 = RAM16(0x00D1);
                                    RAM16_SET(0x00D1, (uint16_t)(value16 + 6));
                                    a2 = (uint8_t)(value16 + 6);
                                    a_hi4 = (uint16_t)(value16 + 6) >> 8;
                                } else {
                                    uint8_t a1;
                                    uint8_t a_hi3;
                                    if ((value8 | value9) != 0) {
                                        uint16_t value17 = RAM16(0x00D1);
                                        a1 = (uint8_t)(value17 + 4);
                                        a_hi3 = (uint16_t)(value17 + 4) >> 8;
                                    } else {
                                        uint16_t value18 = RAM16(0x00D1);
                                        RAM16_SET(0x00D1, (uint16_t)(value18 + 6));
                                        a1 = (uint8_t)(value18 + 6);
                                        a_hi3 = (uint16_t)(value18 + 6) >> 8;
                                    }
                                    a2 = a1;
                                    a_hi4 = a_hi3;
                                }
                                a3 = a2;
                                a_hi5 = a_hi4;
                            }
                            a4 = a3;
                            a_hi6 = a_hi5;
                        }
                        a5 = a4;
                        a_hi7 = a_hi6;
                    }
                    a6 = a5;
                    a_hi8 = a_hi7;
                }
                a7 = a6;
                a_hi9 = a_hi8;
            }
            a8 = a7;
            a_hi10 = a_hi9;
        }
        a34 = a8;
        a_hi36 = a_hi10;
    } else {
        uint8_t a33;
        uint8_t a_hi35;
        if ((uint8_t)((value7 & 7) - 2) == 0) {
            uint8_t value19 = RAM8(0x0002);
            uint8_t value20 = RAM8(0x0003);
            uint8_t a14;
            uint8_t a_hi16;
            if (value19 == value20) {
                uint16_t value21 = RAM16(0x00D1);
                a14 = (uint8_t)(value21 + 4);
                a_hi16 = (uint16_t)(value21 + 4) >> 8;
            } else {
                uint8_t a13;
                uint8_t a_hi15;
                if (value19 >= value20) {
                    uint16_t value22 = RAM16(0x00D1);
                    RAM16_SET(0x00D1, (uint16_t)(value22 + 6));
                    a13 = (uint8_t)(value22 + 6);
                    a_hi15 = (uint16_t)(value22 + 6) >> 8;
                } else {
                    uint8_t a12;
                    uint8_t a_hi14;
                    if (value19 < value20) {
                        uint16_t value23 = RAM16(0x00D1);
                        a12 = (uint8_t)(value23 + 4);
                        a_hi14 = (uint16_t)(value23 + 4) >> 8;
                    } else {
                        uint8_t a11;
                        uint8_t a_hi13;
                        if ((value19 & value20) != 0) {
                            uint16_t value24 = RAM16(0x00D1);
                            a11 = (uint8_t)(value24 + 4);
                            a_hi13 = (uint16_t)(value24 + 4) >> 8;
                        } else {
                            uint8_t a10;
                            uint8_t a_hi12;
                            if ((value19 & value20) == 0) {
                                uint16_t value25 = RAM16(0x00D1);
                                RAM16_SET(0x00D1, (uint16_t)(value25 + 6));
                                a10 = (uint8_t)(value25 + 6);
                                a_hi12 = (uint16_t)(value25 + 6) >> 8;
                            } else {
                                uint8_t a9;
                                uint8_t a_hi11;
                                if ((value19 | value20) != 0) {
                                    uint16_t value26 = RAM16(0x00D1);
                                    a9 = (uint8_t)(value26 + 4);
                                    a_hi11 = (uint16_t)(value26 + 4) >> 8;
                                } else {
                                    uint16_t value27 = RAM16(0x00D1);
                                    RAM16_SET(0x00D1, (uint16_t)(value27 + 6));
                                    a9 = (uint8_t)(value27 + 6);
                                    a_hi11 = (uint16_t)(value27 + 6) >> 8;
                                }
                                a10 = a9;
                                a_hi12 = a_hi11;
                            }
                            a11 = a10;
                            a_hi13 = a_hi12;
                        }
                        a12 = a11;
                        a_hi14 = a_hi13;
                    }
                    a13 = a12;
                    a_hi15 = a_hi14;
                }
                a14 = a13;
                a_hi16 = a_hi15;
            }
            a33 = a14;
            a_hi35 = a_hi16;
        } else {
            uint8_t a32;
            uint8_t a_hi34;
            if ((uint8_t)((value7 & 7) - 3) == 0) {
                uint8_t value28 = RAM8(0x0002);
                uint8_t value29 = RAM8(0x0003);
                uint8_t a17;
                uint8_t a_hi19;
                if ((value28 & value29) != 0) {
                    uint16_t value30 = RAM16(0x00D1);
                    a17 = (uint8_t)(value30 + 4);
                    a_hi19 = (uint16_t)(value30 + 4) >> 8;
                } else {
                    uint8_t a16;
                    uint8_t a_hi18;
                    if ((value28 & value29) == 0) {
                        uint16_t value31 = RAM16(0x00D1);
                        RAM16_SET(0x00D1, (uint16_t)(value31 + 6));
                        a16 = (uint8_t)(value31 + 6);
                        a_hi18 = (uint16_t)(value31 + 6) >> 8;
                    } else {
                        uint8_t a15;
                        uint8_t a_hi17;
                        if ((value28 | value29) != 0) {
                            uint16_t value32 = RAM16(0x00D1);
                            a15 = (uint8_t)(value32 + 4);
                            a_hi17 = (uint16_t)(value32 + 4) >> 8;
                        } else {
                            uint16_t value33 = RAM16(0x00D1);
                            RAM16_SET(0x00D1, (uint16_t)(value33 + 6));
                            a15 = (uint8_t)(value33 + 6);
                            a_hi17 = (uint16_t)(value33 + 6) >> 8;
                        }
                        a16 = a15;
                        a_hi18 = a_hi17;
                    }
                    a17 = a16;
                    a_hi19 = a_hi18;
                }
                a32 = a17;
                a_hi34 = a_hi19;
            } else {
                uint8_t a31;
                uint8_t a_hi33;
                if ((uint8_t)((value7 & 7) - 4) == 0) {
                    uint8_t value34 = RAM8(0x0002);
                    uint8_t value35 = RAM8(0x0003);
                    uint8_t a18;
                    uint8_t a_hi20;
                    if ((value34 | value35) != 0) {
                        uint16_t value36 = RAM16(0x00D1);
                        a18 = (uint8_t)(value36 + 4);
                        a_hi20 = (uint16_t)(value36 + 4) >> 8;
                    } else {
                        uint16_t value37 = RAM16(0x00D1);
                        RAM16_SET(0x00D1, (uint16_t)(value37 + 6));
                        a18 = (uint8_t)(value37 + 6);
                        a_hi20 = (uint16_t)(value37 + 6) >> 8;
                    }
                    a31 = a18;
                    a_hi33 = a_hi20;
                } else {
                    uint8_t a30;
                    uint8_t a_hi32;
                    if ((uint8_t)((value7 & 7) - 5) == 0) {
                        uint8_t value38 = RAM8(0x0002);
                        uint8_t value39 = RAM8(0x0003);
                        uint8_t a28;
                        uint8_t a_hi30;
                        if ((value38 ^ value39) != 0) {
                            uint16_t value40 = RAM16(0x00D1);
                            a28 = (uint8_t)(value40 + 4);
                            a_hi30 = (uint16_t)(value40 + 4) >> 8;
                        } else {
                            uint8_t a27;
                            uint8_t a_hi29;
                            if ((value38 ^ value39) == 0) {
                                uint16_t value41 = RAM16(0x00D1);
                                RAM16_SET(0x00D1, (uint16_t)(value41 + 6));
                                a27 = (uint8_t)(value41 + 6);
                                a_hi29 = (uint16_t)(value41 + 6) >> 8;
                            } else {
                                uint8_t a26;
                                uint8_t a_hi28;
                                if (value38 >= value39) {
                                    uint16_t value42 = RAM16(0x00D1);
                                    a26 = (uint8_t)(value42 + 4);
                                    a_hi28 = (uint16_t)(value42 + 4) >> 8;
                                } else {
                                    uint8_t a25;
                                    uint8_t a_hi27;
                                    if (value38 < value39) {
                                        uint16_t value43 = RAM16(0x00D1);
                                        RAM16_SET(0x00D1, (uint16_t)(value43 + 6));
                                        a25 = (uint8_t)(value43 + 6);
                                        a_hi27 = (uint16_t)(value43 + 6) >> 8;
                                    } else {
                                        uint8_t a24;
                                        uint8_t a_hi26;
                                        if (value38 == value39) {
                                            uint16_t value44 = RAM16(0x00D1);
                                            a24 = (uint8_t)(value44 + 4);
                                            a_hi26 = (uint16_t)(value44 + 4) >> 8;
                                        } else {
                                            uint8_t a23;
                                            uint8_t a_hi25;
                                            if (value38 >= value39) {
                                                uint16_t value45 = RAM16(0x00D1);
                                                RAM16_SET(0x00D1, (uint16_t)(value45 + 6));
                                                a23 = (uint8_t)(value45 + 6);
                                                a_hi25 = (uint16_t)(value45 + 6) >> 8;
                                            } else {
                                                uint8_t a22;
                                                uint8_t a_hi24;
                                                if (value38 < value39) {
                                                    uint16_t value46 = RAM16(0x00D1);
                                                    a22 = (uint8_t)(value46 + 4);
                                                    a_hi24 = (uint16_t)(value46 + 4) >> 8;
                                                } else {
                                                    uint8_t a21;
                                                    uint8_t a_hi23;
                                                    if ((value38 & value39) != 0) {
                                                        uint16_t value47 = RAM16(0x00D1);
                                                        a21 = (uint8_t)(value47 + 4);
                                                        a_hi23 = (uint16_t)(value47 + 4) >> 8;
                                                    } else {
                                                        uint8_t a20;
                                                        uint8_t a_hi22;
                                                        if ((value38 & value39) == 0) {
                                                            uint16_t value48 = RAM16(0x00D1);
                                                            RAM16_SET(0x00D1, (uint16_t)(value48 + 6));
                                                            a20 = (uint8_t)(value48 + 6);
                                                            a_hi22 = (uint16_t)(value48 + 6) >> 8;
                                                        } else {
                                                            uint8_t a19;
                                                            uint8_t a_hi21;
                                                            if ((value38 | value39) != 0) {
                                                                uint16_t value49 = RAM16(0x00D1);
                                                                a19 = (uint8_t)(value49 + 4);
                                                                a_hi21 = (uint16_t)(value49 + 4) >> 8;
                                                            } else {
                                                                uint16_t value50 = RAM16(0x00D1);
                                                                RAM16_SET(0x00D1, (uint16_t)(value50 + 6));
                                                                a19 = (uint8_t)(value50 + 6);
                                                                a_hi21 = (uint16_t)(value50 + 6) >> 8;
                                                            }
                                                            a20 = a19;
                                                            a_hi22 = a_hi21;
                                                        }
                                                        a21 = a20;
                                                        a_hi23 = a_hi22;
                                                    }
                                                    a22 = a21;
                                                    a_hi24 = a_hi23;
                                                }
                                                a23 = a22;
                                                a_hi25 = a_hi24;
                                            }
                                            a24 = a23;
                                            a_hi26 = a_hi25;
                                        }
                                        a25 = a24;
                                        a_hi27 = a_hi26;
                                    }
                                    a26 = a25;
                                    a_hi28 = a_hi27;
                                }
                                a27 = a26;
                                a_hi29 = a_hi28;
                            }
                            a28 = a27;
                            a_hi30 = a_hi29;
                        }
                        a30 = a28;
                        a_hi32 = a_hi30;
                    } else {
                        uint8_t value51 = RAM8(0x0002);
                        uint8_t value52 = RAM8(0x0003);
                        uint8_t a29;
                        uint8_t a_hi31;
                        if (value51 == value52) {
                            uint16_t value53 = RAM16(0x00D1);
                            a29 = (uint8_t)(value53 + 4);
                            a_hi31 = (uint16_t)(value53 + 4) >> 8;
                        } else {
                            uint16_t value54 = RAM16(0x00D1);
                            RAM16_SET(0x00D1, (uint16_t)(value54 + 6));
                            a29 = (uint8_t)(value54 + 6);
                            a_hi31 = (uint16_t)(value54 + 6) >> 8;
                        }
                        a30 = a29;
                        a_hi32 = a_hi31;
                    }
                    a31 = a30;
                    a_hi33 = a_hi32;
                }
                a32 = a31;
                a_hi34 = a_hi33;
            }
            a33 = a32;
            a_hi35 = a_hi34;
        }
        a34 = a33;
        a_hi36 = a_hi35;
    }
    RAM16_SET(0x00D1, (a_hi36 << 8) | a34);
    r->a = (a_hi36 << 8) | a34;
    r->x = ((x2 | 0x0100) >> 8 << 8) | value5;
    r->y = 2;
    r->mf = 0;
    r->xf = 0;
    TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
}

/* C1F2E9 event_wait_for_party_gather   [class A, 12 bytes, 6 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=any DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_wait_for_party_gather(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0x004E);
    if (value == 0) {
        RAM8(0x00D0) = 1;
        r->a = (a_hi << 8) | 1;
        r->z = 0;
        r->n = 0;
        TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
    }
    SET_A8(r, value);
    r->z = value == 0;
    r->n = value & 0x80;
    RETURN_RTS(c);
}

/* C1F2F5 event_wait_for_text_then_resume_script   [class A, 27 bytes, 12 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=any DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_wait_for_text_then_resume_script(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint8_t db = r->db;
    uint8_t value = RAM8(0x0048);
    if (value == 0) {
        uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0x1D01);
        RAM8(0x00D1) = value2;
        uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0x1D02);
        RAM8(0x00D2) = value3;
        uint8_t value4 = BUS8_RDP(c, (db << 0x10) + 0x1D03);
        RAM8(0x00D3) = value4;
        RAM8(0x00D0) = 1;
        r->a = (a_hi << 8) | 1;
        r->z = 0;
        r->n = 0;
        TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
    }
    SET_A8(r, value);
    r->z = value == 0;
    r->n = value & 0x80;
    RETURN_RTS(c);
}

/* C1F310 event_wait_for_frame_count   [class A, 12 bytes, 6 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=any DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_wait_for_frame_count(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    RAM8(0x004F)--;
    if (RAM8(0x004F) == 0) {
        RAM8(0x00D0) = 1;
        r->a = (a_hi << 8) | 1;
        r->z = 0;
        r->n = 0;
        TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
    }
    r->z = RAM8(0x004F) == 0;
    r->n = RAM8(0x004F) & 0x80;
    RETURN_RTS(c);
}

/* C1F31C event_wait_for_selected_actor_pad_press   [class A, 37 bytes, 19 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=any DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_wait_for_selected_actor_pad_press(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const uint8_t db = r->db;
    uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0xE02C + RAM16(0x00D4));
    uint8_t a2;
    bool carry1;
    if (value2 == 0) {
        a2 = value2;
        carry1 = carry;
    } else {
        uint8_t a1;
        if ((uint8_t)(value2 - 1) != 3) {
            a1 = (uint8_t)(value2 - 1);
        } else {
            a1 = 2;
        }
        a2 = a1;
        carry1 = (uint8_t)(value2 - 1) >= 3;
    }
    uint8_t value3 = RAM8(0x00CC + (uint8_t)((a_hi << 8) | a2));
    if ((value3 & 0xFC) != 0) {
        RAM8(0x00CC + (uint8_t)((a_hi << 8) | a2)) = 0;
        RAM8(0x00D0) = 1;
        r->a = (a_hi << 8) | 1;
        r->x = (uint8_t)((a_hi << 8) | a2);
        r->y = (uint8_t)y;
        r->c = carry1;
        r->z = 0;
        r->n = 0;
        r->v = value3 & 0x40;
        r->xf = 1;
        TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
    }
    SET_A8(r, 0xFC);
    r->x = (uint8_t)((a_hi << 8) | a2);
    r->y = (uint8_t)y;
    r->c = carry1;
    r->z = (value3 & 0xFC) == 0;
    r->n = value3 & 0x80;
    r->v = value3 & 0x40;
    r->xf = 1;
    RETURN_RTS(c);
}

/* C1F341 event_resume_dispatch_immediately   [class A, 7 bytes, 3 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=any DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_resume_dispatch_immediately(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    RAM8(0x00D0) = 1;
    r->a = (a_hi << 8) | 1;
    r->z = 0;
    r->n = 0;
    TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
}

/* C1F348 event_wait_for_all_active_actors_idle   [class A, 51 bytes, 24 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=any DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_wait_for_all_active_actors_idle(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const uint8_t db = r->db;
    uint8_t value = RAM8(0x00ED);
    uint16_t x2;
    bool overflow1;
    if (!(value & 0x80)) {
        x2 = 0x1600;
        overflow1 = value & 0x40;
    } else {
        uint8_t value2 = RAM8(0x005C);
        uint16_t x1;
        if (!(value2 & 0x80)) {
            x1 = 0x0A00;
        } else {
            x1 = 0x0400;
        }
        x2 = x1;
        overflow1 = value2 & 0x40;
    }
    uint8_t a_hi1 = a_hi;
    uint16_t x3 = x2;
    bool carry1 = carry;
    bool overflow2 = overflow1;
    for (;;) {
        uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0xE000 + x3);
        if (value3 == 0) {
            if (!((uint16_t)(x3 - 0x0200) & 0x8000)) {
                uint8_t a_hi1_next = (uint16_t)(x3 - 0x0200) >> 8;
                uint16_t x3_next = (uint16_t)(x3 - 0x0200);
                bool carry1_next = x3 >= 0x0200;
                bool overflow2_next = ((x3 ^ 0x0200) & (x3 ^ (uint16_t)(x3 - 0x0200)) & 0x8000) != 0;
                a_hi1 = a_hi1_next;
                x3 = x3_next;
                carry1 = carry1_next;
                overflow2 = overflow2_next;
                continue;
            }
            uint8_t a_hi1_next6 = (uint16_t)(x3 - 0x0200) >> 8;
            uint16_t x3_next6 = (uint16_t)(x3 - 0x0200);
            bool carry1_next6 = x3 >= 0x0200;
            bool overflow2_next6 = ((x3 ^ 0x0200) & (x3 ^ (uint16_t)(x3 - 0x0200)) & 0x8000) != 0;
            a_hi1 = a_hi1_next6;
            x3 = x3_next6;
            carry1 = carry1_next6;
            overflow2 = overflow2_next6;
            break;
        }
        if (value3 & 0x80) {
            if (!((uint16_t)(x3 - 0x0200) & 0x8000)) {
                uint8_t a_hi1_next2 = (uint16_t)(x3 - 0x0200) >> 8;
                uint16_t x3_next2 = (uint16_t)(x3 - 0x0200);
                bool carry1_next2 = x3 >= 0x0200;
                bool overflow2_next2 = ((x3 ^ 0x0200) & (x3 ^ (uint16_t)(x3 - 0x0200)) & 0x8000) != 0;
                a_hi1 = a_hi1_next2;
                x3 = x3_next2;
                carry1 = carry1_next2;
                overflow2 = overflow2_next2;
                continue;
            }
            uint8_t a_hi1_next5 = (uint16_t)(x3 - 0x0200) >> 8;
            uint16_t x3_next5 = (uint16_t)(x3 - 0x0200);
            bool carry1_next5 = x3 >= 0x0200;
            bool overflow2_next5 = ((x3 ^ 0x0200) & (x3 ^ (uint16_t)(x3 - 0x0200)) & 0x8000) != 0;
            a_hi1 = a_hi1_next5;
            x3 = x3_next5;
            carry1 = carry1_next5;
            overflow2 = overflow2_next5;
            break;
        }
        uint8_t value4 = BUS8_RDP(c, (db << 0x10) + 0xE042 + x3);
        if (value4 == 0) {
            if (!((uint16_t)(x3 - 0x0200) & 0x8000)) {
                uint8_t a_hi1_next3 = (uint16_t)(x3 - 0x0200) >> 8;
                uint16_t x3_next3 = (uint16_t)(x3 - 0x0200);
                bool carry1_next3 = x3 >= 0x0200;
                bool overflow2_next3 = ((x3 ^ 0x0200) & (x3 ^ (uint16_t)(x3 - 0x0200)) & 0x8000) != 0;
                a_hi1 = a_hi1_next3;
                x3 = x3_next3;
                carry1 = carry1_next3;
                overflow2 = overflow2_next3;
                continue;
            }
            uint8_t a_hi1_next4 = (uint16_t)(x3 - 0x0200) >> 8;
            uint16_t x3_next4 = (uint16_t)(x3 - 0x0200);
            bool carry1_next4 = x3 >= 0x0200;
            bool overflow2_next4 = ((x3 ^ 0x0200) & (x3 ^ (uint16_t)(x3 - 0x0200)) & 0x8000) != 0;
            a_hi1 = a_hi1_next4;
            x3 = x3_next4;
            carry1 = carry1_next4;
            overflow2 = overflow2_next4;
            break;
        }
        r->a = (a_hi1 << 8) | value4;
        r->x = x3;
        r->y = y;
        r->c = carry1;
        r->z = value4 == 0;
        r->n = value4 & 0x80;
        r->v = overflow2;
        r->xf = 0;
        RETURN_RTS(c);
    }
    RAM8(0x00D0) = 1;
    r->a = (a_hi1 << 8) | 1;
    r->x = x3;
    r->y = y;
    r->c = carry1;
    r->z = 0;
    r->n = 0;
    r->v = overflow2;
    r->xf = 0;
    TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
}

/* C1F37B event_wait_for_camera_center   [class A, 14 bytes, 7 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=any DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_wait_for_camera_center(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0x00E2);
    if ((value & 8) == 0) {
        RAM8(0x00D0) = 1;
        r->a = (a_hi << 8) | 1;
        r->z = 0;
        r->n = 0;
        TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
    }
    SET_A8(r, value);
    r->z = (value & 8) == 0;
    r->n = value & 0x80;
    RETURN_RTS(c);
}

/* C1F389 event_reserved_state_resume_dispatch   [class A, 7 bytes, 3 instructions]
 * Source: src/rom/dispatch_native_event_opcode_or_wait_state.s
 * Subroutine of dispatch_native_event_opcode_or_wait_state, translated in place.
 * Entry: M=8 bit X=any DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void event_reserved_state_resume_dispatch(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    RAM8(0x00D0) = 1;
    r->a = (a_hi << 8) | 1;
    r->z = 0;
    r->n = 0;
    TAIL_CALL(c, 0xC1E8D3, SOM_RTS); /* dispatch_native_event_opcode_or_wait_state */
}
