; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-write.md.
.setcpu "65816"
.smart
.a8
.i16

advance_native_save_serial_and_propagate_counter_to_valid_slots = $5618
derive_primary_sram_slot_offset_from_selected_index = $57C6
pack_128_wram_bytes_into_two_sram_slot_copies = $56E1
pack_128_wram_nibble_pairs_into_two_sram_slot_copies = $56F6
pack_low_bank_map_position_into_saved_slot = $5731
pack_menu_word_into_two_copies_and_advance_cursor = $579F
pack_seventeen_menu_bytes_into_saved_slot = $576F
pack_three_party_name_prefixes_into_saved_slot = $571E
pack_twelve_menu_bytes_into_saved_slot = $5787
select_active_controller_binding_and_pack_low_nibble = $574F
write_current_map_word_to_both_saved_slot_copies = $56D0
write_two_save_signatures_and_checksum_primary_payload = $56A9

.segment "CODE"
.org $55D6
write_selected_saved_game_to_primary_and_backup_sram:
    jsr derive_primary_sram_slot_offset_from_selected_index
    phx
    inx
    inx
    inx
    .i16
    ldy #$CC00
    jsr pack_128_wram_bytes_into_two_sram_slot_copies
    .i16
    ldy #$CF00
    jsr pack_128_wram_nibble_pairs_into_two_sram_slot_copies
    .i16
    ldy #$E180
    jsr pack_128_wram_bytes_into_two_sram_slot_copies
    .i16
    ldy #$E380
    jsr pack_128_wram_bytes_into_two_sram_slot_copies
    .i16
    ldy #$E580
    jsr pack_128_wram_bytes_into_two_sram_slot_copies
    jsr pack_three_party_name_prefixes_into_saved_slot
    jsr pack_low_bank_map_position_into_saved_slot
    jsr select_active_controller_binding_and_pack_low_nibble
    jsr pack_seventeen_menu_bytes_into_saved_slot
    jsr pack_menu_word_into_two_copies_and_advance_cursor
    jsr pack_twelve_menu_bytes_into_saved_slot
    jsr advance_native_save_serial_and_propagate_counter_to_valid_slots
    jsr write_current_map_word_to_both_saved_slot_copies
    plx
    jsr write_two_save_signatures_and_checksum_primary_payload
    rtl
