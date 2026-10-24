; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-status-child.md.
.setcpu "65816"
.smart
.a8
.i16

set_eligible_spell_target_status_and_timer = $9910

.segment "CODE"
.org $9CFA
set_status_single_or_three_spell_targets:
    lda a:$00B8,X
    .a16
    bit #$0004
    bne set_status_single_or_three_spell_targets_c29d06
    jsr set_eligible_spell_target_status_and_timer
    rts
set_status_single_or_three_spell_targets_c29d06:
    .a16
    lda #$E000
    sta a:$00B2,X
    jsr set_eligible_spell_target_status_and_timer
    ldx $87
    .a16
    lda #$E200
    sta a:$00B2,X
    jsr set_eligible_spell_target_status_and_timer
    ldx $87
    .a16
    lda #$E400
    sta a:$00B2,X
    jsr set_eligible_spell_target_status_and_timer
    rts
