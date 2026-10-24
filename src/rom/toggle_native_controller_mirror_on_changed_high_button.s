; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-controller-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

derive_native_menu_selected_pad_offset_preserving_accumulator_byte = $3269
preserve_accumulator_byte_and_request_fixed_local_audio_presets = $1BA5
toggle_native_controller_layout_mirror_flags = $C76F69

.segment "CODE"
.org $3134
toggle_native_controller_mirror_on_changed_high_button:
    jsr derive_native_menu_selected_pad_offset_preserving_accumulator_byte
    lda $42,X
    cmp a:$A203,X
    beq toggle_native_controller_mirror_on_changed_high_button_c0314a
    jsr preserve_accumulator_byte_and_request_fixed_local_audio_presets
    jsl f:toggle_native_controller_layout_mirror_flags
    .a8
    lda #$80
    tsb a:$A212
toggle_native_controller_mirror_on_changed_high_button_c0314a:
    rts
