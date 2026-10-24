; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

compare_selected_pad_buttons_against_native_previous_buttons = $325A
preserve_accumulator_byte_and_request_fixed_local_audio_presets = $1BA5

.segment "CODE"
.org $2E65
request_native_save_confirmation_page_on_changed_buttons:
    jsr compare_selected_pad_buttons_against_native_previous_buttons
    beq request_native_save_confirmation_page_on_changed_buttons_c02e7c
    .a8
    lda #$0A
    sta a:$A210
    .a8
    lda #$01
    tsb a:$A20A
    .a8
    lda #$20
    trb a:$A212
    jsr preserve_accumulator_byte_and_request_fixed_local_audio_presets
request_native_save_confirmation_page_on_changed_buttons_c02e7c:
    rts
