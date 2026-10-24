; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-ten-children.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $7A09
propagate_predecessor_request_without_end_animation_reseed:
    ldx $87
    ldy a:$00B0,X
    lda a:$0082,X
    sta a:$0014,X
    lda a:$0080,X
    sta a:$0082,X
    lda a:$0082,Y
    sta a:$0080,X
    lda a:$0014,X
    .a16
    cmp #$FFFF
    bne propagate_predecessor_request_without_end_animation_reseed_c27a28
propagate_predecessor_request_without_end_animation_reseed_c27a28:
    rts
