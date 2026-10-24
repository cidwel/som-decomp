; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-two.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4083
choose_descriptor_two_hurt_pointer_by_phase:
    lda a:$007E,X
    bne choose_descriptor_two_hurt_pointer_by_phase_c2408c
    .a16
    lda #$D226
    rts
choose_descriptor_two_hurt_pointer_by_phase_c2408c:
    .a16
    lda #$D228
    rts
