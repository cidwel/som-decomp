; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-hold-child.md.
.setcpu "65816"
.smart
.a8
.i16

clear_spell_status_and_mark_reciprocal_contacts = $9FBD
select_next_live_active_party_spell_target = $9A74
set_eligible_spell_target_status_and_timer = $9910

.segment "CODE"
.org $9F26
hold_spell_status_until_animation_then_select_next_target:
    ldx $87
    jsr set_eligible_spell_target_status_and_timer
    lda a:$009E,X
    bne hold_spell_status_until_animation_then_select_next_target_c29f3b
    jsr clear_spell_status_and_mark_reciprocal_contacts
    ldx $87
    stz a:$00BA,X
    jsr select_next_live_active_party_spell_target
hold_spell_status_until_animation_then_select_next_target_c29f3b:
    rts
