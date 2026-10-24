; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1834
rewind_animation_stream:
    ldx $87
    .i16
    ldy #$0000
    rts
