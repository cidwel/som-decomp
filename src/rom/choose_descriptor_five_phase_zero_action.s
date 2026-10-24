; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-five.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $60C9
choose_descriptor_five_phase_zero_action:
    .a16
    lda #$DD82
    clc
    rts
