; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-party-map-contacts.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D42A
compare_two_packed_contact_hitboxes:
    sep #$20
    lda $12
    clc
    adc $16
    lsr
    sta $12
    lda $13
    clc
    adc $17
    lsr
    sta $13
    bit $06
    bmi compare_two_packed_contact_hitboxes_c1d449
    lda $10
    .a8
    eor #$FF
    sec
    adc $14
    bra compare_two_packed_contact_hitboxes_c1d450
compare_two_packed_contact_hitboxes_c1d449:
    lda $14
    .a8
    eor #$FF
    sec
    adc $10
compare_two_packed_contact_hitboxes_c1d450:
    bmi compare_two_packed_contact_hitboxes_c1d45a
    clc
    adc $0A
    cmp $12
    bcc compare_two_packed_contact_hitboxes_c1d466
compare_two_packed_contact_hitboxes_c1d459:
    rts
compare_two_packed_contact_hitboxes_c1d45a:
    clc
    adc $0A
    bpl compare_two_packed_contact_hitboxes_c1d462
    .a8
    eor #$FF
    inc
compare_two_packed_contact_hitboxes_c1d462:
    cmp $12
    bcs compare_two_packed_contact_hitboxes_c1d459
compare_two_packed_contact_hitboxes_c1d466:
    bit $07
    bmi compare_two_packed_contact_hitboxes_c1d473
    lda $11
    .a8
    eor #$FF
    sec
    adc $15
    bra compare_two_packed_contact_hitboxes_c1d47a
compare_two_packed_contact_hitboxes_c1d473:
    lda $15
    .a8
    eor #$FF
    sec
    adc $11
compare_two_packed_contact_hitboxes_c1d47a:
    bmi compare_two_packed_contact_hitboxes_c1d482
    clc
    adc $0B
    cmp $13
    rts
compare_two_packed_contact_hitboxes_c1d482:
    clc
    adc $0B
    bpl compare_two_packed_contact_hitboxes_c1d48a
    .a8
    eor #$FF
    inc
compare_two_packed_contact_hitboxes_c1d48a:
    cmp $13
    rts
