; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eleven-children.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8E92
follow_descriptor_eleven_parent_position_minus_half_height:
    ldy a:$00B0,X
    lda a:$002B,Y
    sta a:$002B,X
    lda a:$0032,Y
    sta a:$0032,X
    lda a:$0066,Y
    lsr
    eor $C7
    inc
    clc
    adc a:$0032,X
    sta a:$0032,X
    rts
