; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-controller-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

clear_native_saved_slot_rectangle_highlight = $C757D5
decode_native_controller_layout_and_publish_four_button_labels = $C76DFC
derive_native_menu_selected_pad_offset_preserving_accumulator_byte = $3269
encode_native_controller_permutation_from_twenty_four_masks = $C76ED6
preserve_accumulator_byte_and_request_fixed_local_audio_presets = $1BA5

.segment "CODE"
.org $30FF
commit_native_controller_permutation_on_button_release:
    jsr derive_native_menu_selected_pad_offset_preserving_accumulator_byte
    lda $42,X
    ora $43,X
    bne commit_native_controller_permutation_on_button_release_c03133
    lda a:$A203,X
    ora a:$A204,X
    .a8
    and #$C0
    beq commit_native_controller_permutation_on_button_release_c03133
    jsr preserve_accumulator_byte_and_request_fixed_local_audio_presets
    jsl f:clear_native_saved_slot_rectangle_highlight
    jsl f:encode_native_controller_permutation_from_twenty_four_masks
    jsl f:decode_native_controller_layout_and_publish_four_button_labels
    stz a:$A180
    .a8
    lda #$04
    sta a:$A1D8
    .a8
    lda #$02
    tsb a:$A20A
    .a8
    lda #$40
    trb a:$A212
commit_native_controller_permutation_on_button_release_c03133:
    rts
