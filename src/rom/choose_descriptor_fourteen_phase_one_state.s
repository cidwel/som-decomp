; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-fourteen.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $51C9
choose_descriptor_fourteen_phase_one_state:
    .a16
    lda #$D900
    rts
