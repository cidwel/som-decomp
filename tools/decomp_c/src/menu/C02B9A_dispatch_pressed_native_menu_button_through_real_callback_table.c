#include "som_c.h"

/* C02B9A dispatch_pressed_native_menu_button_through_real_callback_table   [class C, 11 bytes, 6 instructions]
 * Source: src/rom/dispatch_pressed_native_menu_button_through_real_callback_table.s
 * Documented in docs/ui-native-loaded-game-input-dispatch.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void dispatch_pressed_native_menu_button_through_real_callback_table(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    bool m_flag;
    bool x_flag;
    uint8_t a_hi1;
    uint16_t y1;
    bool carry1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if (zero) {
        m_flag = 1;
        x_flag = 0;
        a_hi1 = a_hi;
        y1 = y;
        carry1 = carry;
        overflow1 = overflow;
        data_bank = 0x7E;
        direct_page = 0;
    } else {
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x2B9F, 0xC03275); GUARD_JSR(c, sp_call, 0x2B9F); } /* derive_native_menu_button_and_page_callback_table_index */
        r->sp += 2;
        uint16_t x_ret = r->x;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp;
        switch (x_ret) {
        case 0x0000: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0002: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0004: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0006: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0008: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x000A: JSR(c, 0x2BA2, 0xC02BEA); GUARD_JSR(c, sp_call, 0x2BA2); break; /* adjust_native_selector_component_zero */
        case 0x000C: JSR(c, 0x2BA2, 0xC03078); GUARD_JSR(c, sp_call, 0x2BA2); break; /* select_native_controller_button_three_from_exclusive_current_mask */
        case 0x000E: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0010: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0012: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0014: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0016: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0018: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x001A: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x001C: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x001E: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0020: JSR(c, 0x2BA2, 0xC02BEF); GUARD_JSR(c, sp_call, 0x2BA2); break; /* adjust_native_selector_component_two */
        case 0x0022: JSR(c, 0x2BA2, 0xC030A2); GUARD_JSR(c, sp_call, 0x2BA2); break; /* select_native_controller_button_one_from_exclusive_current_mask */
        case 0x0024: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0026: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0028: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x002A: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x002C: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x002E: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0030: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0032: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0034: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0036: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0038: JSR(c, 0x2BA2, 0xC03134); GUARD_JSR(c, sp_call, 0x2BA2); break; /* toggle_native_controller_mirror_on_changed_high_button */
        case 0x003A: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x003C: JSR(c, 0x2BA2, 0xC02D50); GUARD_JSR(c, sp_call, 0x2BA2); break; /* request_item_page_and_restore_its_remembered_slot */
        case 0x003E: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0040: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0042: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0044: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0046: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0048: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x004A: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x004C: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x004E: JSR(c, 0x2BA2, 0xC03134); GUARD_JSR(c, sp_call, 0x2BA2); break; /* toggle_native_controller_mirror_on_changed_high_button */
        case 0x0050: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0052: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0054: JSR(c, 0x2BA2, 0xC02D36); GUARD_JSR(c, sp_call, 0x2BA2); break; /* request_spell_page_for_a_magic_capable_actor */
        case 0x0056: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0058: JSR(c, 0x2BA2, 0xC02D27); GUARD_JSR(c, sp_call, 0x2BA2); break; /* confirm_native_title_selection_on_changed_pad_zero */
        case 0x005A: JSR(c, 0x2BA2, 0xC02E65); GUARD_JSR(c, sp_call, 0x2BA2); break; /* request_native_save_confirmation_page_on_changed_buttons */
        case 0x005C: JSR(c, 0x2BA2, 0xC02EBC); GUARD_JSR(c, sp_call, 0x2BA2); break; /* confirm_native_load_selection_and_apply_save_or_return_title */
        case 0x005E: JSR(c, 0x2BA2, 0xC0318E); GUARD_JSR(c, sp_call, 0x2BA2); break; /* append_selected_native_name_glyph */
        case 0x0060: JSR(c, 0x2BA2, 0xC02F15); GUARD_JSR(c, sp_call, 0x2BA2); break; /* confirm_native_personality_selection_or_open_selector */
        case 0x0062: JSR(c, 0x2BA2, 0xC02BFB); GUARD_JSR(c, sp_call, 0x2BA2); break; /* commit_native_controller_bindings_on_changed_press */
        case 0x0064: JSR(c, 0x2BA2, 0xC0308D); GUARD_JSR(c, sp_call, 0x2BA2); break; /* select_native_controller_button_two_from_exclusive_current_mask */
        case 0x0066: JSR(c, 0x2BA2, 0xC02EE0); GUARD_JSR(c, sp_call, 0x2BA2); break; /* cycle_native_party_page_to_next_active_hero */
        case 0x0068: JSR(c, 0x2BA2, 0xC02D6F); GUARD_JSR(c, sp_call, 0x2BA2); break; /* confirm_native_spell_item_selection_or_open_detail */
        case 0x006A: JSR(c, 0x2BA2, 0xC02D6F); GUARD_JSR(c, sp_call, 0x2BA2); break; /* confirm_native_spell_item_selection_or_open_detail */
        case 0x006C: JSR(c, 0x2BA2, 0xC02E7D); GUARD_JSR(c, sp_call, 0x2BA2); break; /* write_native_selected_save_slot_on_new_confirm_press */
        case 0x006E: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0070: JSR(c, 0x2BA2, 0xC0305A); GUARD_JSR(c, sp_call, 0x2BA2); break; /* request_native_menu_close_and_clear_auxiliary_page_flag */
        case 0x0072: JSR(c, 0x2BA2, 0xC0306A); GUARD_JSR(c, sp_call, 0x2BA2); break; /* cancel_native_load_selection_and_request_title_page */
        case 0x0074: JSR(c, 0x2BA2, 0xC031C2); GUARD_JSR(c, sp_call, 0x2BA2); break; /* delete_native_name_glyph_on_new_right_button */
        case 0x0076: JSR(c, 0x2BA2, 0xC03043); GUARD_JSR(c, sp_call, 0x2BA2); break; /* cancel_native_personality_selector_or_request_menu_close */
        case 0x0078: JSR(c, 0x2BA2, 0xC02BF4); GUARD_JSR(c, sp_call, 0x2BA2); break; /* adjust_native_selector_component_one */
        case 0x007A: JSR(c, 0x2BA2, 0xC030B7); GUARD_JSR(c, sp_call, 0x2BA2); break; /* select_native_controller_button_zero_and_process_shared_gesture */
        case 0x007C: JSR(c, 0x2BA2, 0xC0305A); GUARD_JSR(c, sp_call, 0x2BA2); break; /* request_native_menu_close_and_clear_auxiliary_page_flag */
        case 0x007E: JSR(c, 0x2BA2, 0xC0317E); GUARD_JSR(c, sp_call, 0x2BA2); break; /* cancel_spell_item_selection_and_request_page_rebuild */
        case 0x0080: JSR(c, 0x2BA2, 0xC0317E); GUARD_JSR(c, sp_call, 0x2BA2); break; /* cancel_spell_item_selection_and_request_page_rebuild */
        case 0x0082: JSR(c, 0x2BA2, 0xC02EA2); GUARD_JSR(c, sp_call, 0x2BA2); break; /* cancel_save_confirmation_and_remember_selected_slot */
        case 0x0084: JSR(c, 0x2BA2, 0xC02CBE); GUARD_JSR(c, sp_call, 0x2BA2); break; /* move_title_or_load_slot_selection_up_with_native_wrap */
        case 0x0086: JSR(c, 0x2BA2, 0xC0305A); GUARD_JSR(c, sp_call, 0x2BA2); break; /* request_native_menu_close_and_clear_auxiliary_page_flag */
        case 0x0088: JSR(c, 0x2BA2, 0xC0306A); GUARD_JSR(c, sp_call, 0x2BA2); break; /* cancel_native_load_selection_and_request_title_page */
        case 0x008A: JSR(c, 0x2BA2, 0xC031B6); GUARD_JSR(c, sp_call, 0x2BA2); break; /* delete_native_name_glyph_on_new_left_button */
        case 0x008C: JSR(c, 0x2BA2, 0xC03043); GUARD_JSR(c, sp_call, 0x2BA2); break; /* cancel_native_personality_selector_or_request_menu_close */
        case 0x008E: JSR(c, 0x2BA2, 0xC02C0F); GUARD_JSR(c, sp_call, 0x2BA2); break; /* snapshot_or_restore_native_settings_selection_on_changed_press */
        case 0x0090: JSR(c, 0x2BA2, 0xC0300C); GUARD_JSR(c, sp_call, 0x2BA2); break; /* cancel_native_controller_layout_changes_or_request_menu_close */
        case 0x0092: JSR(c, 0x2BA2, 0xC0305A); GUARD_JSR(c, sp_call, 0x2BA2); break; /* request_native_menu_close_and_clear_auxiliary_page_flag */
        case 0x0094: JSR(c, 0x2BA2, 0xC0317E); GUARD_JSR(c, sp_call, 0x2BA2); break; /* cancel_spell_item_selection_and_request_page_rebuild */
        case 0x0096: JSR(c, 0x2BA2, 0xC0317E); GUARD_JSR(c, sp_call, 0x2BA2); break; /* cancel_spell_item_selection_and_request_page_rebuild */
        case 0x0098: JSR(c, 0x2BA2, 0xC02EA2); GUARD_JSR(c, sp_call, 0x2BA2); break; /* cancel_save_confirmation_and_remember_selected_slot */
        case 0x009A: JSR(c, 0x2BA2, 0xC02D27); GUARD_JSR(c, sp_call, 0x2BA2); break; /* confirm_native_title_selection_on_changed_pad_zero */
        case 0x009C: JSR(c, 0x2BA2, 0xC02E65); GUARD_JSR(c, sp_call, 0x2BA2); break; /* request_native_save_confirmation_page_on_changed_buttons */
        case 0x009E: JSR(c, 0x2BA2, 0xC02EBC); GUARD_JSR(c, sp_call, 0x2BA2); break; /* confirm_native_load_selection_and_apply_save_or_return_title */
        case 0x00A0: JSR(c, 0x2BA2, 0xC031E2); GUARD_JSR(c, sp_call, 0x2BA2); break; /* confirm_native_name_and_initialize_hero */
        case 0x00A2: JSR(c, 0x2BA2, 0xC02F15); GUARD_JSR(c, sp_call, 0x2BA2); break; /* confirm_native_personality_selection_or_open_selector */
        case 0x00A4: JSR(c, 0x2BA2, 0xC02BFB); GUARD_JSR(c, sp_call, 0x2BA2); break; /* commit_native_controller_bindings_on_changed_press */
        case 0x00A6: JSR(c, 0x2BA2, 0xC0302F); GUARD_JSR(c, sp_call, 0x2BA2); break; /* commit_native_controller_bindings_before_changed_press_exit */
        case 0x00A8: JSR(c, 0x2BA2, 0xC02EE0); GUARD_JSR(c, sp_call, 0x2BA2); break; /* cycle_native_party_page_to_next_active_hero */
        case 0x00AA: JSR(c, 0x2BA2, 0xC02D6F); GUARD_JSR(c, sp_call, 0x2BA2); break; /* confirm_native_spell_item_selection_or_open_detail */
        case 0x00AC: JSR(c, 0x2BA2, 0xC02D6F); GUARD_JSR(c, sp_call, 0x2BA2); break; /* confirm_native_spell_item_selection_or_open_detail */
        case 0x00AE: JSR(c, 0x2BA2, 0xC02E7D); GUARD_JSR(c, sp_call, 0x2BA2); break; /* write_native_selected_save_slot_on_new_confirm_press */
        case 0x00B0: JSR(c, 0x2BA2, 0xC02CBE); GUARD_JSR(c, sp_call, 0x2BA2); break; /* move_title_or_load_slot_selection_up_with_native_wrap */
        case 0x00B2: JSR(c, 0x2BA2, 0xC02CBE); GUARD_JSR(c, sp_call, 0x2BA2); break; /* move_title_or_load_slot_selection_up_with_native_wrap */
        case 0x00B4: JSR(c, 0x2BA2, 0xC02CBE); GUARD_JSR(c, sp_call, 0x2BA2); break; /* move_title_or_load_slot_selection_up_with_native_wrap */
        case 0x00B6: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x00B8: JSR(c, 0x2BA2, 0xC02F41); GUARD_JSR(c, sp_call, 0x2BA2); break; /* move_native_personality_cursor_up_or_previous_selector_row */
        case 0x00BA: JSR(c, 0x2BA2, 0xC02C3C); GUARD_JSR(c, sp_call, 0x2BA2); break; /* advance_native_settings_palette_cursor */
        case 0x00BC: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x00BE: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x00C0: JSR(c, 0x2BA2, 0xC02DAD); GUARD_JSR(c, sp_call, 0x2BA2); break; /* move_spell_item_slot_up_with_two_column_wrap */
        case 0x00C2: JSR(c, 0x2BA2, 0xC02DAD); GUARD_JSR(c, sp_call, 0x2BA2); break; /* move_spell_item_slot_up_with_two_column_wrap */
        case 0x00C4: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x00C6: JSR(c, 0x2BA2, 0xC02CF3); GUARD_JSR(c, sp_call, 0x2BA2); break; /* move_title_or_load_slot_selection_down_with_native_wrap */
        case 0x00C8: JSR(c, 0x2BA2, 0xC02CF3); GUARD_JSR(c, sp_call, 0x2BA2); break; /* move_title_or_load_slot_selection_down_with_native_wrap */
        case 0x00CA: JSR(c, 0x2BA2, 0xC02CF3); GUARD_JSR(c, sp_call, 0x2BA2); break; /* move_title_or_load_slot_selection_down_with_native_wrap */
        case 0x00CC: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x00CE: JSR(c, 0x2BA2, 0xC02F83); GUARD_JSR(c, sp_call, 0x2BA2); break; /* move_native_personality_cursor_down_or_next_selector_row */
        case 0x00D0: JSR(c, 0x2BA2, 0xC02C59); GUARD_JSR(c, sp_call, 0x2BA2); break; /* retreat_native_settings_palette_cursor */
        case 0x00D2: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x00D4: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x00D6: JSR(c, 0x2BA2, 0xC02DE2); GUARD_JSR(c, sp_call, 0x2BA2); break; /* move_spell_item_slot_down_with_two_column_wrap */
        case 0x00D8: JSR(c, 0x2BA2, 0xC02DE2); GUARD_JSR(c, sp_call, 0x2BA2); break; /* move_spell_item_slot_down_with_two_column_wrap */
        case 0x00DA: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x00DC: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x00DE: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x00E0: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x00E2: JSR(c, 0x2BA2, 0xC03210); GUARD_JSR(c, sp_call, 0x2BA2); break; /* move_native_name_cursor_left */
        case 0x00E4: JSR(c, 0x2BA2, 0xC02FC8); GUARD_JSR(c, sp_call, 0x2BA2); break; /* move_native_personality_grid_cursor_left */
        case 0x00E6: JSR(c, 0x2BA2, 0xC02C76); GUARD_JSR(c, sp_call, 0x2BA2); break; /* decrease_selected_native_settings_icon_variant */
        case 0x00E8: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x00EA: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x00EC: JSR(c, 0x2BA2, 0xC02E14); GUARD_JSR(c, sp_call, 0x2BA2); break; /* move_spell_item_slot_left_with_last_slot_wrap */
        case 0x00EE: JSR(c, 0x2BA2, 0xC02E14); GUARD_JSR(c, sp_call, 0x2BA2); break; /* move_spell_item_slot_left_with_last_slot_wrap */
        case 0x00F0: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x00F2: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x00F4: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x00F6: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x00F8: JSR(c, 0x2BA2, 0xC03221); GUARD_JSR(c, sp_call, 0x2BA2); break; /* move_native_name_cursor_right_and_publish_corners */
        case 0x00FA: JSR(c, 0x2BA2, 0xC02FEA); GUARD_JSR(c, sp_call, 0x2BA2); break; /* move_native_personality_grid_cursor_right */
        case 0x00FC: JSR(c, 0x2BA2, 0xC02C9A); GUARD_JSR(c, sp_call, 0x2BA2); break; /* increase_selected_native_settings_icon_variant */
        case 0x00FE: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0100: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0102: JSR(c, 0x2BA2, 0xC02E3D); GUARD_JSR(c, sp_call, 0x2BA2); break; /* move_spell_item_slot_right_with_first_slot_wrap */
        case 0x0104: JSR(c, 0x2BA2, 0xC02E3D); GUARD_JSR(c, sp_call, 0x2BA2); break; /* move_spell_item_slot_right_with_first_slot_wrap */
        case 0x0106: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0108: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x010A: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x010C: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x010E: JSR(c, 0x2BA2, 0xC03244); GUARD_JSR(c, sp_call, 0x2BA2); break; /* set_native_name_idle_timer */
        case 0x0110: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0112: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0114: JSR(c, 0x2BA2, 0xC030FF); GUARD_JSR(c, sp_call, 0x2BA2); break; /* commit_native_controller_permutation_on_button_release */
        case 0x0116: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x0118: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x011A: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        case 0x011C: JSR(c, 0x2BA2, 0xC03296); GUARD_JSR(c, sp_call, 0x2BA2); break; /* return_from_native_menu_no_action_callback */
        default: JSR(c, 0x2BA2, 0xC00000 | BUS16(c, 0xC00000 + (uint16_t)(0x3297 + (x_ret)))); GUARD_JSR(c, sp_call, 0x2BA2);
        }
        }
        r->sp += 2;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret2 = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t y_ret = r->y;
        bool carry_ret2 = r->c;
        bool overflow_ret2 = r->v;
        m_flag = m_ret;
        x_flag = x_ret2;
        a_hi1 = a_all2 >> 8;
        y1 = y_ret;
        carry1 = carry_ret2;
        overflow1 = overflow_ret2;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    if (x_flag) {
        c->fail = 3;
        return;
    } else {
        uint8_t value2 = RAM8(0x0000 + sp0 - 1);
        uint8_t value3 = RAM8(0x0000 + sp0);
        r->a = (a_hi1 << 8) | a;
        r->x = (value3 << 8) | value2;
        r->y = y1;
        r->c = carry1;
        r->v = overflow1;
        r->mf = m_flag;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC02B9A, SOM_RTS, "gen", dispatch_pressed_native_menu_button_through_real_callback_table, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 11, 6)
