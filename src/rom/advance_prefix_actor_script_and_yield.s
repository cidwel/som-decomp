; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-program-prefix-copies.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0091
advance_prefix_actor_script_and_yield:
    rep #$20
    .a16
    and #$00FF
    clc
    adc a:$0144,Y
    sta a:$0144,Y
    .a16
    lda #$0000
    rts
