; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-latent-scroll-flow.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c9ffb7 = $FFB7

.segment "CODE"
.org $FE68
latent_begin_scrolling_dialogue_end_sequence:
    iny
    inc a:$A161
    stz a:$A171
    jsr routine_c9ffb7
    sec
    rts
