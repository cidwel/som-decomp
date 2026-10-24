; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1226
integrate_boss_vertical_position_and_velocity:
    lda a:$00C4,X
    clc
    adc a:$0064,X
    sta a:$0064,X
    lda a:$00C6,X
    adc a:$0066,X
    sta a:$0066,X
    bpl integrate_boss_vertical_position_and_velocity_c21247
    stz a:$0064,X
    stz a:$0066,X
    stz a:$00C4,X
    stz a:$00C6,X
integrate_boss_vertical_position_and_velocity_c21247:
    lda a:$00C4,X
    clc
    adc a:$0FC0
    sta a:$00C4,X
    lda a:$00C6,X
    adc a:$0FC2
    sta a:$00C6,X
    rts
