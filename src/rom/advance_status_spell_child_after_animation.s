; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-status-child.md.
.setcpu "65816"
.smart
.a8
.i16

mark_single_or_three_spell_targets_control19 = $9CCE
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $9CB6
advance_status_spell_child_after_animation:
    ldx $87
    lda a:$009E,X
    bne advance_status_spell_child_after_animation_c29ccc
    inc a:$0094,X
    stz a:$0096,X
    .a16
    lda #$0000
    jsr select_boss_animation_and_reset_frame_cursor
    jsr mark_single_or_three_spell_targets_control19
advance_status_spell_child_after_animation_c29ccc:
    clc
    rts
