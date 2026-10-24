; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-projection.md.
.setcpu "65816"
.smart
.a8
.i16

multiply_signed_ui_coordinate_using_two_native_byte_products = $B453

.segment "CODE"
.org $B435
multiply_ui_target_pair_in_second_coefficient_order:
    ldx $0E
    jsr multiply_signed_ui_coordinate_using_two_native_byte_products
    stx $04
    ldx $0C
    jsr multiply_signed_ui_coordinate_using_two_native_byte_products
    stx $00
    rts
