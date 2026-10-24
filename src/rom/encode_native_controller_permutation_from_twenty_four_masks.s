; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-controller-layout.md.
.setcpu "65816"
.smart
.a8
.i16

compare_four_native_controller_permutation_entries = $6F15
decode_native_controller_layout_and_publish_four_button_labels = $C76DFC
snapshot_native_controller_permutation_to_two_buffers = $C76F29

.segment "CODE"
.org $6ED6
encode_native_controller_permutation_from_twenty_four_masks:
    .i16
    ldx #$0000
    stx a:$A1A2
    .a8
    lda #$18
    sta a:$A198
encode_native_controller_permutation_from_twenty_four_masks_c76ee1:
    lda a:$A198
    beq encode_native_controller_permutation_from_twenty_four_masks_c76f14
    ldx a:$A1A2
    lda f:$C76FE9,X
    sta a:$A1CB
    inx
    stx a:$A1A2
    ldx a:$A220
    lda a:$A22F,X
    .a8
    and #$03
    ora a:$A1CB
    sta a:$A22F,X
    jsl f:decode_native_controller_layout_and_publish_four_button_labels
    jsr compare_four_native_controller_permutation_entries
    php
    dec a:$A198
    plp
    bne encode_native_controller_permutation_from_twenty_four_masks_c76ee1
    jsl f:snapshot_native_controller_permutation_to_two_buffers
encode_native_controller_permutation_from_twenty_four_masks_c76f14:
    rtl
