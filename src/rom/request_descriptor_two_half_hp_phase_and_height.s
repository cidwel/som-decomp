; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-two.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3FB5
request_descriptor_two_half_hp_phase_and_height:
    lda a:$0184,X
    lsr
    cmp a:$0182,X
    bcc request_descriptor_two_half_hp_phase_and_height_c23fd8
    .a16
    lda #$0008
    sta a:$007E,X
    lda a:$0042,X
    bne request_descriptor_two_half_hp_phase_and_height_c23fd1
    .a16
    lda #$0020
    sta a:$0066,X
    bra request_descriptor_two_half_hp_phase_and_height_c23fd7
request_descriptor_two_half_hp_phase_and_height_c23fd1:
    .a16
    lda #$0020
    sta a:$0066,X
request_descriptor_two_half_hp_phase_and_height_c23fd7:
    sec
request_descriptor_two_half_hp_phase_and_height_c23fd8:
    rts
