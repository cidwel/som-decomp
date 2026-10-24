; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $17F0
set_animation_relative_actor_parent:
    lda [$76],Y
    clc
    adc $87
    tax
    iny
    iny
    lda [$76],Y
    sta a:$00B0,X
    iny
    iny
    ldx $87
    rts
