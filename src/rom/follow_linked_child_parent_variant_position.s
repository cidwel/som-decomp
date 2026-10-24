; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-motion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5D5C
follow_linked_child_parent_variant_position:
    ldx $87
    ldy a:$00B0,X
    lda a:$007A,X
    bne follow_linked_child_parent_variant_position_c25d72
    lda a:$002B,Y
    sec
    .a16
    sbc #$0006
    sta a:$002B,X
    bra follow_linked_child_parent_variant_position_c25d7c
follow_linked_child_parent_variant_position_c25d72:
    lda a:$002B,Y
    clc
    .a16
    adc #$0006
    sta a:$002B,X
follow_linked_child_parent_variant_position_c25d7c:
    lda a:$0032,Y
    sec
    .a16
    sbc #$0020
    sta a:$0032,X
    rts
