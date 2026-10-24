; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1A2A
set_animation_actor_field_22:
    lda [$76],Y
    iny
    iny
    ldx $87
    sta a:$0022,X
    rts
