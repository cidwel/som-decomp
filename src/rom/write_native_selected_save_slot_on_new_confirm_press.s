; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

derive_native_menu_selected_pad_offset_preserving_accumulator_byte = $3269
expand_local_audio_preset_and_send_four_byte_request = $29D2
write_selected_saved_game_to_primary_and_backup_sram = $C755D6

.segment "CODE"
.org $2E7D
write_native_selected_save_slot_on_new_confirm_press:
    jsr derive_native_menu_selected_pad_offset_preserving_accumulator_byte
    lda a:$A204,X
    .a8
    bit #$80
    bne write_native_selected_save_slot_on_new_confirm_press_c02ea1
    jsl f:write_selected_saved_game_to_primary_and_backup_sram
    lda a:$A211
    sta f:$307FFF
    .a8
    lda #$01
    tsb a:$A20A
    .a8
    lda #$20
    trb a:$A212
    .a8
    lda #$02
    jsr expand_local_audio_preset_and_send_four_byte_request
write_native_selected_save_slot_on_new_confirm_press_c02ea1:
    rts
