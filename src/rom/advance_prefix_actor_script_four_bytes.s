; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-program-prefix-copies.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $00CB
advance_prefix_actor_script_four_bytes:
    rep #$20
    lda a:$0144,Y
    clc
    .a16
    adc #$0004
    sta a:$0144,Y
    .a16
    lda #$FFFF
    rts
