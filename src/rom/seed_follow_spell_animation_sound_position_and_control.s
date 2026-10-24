; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-follow-child.md.
.setcpu "65816"
.smart
.a8
.i16

follow_spell_target_integer_position = $993D
mark_eligible_spell_target_control19 = $98F6
request_follow_spell_target_sound = $9AD1
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $9AAF
seed_follow_spell_animation_sound_position_and_control:
    ldx $87
    lda a:$00B4,X
    asl
    tax
    lda f:$DCE73D,X
    ldx $87
    jsr select_boss_animation_and_reset_frame_cursor
    jsr request_follow_spell_target_sound
    jsr follow_spell_target_integer_position
    lda a:$00B6,X
    sta a:$00BC,X
    jsr mark_eligible_spell_target_control19
    ldx $87
    rts
