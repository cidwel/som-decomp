; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-status-child.md.
.setcpu "65816"
.smart
.a8
.i16

resolve_single_or_three_spell_target_contacts = $9D38
set_status_single_or_three_spell_targets = $9CFA

.segment "CODE"
.org $9D26
finish_status_spell_child_after_three_ticks:
    ldx $87
    jsr set_status_single_or_three_spell_targets
    lda a:$0096,X
    .a16
    cmp #$0003
    bcc finish_status_spell_child_after_three_ticks_c29d37
    jsr resolve_single_or_three_spell_target_contacts
    sec
finish_status_spell_child_after_three_ticks_c29d37:
    rts
