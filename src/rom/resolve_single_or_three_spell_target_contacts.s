; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-status-child.md.
.setcpu "65816"
.smart
.a8
.i16

clear_spell_status_and_mark_reciprocal_contacts = $9FBD

.segment "CODE"
.org $9D38
resolve_single_or_three_spell_target_contacts:
    lda a:$00B8,X
    .a16
    bit #$0004
    bne resolve_single_or_three_spell_target_contacts_c29d44
    jsr clear_spell_status_and_mark_reciprocal_contacts
    rts
resolve_single_or_three_spell_target_contacts_c29d44:
    .a16
    lda #$E000
    sta a:$00B2,X
    jsr clear_spell_status_and_mark_reciprocal_contacts
    ldx $87
    .a16
    lda #$E200
    sta a:$00B2,X
    jsr clear_spell_status_and_mark_reciprocal_contacts
    ldx $87
    .a16
    lda #$E400
    sta a:$00B2,X
    jsr clear_spell_status_and_mark_reciprocal_contacts
    rts
