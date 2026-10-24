; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-title-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

preserve_accumulator_byte_and_request_fixed_local_audio_presets = $1BA5
select_title_load_or_new_game_page_and_initialize_save_records = $C75F4A

.segment "CODE"
.org $2D27
confirm_native_title_selection_on_changed_pad_zero:
    lda $43
    cmp a:$A204
    beq confirm_native_title_selection_on_changed_pad_zero_c02d35
    jsr preserve_accumulator_byte_and_request_fixed_local_audio_presets
    jsl f:select_title_load_or_new_game_page_and_initialize_save_records
confirm_native_title_selection_on_changed_pad_zero_c02d35:
    rts
