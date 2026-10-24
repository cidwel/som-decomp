; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $147A
clear_boss_animation_horizontal_orientation:
    ldx $87
    lda a:$0098,X
    .a16
    and #$FFBF
    sta a:$0098,X
    rts
