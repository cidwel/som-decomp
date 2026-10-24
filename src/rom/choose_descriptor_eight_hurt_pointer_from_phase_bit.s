; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eight.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6EBA
choose_descriptor_eight_hurt_pointer_from_phase_bit:
    lda a:$007E,X
    .a16
    bit #$0001
    bne choose_descriptor_eight_hurt_pointer_from_phase_bit_c26ec6
    .a16
    lda #$E84A
    rts
choose_descriptor_eight_hurt_pointer_from_phase_bit_c26ec6:
    .a16
    lda #$E84C
    rts
