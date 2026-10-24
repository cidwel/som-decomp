; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-controller-layout.md.
.setcpu "65816"
.smart
.a8
.i16

decode_six_native_controller_pair_swap_bits = $6F39
publish_four_native_controller_button_label_tile_strips = $6E36

.segment "CODE"
.org $6DFC
decode_native_controller_layout_and_publish_four_button_labels:
    .a8
    lda #$03
    .i16
    ldx #$0004
decode_native_controller_layout_and_publish_four_button_labels_c76e01:
    sta a:$9BFF,X
    dec
    dex
    bne decode_native_controller_layout_and_publish_four_button_labels_c76e01
    ldx a:$A220
    lda a:$A22F,X
    lsr
    lsr
    jsr decode_six_native_controller_pair_swap_bits
    jsr publish_four_native_controller_button_label_tile_strips
    rtl
