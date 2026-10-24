; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-follow-child.md.
.setcpu "65816"
.smart
.a8
.i16

clear_spell_status_and_mark_reciprocal_contacts = $9FBD
select_next_live_active_party_spell_target = $9A74
set_eligible_spell_target_status_and_timer = $9910

.segment "CODE"
.org $9A54
apply_follow_spell_status_and_advance_targets:
    ldx $87
    jsr set_eligible_spell_target_status_and_timer
    lda a:$009E,X
    bne apply_follow_spell_status_and_advance_targets_c29a65
    jsr clear_spell_status_and_mark_reciprocal_contacts
    jsr select_next_live_active_party_spell_target
    rts
apply_follow_spell_status_and_advance_targets_c29a65:
    clc
    rts
