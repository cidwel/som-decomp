; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-latent-scroll-flow.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FEAB
latent_tick_scrolling_dialogue_line_delay:
    lda a:$A20C
    dec
    .a8
    and #$01
    sta a:$A20C
    bne latent_tick_scrolling_dialogue_line_delay_c9fecc
    lda f:$000040
    inc
    sta f:$000040
    inc a:$A171
    lda a:$A171
    .a8
    and #$0F
    bne latent_tick_scrolling_dialogue_line_delay_c9fecc
    dec a:$A161
latent_tick_scrolling_dialogue_line_delay_c9fecc:
    rts
