; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-one.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4330
request_descriptor_one_phase_eight_at_half_hp:
    lda a:$0184,X
    lsr
    cmp a:$0182,X
    bcc request_descriptor_one_phase_eight_at_half_hp_c24340
    .a16
    lda #$0008
    sta a:$007E,X
    sec
request_descriptor_one_phase_eight_at_half_hp_c24340:
    rts
