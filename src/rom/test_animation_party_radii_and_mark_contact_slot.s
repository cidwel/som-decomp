; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $17A9
test_animation_party_radii_and_mark_contact_slot:
    lda $46
    sec
    sbc $56
    bpl test_animation_party_radii_and_mark_contact_slot_c217b4
    .a16
    eor #$FFFF
    inc
test_animation_party_radii_and_mark_contact_slot_c217b4:
    sta $52
    lda $48
    clc
    adc $58
    cmp $52
    bcc test_animation_party_radii_and_mark_contact_slot_c217e3
    lda $4E
    sec
    sbc $5E
    bpl test_animation_party_radii_and_mark_contact_slot_c217ca
    .a16
    eor #$FFFF
    inc
test_animation_party_radii_and_mark_contact_slot_c217ca:
    sta $52
    lda $50
    clc
    adc $60
    cmp $52
    bcc test_animation_party_radii_and_mark_contact_slot_c217e3
    ldx $87
    tya
    asl
    asl
    asl
    asl
    ora a:$005B,X
    sta a:$005B,X
    sec
test_animation_party_radii_and_mark_contact_slot_c217e3:
    rts
