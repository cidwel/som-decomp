; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-fourteen-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $539F
follow_descriptor_fourteen_parent_position_depth_and_height:
    ldy a:$00B0,X
    lda a:$0032,Y
    clc
    .a16
    adc #$0028
    sta a:$0032,X
    lda a:$002B,Y
    sta a:$002B,X
    lda a:$0066,Y
    clc
    .a16
    adc #$0050
    sta a:$0066,X
    rts
