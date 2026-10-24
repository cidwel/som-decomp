; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $149E
set_boss_animation_vertical_orientation:
    ldx $87
    lda a:$0098,X
    .a16
    ora #$0080
    sta a:$0098,X
    rts
