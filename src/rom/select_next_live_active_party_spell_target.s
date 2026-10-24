; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-follow-child.md.
.setcpu "65816"
.smart
.a8
.i16

activate_spell_child_and_clear_fractional_height = $98DA
seed_follow_spell_animation_sound_position_and_control = $9AAF

.segment "CODE"
.org $9A74
select_next_live_active_party_spell_target:
select_next_live_active_party_spell_target_c29a74:
    ldx $87
    lda a:$00B8,X
    .a16
    bit #$0004
    beq select_next_live_active_party_spell_target_c29aad
    .a16
    cmp #$0007
    bcs select_next_live_active_party_spell_target_c29aad
    .a16
    and #$0003
    xba
    asl
    clc
    .a16
    adc #$E000
    sta a:$00B2,X
    inc a:$00B8,X
    tax
    lda a:$0000,X
    .a16
    cmp #$0001
    bne select_next_live_active_party_spell_target_c29a74
    lda a:$0190,X
    bmi select_next_live_active_party_spell_target_c29a74
    ldx $87
    stz a:$0096,X
    jsr activate_spell_child_and_clear_fractional_height
    jsr seed_follow_spell_animation_sound_position_and_control
    clc
    rts
select_next_live_active_party_spell_target_c29aad:
    sec
    rts
