; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-status-child.md.
.setcpu "65816"
.smart
.a8
.i16

mark_eligible_spell_target_control19 = $98F6

.segment "CODE"
.org $9CCE
mark_single_or_three_spell_targets_control19:
    lda a:$00B8,X
    .a16
    bit #$0004
    bne mark_single_or_three_spell_targets_control19_c29cda
    jsr mark_eligible_spell_target_control19
    rts
mark_single_or_three_spell_targets_control19_c29cda:
    .a16
    lda #$E000
    sta a:$00B2,X
    jsr mark_eligible_spell_target_control19
    ldx $87
    .a16
    lda #$E200
    sta a:$00B2,X
    jsr mark_eligible_spell_target_control19
    ldx $87
    .a16
    lda #$E400
    sta a:$00B2,X
    jsr mark_eligible_spell_target_control19
    rts
