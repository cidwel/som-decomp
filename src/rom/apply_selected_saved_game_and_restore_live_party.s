; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-apply.md.
.setcpu "65816"
.smart
.a8
.i16

read_saved_map_word_after_skipping_two_bytes = $58EB
read_saved_menu_word_without_advancing_sram_cursor = $593C
restore_first_controller_binding_and_clear_other_two = $58FA
restore_loaded_party_actor_records_public_jump = $C00021
select_save_slot_copy_and_reject_invalid_pair = $583C
unpack_128_save_bytes_into_wram = $587A
unpack_128_save_nibble_pairs_into_wram = $588B
unpack_eight_saved_menu_bytes = $591A
unpack_saved_map_position_to_low_bank_globals = $58D1
unpack_saved_menu_word_and_advance_sram_cursor = $592E
unpack_seventeen_saved_menu_bytes = $5906
unpack_three_saved_actor_name_prefixes = $58A8
unpack_three_saved_menu_bytes = $5948

.segment "CODE"
.org $557A
apply_selected_saved_game_and_restore_live_party:
    lda a:$A211
    sta f:$307FFF
    jsr select_save_slot_copy_and_reject_invalid_pair
    lda a:$A212
    .a8
    bit #$04
    bne apply_selected_saved_game_and_restore_live_party_c755d5
    inx
    phx
    inx
    inx
    .i16
    ldy #$CC00
    jsr unpack_128_save_bytes_into_wram
    .i16
    ldy #$CF00
    jsr unpack_128_save_nibble_pairs_into_wram
    .i16
    ldy #$E180
    jsr unpack_128_save_bytes_into_wram
    .i16
    ldy #$E380
    jsr unpack_128_save_bytes_into_wram
    .i16
    ldy #$E580
    jsr unpack_128_save_bytes_into_wram
    jsr unpack_three_saved_actor_name_prefixes
    jsr unpack_saved_map_position_to_low_bank_globals
    jsr restore_first_controller_binding_and_clear_other_two
    jsr unpack_seventeen_saved_menu_bytes
    jsr unpack_saved_menu_word_and_advance_sram_cursor
    jsr unpack_eight_saved_menu_bytes
    jsr unpack_three_saved_menu_bytes
    jsr read_saved_map_word_after_skipping_two_bytes
    plx
    phx
    jsl f:restore_loaded_party_actor_records_public_jump
    .a8
    lda #$FE
    sta f:$00011F
    plx
    jsr read_saved_menu_word_without_advancing_sram_cursor
apply_selected_saved_game_and_restore_live_party_c755d5:
    rtl
