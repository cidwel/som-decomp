; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1A34
set_animation_actor_field_88:
    lda [$76],Y
    ldx $87
    sta a:$0088,X
    iny
    iny
    rts
