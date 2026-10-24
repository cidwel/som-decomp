; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $F390
reset_actor_event_animation_and_motion:
    rep #$20
    txa
    xba
    asl
    asl
    asl
    tay
    .a16
    lda #$0000
    sta a:$0A50,Y
    sta a:$0A52,Y
    sta a:$0A53,Y
    sta a:$E01A,X
    .a16
    lda #$2817
    sta a:$0A56,Y
    sep #$20
    .a8
    lda #$00
    sta a:$E041,X
    sta a:$E01C,X
    sta a:$E01D,X
    sta a:$E011,X
    sta a:$E013,X
    .a8
    lda #$FF
    sta a:$E030,X
    stz a:$E063,X
    rts
