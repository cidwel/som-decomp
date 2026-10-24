; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-latent-scroll-registers.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FF05
finish_latent_scrolling_dialogue_register_state:
    stz a:$A170
    stz a:$A161
    .a8
    lda #$00
    sta f:$001D11
    sta f:$000040
    rep #$20
    .a16
    lda #$0536
    sta f:$001D1A
    sep #$20
    rts
