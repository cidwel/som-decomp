; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1462
toggle_boss_animation_horizontal_orientation:
    ldx $87
    lda a:$0098,X
    .a16
    eor #$0040
    sta a:$0098,X
    rts
