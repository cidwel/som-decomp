; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-latent-scroll-flow.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c9fecc = $FECC
routine_c9ffb7 = $FFB7
routine_c9ffce = $FFCE

.segment "CODE"
.org $FECD
latent_tick_scrolling_dialogue_final_ring_clear:
    lda a:$A20C
    dec
    .a8
    and #$01
    sta a:$A20C
    bne latent_tick_scrolling_dialogue_final_ring_clear_c9ff04
    lda f:$000040
    inc
    sta f:$000040
    inc a:$A171
    lda a:$A171
    pha
    .a8
    and #$0F
    bne latent_tick_scrolling_dialogue_final_ring_clear_c9fefc
    jsr routine_c9ffce
    jsr routine_c9ffb7
    lda f:$001D04
    .a8
    ora #$44
    sta f:$001D04
latent_tick_scrolling_dialogue_final_ring_clear_c9fefc:
    pla
    .a8
    cmp #$00
    bne routine_c9fecc
    inc a:$A161
latent_tick_scrolling_dialogue_final_ring_clear_c9ff04:
    rts
