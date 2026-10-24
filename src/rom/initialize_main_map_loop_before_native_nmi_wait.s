; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-map-entry-prefix.md.
.setcpu "65816"
.smart
.a8
.i16

blank_display_disable_interrupts_and_clear_windows_for_map_entry = $87C4
clear_map_direct_page_scratch_preserving_first_word = $BC9B
initialize_complete_map_entry = $BC0B
refresh_three_party_weapon_graphics_with_saved_bank = $E9F8
request_actual_map_entry_event_and_restore_deferred_party_actor = $BEAA

.segment "CODE"
.org $B03F
initialize_main_map_loop_before_native_nmi_wait:
    rep #$10
    .i16
    ldx #$01FF
    txs
    sei
    jsr blank_display_disable_interrupts_and_clear_windows_for_map_entry
    jsr clear_map_direct_page_scratch_preserving_first_word
    jsr initialize_complete_map_entry
    jsr refresh_three_party_weapon_graphics_with_saved_bank
    jsr request_actual_map_entry_event_and_restore_deferred_party_actor
