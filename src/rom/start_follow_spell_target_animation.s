; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-follow-child.md.
.setcpu "65816"
.smart
.a8
.i16

activate_spell_child_and_clear_fractional_height = $98DA
seed_follow_spell_animation_sound_position_and_control = $9AAF

.segment "CODE"
.org $9A67
start_follow_spell_target_animation:
    inc a:$00B8,X
    stz a:$0096,X
    jsr activate_spell_child_and_clear_fractional_height
    jsr seed_follow_spell_animation_sound_position_and_control
    rts
