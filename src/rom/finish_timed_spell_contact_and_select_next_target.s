; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-palette-child.md.
.setcpu "65816"
.smart
.a8
.i16

clear_spell_status_and_mark_reciprocal_contacts = $9FBD
select_next_live_active_party_spell_target = $9A74
set_eligible_spell_target_status_and_timer = $9910

.segment "CODE"
.org $9C74
finish_timed_spell_contact_and_select_next_target:
    ldx $87
    jsr set_eligible_spell_target_status_and_timer
    lda a:$0096,X
    .a16
    cmp #$000C
    bcc finish_timed_spell_contact_and_select_next_target_c29c92
    jsr clear_spell_status_and_mark_reciprocal_contacts
    ldx $87
    .a16
    lda #$9C93
    sta a:$0090,X
    stz a:$00BA,X
    jsr select_next_live_active_party_spell_target
finish_timed_spell_contact_and_select_next_target_c29c92:
    rts
