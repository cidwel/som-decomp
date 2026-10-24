; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1827
set_animation_actor_byte_a2:
    ldx $87
    lda [$76],Y
    iny
    sep #$20
    sta a:$00A2,X
    rep #$20
    rts
