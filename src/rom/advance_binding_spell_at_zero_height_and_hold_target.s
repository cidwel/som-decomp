; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-hold-child.md.
.setcpu "65816"
.smart
.a8
.i16

follow_spell_target_integer_position = $993D
mark_eligible_spell_target_control19 = $98F6
select_boss_animation_and_reset_frame_cursor = $1394
set_eligible_spell_target_status_and_timer = $9910

.segment "CODE"
.org $9F85
advance_binding_spell_at_zero_height_and_hold_target:
    ldx $87
    lda a:$0066,X
    bne advance_binding_spell_at_zero_height_and_hold_target_c29f95
    inc a:$0094,X
    .a16
    lda #$0127
    jsr select_boss_animation_and_reset_frame_cursor
advance_binding_spell_at_zero_height_and_hold_target_c29f95:
    jsr mark_eligible_spell_target_control19
    jsr set_eligible_spell_target_status_and_timer
    jsr follow_spell_target_integer_position
    clc
    rts
