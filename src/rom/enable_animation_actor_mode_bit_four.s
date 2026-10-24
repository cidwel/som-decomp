; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1A06
enable_animation_actor_mode_bit_four:
    ldx $87
    lda a:$0070,X
    .a16
    ora #$0004
    sta a:$0070,X
    rts
