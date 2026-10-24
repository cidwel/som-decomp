; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-five.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6170
choose_descriptor_five_phase_two_action:
    .a16
    lda #$DD60
    clc
    rts
