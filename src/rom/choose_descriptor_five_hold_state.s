; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-five.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $60B7
choose_descriptor_five_hold_state:
    .a16
    lda #$DD77
    rts
