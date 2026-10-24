; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-three.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $62B8
initialize_descriptor_three_control_and_phase:
    .a16
    lda #$0001
    sta a:$007A,X
    stz a:$007E,X
    rts
