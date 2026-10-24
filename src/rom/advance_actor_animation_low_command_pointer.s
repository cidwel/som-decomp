; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-animation-operands.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D5C0
advance_actor_animation_low_command_pointer:
    pha
    rep #$20
    lda $00
    inc
    sta $00
    sep #$20
    pla
