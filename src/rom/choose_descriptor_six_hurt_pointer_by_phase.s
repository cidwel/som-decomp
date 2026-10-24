; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-six.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $42D3
choose_descriptor_six_hurt_pointer_by_phase:
    lda a:$007E,X
    bne choose_descriptor_six_hurt_pointer_by_phase_c242dc
    .a16
    lda #$D46D
    rts
choose_descriptor_six_hurt_pointer_by_phase_c242dc:
    .a16
    lda #$D46F
    rts
