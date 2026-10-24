; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-latent-scroll-flow.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FE62
latent_reset_scrolling_dialogue_line_delay:
    iny
    stz a:$A171
    clc
    rts
