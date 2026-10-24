; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3182
follow_boss_parent_position_callback:
    lda a:$00B0,X
    tay
    lda a:$002B,Y
    sta a:$002B,X
    lda a:$0032,Y
    clc
    adc a:$00A5,Y
    sta a:$0032,X
    rts
