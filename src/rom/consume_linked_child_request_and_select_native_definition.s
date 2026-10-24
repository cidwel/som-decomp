; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-child.md.
.setcpu "65816"
.smart
.a8
.i16

clear_linked_child_strip_piece_attribute_bit_40 = $5E8C

.segment "CODE"
.org $5E9D
consume_linked_child_request_and_select_native_definition:
    ldy $87
    lda a:$0081,Y
    bne consume_linked_child_request_and_select_native_definition_c25ea6
    clc
    rts
consume_linked_child_request_and_select_native_definition_c25ea6:
    stz a:$00C2,X
    stz a:$0090,X
    asl
    tax
    .a16
    lda #$0000
    sta a:$0081,Y
    lda f:$C259E9,X
    sta a:$008E,Y
    sta a:$0094,Y
    jsr clear_linked_child_strip_piece_attribute_bit_40
    clc
    rts
