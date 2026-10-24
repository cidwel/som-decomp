; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $17E7
jump_animation_stream_absolute:
    ldx $87
    lda [$76],Y
    tay
    sta a:$009C,X
    rts
