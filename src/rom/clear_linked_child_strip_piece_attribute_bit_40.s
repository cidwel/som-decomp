; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5E8C
clear_linked_child_strip_piece_attribute_bit_40:
    lda $89
    clc
    .a16
    adc #$0015
    tay
    lda a:$0002,Y
    .a16
    and #$FFBF
    sta a:$0002,Y
    rts
