; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-two-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4143
follow_descriptor_two_parent_position_and_depth_minus_eight:
    ldy a:$00B0,X
    lda a:$002B,Y
    sta a:$002B,X
    lda a:$0032,Y
    sta a:$0032,X
    lda a:$0022,Y
    sec
    .a16
    sbc #$0008
    sta a:$0022,X
    rts
