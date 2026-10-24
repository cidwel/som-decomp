; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-program-prefix-copies.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $00A1
advance_prefix_actor_script_one_byte:
    rep #$20
    tyx
    inc a:$0144,X
    .a16
    lda #$FFFF
    rts
