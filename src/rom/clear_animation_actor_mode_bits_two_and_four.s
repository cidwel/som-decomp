; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1A12
clear_animation_actor_mode_bits_two_and_four:
    ldx $87
    lda a:$0070,X
    .a16
    and #$FFF9
    sta a:$0070,X
    rts
