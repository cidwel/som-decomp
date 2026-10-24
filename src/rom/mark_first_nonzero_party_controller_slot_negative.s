; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-death-dependencies.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0C1B
mark_first_nonzero_party_controller_slot_negative:
    sep #$30
    .i8
    ldx #$00
mark_first_nonzero_party_controller_slot_negative_c20c1f:
    lda a:$00D9,X
    beq mark_first_nonzero_party_controller_slot_negative_c20c2b
    .a8
    ora #$80
    sta a:$00D9,X
    bra mark_first_nonzero_party_controller_slot_negative_c20c30
mark_first_nonzero_party_controller_slot_negative_c20c2b:
    inx
    .i8
    cpx #$03
    bcc mark_first_nonzero_party_controller_slot_negative_c20c1f
mark_first_nonzero_party_controller_slot_negative_c20c30:
    rep #$30
    rts
