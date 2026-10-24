; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eleven-children.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8E1A
follow_descriptor_eleven_parent_offset_position_and_height:
    ldy a:$00B0,X
    lda a:$002B,Y
    clc
    .a16
    adc #$0008
    sta a:$002B,X
    lda a:$0032,Y
    clc
    .a16
    adc #$0038
    sta a:$0032,X
    lda a:$0066,Y
    sta a:$0066,X
    rts
