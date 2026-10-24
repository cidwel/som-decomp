; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-pull-child.md.
.setcpu "65816"
.smart
.a8
.i16

move_party_target_toward_parent_offset_with_fixed_point_vector = $9E6F
release_eligible_pull_target_control24 = $9E55
select_boss_animation_and_reset_frame_cursor = $1394
set_eligible_spell_target_status_and_timer = $9910

.segment "CODE"
.org $9DDF
pull_spell_target_and_test_lifetime_or_parent_offset:
    ldx $87
    jsr set_eligible_spell_target_status_and_timer
    jsr move_party_target_toward_parent_offset_with_fixed_point_vector
    lda a:$0096,X
    .a16
    cmp #$003C
    bcs pull_spell_target_and_test_lifetime_or_parent_offset_c29e34
    lda a:$00BE,X
    bne pull_spell_target_and_test_lifetime_or_parent_offset_c29e15
    ldy a:$00B2,X
    lda a:$00B0,X
    tax
    lda a:$0004,Y
    sec
    .a16
    sbc #$0028
    cmp a:$0032,X
    bcc pull_spell_target_and_test_lifetime_or_parent_offset_c29e34
    lda a:$0002,Y
    clc
    .a16
    adc #$0050
    cmp a:$002B,X
    bcc pull_spell_target_and_test_lifetime_or_parent_offset_c29e34
    bra pull_spell_target_and_test_lifetime_or_parent_offset_c29e42
pull_spell_target_and_test_lifetime_or_parent_offset_c29e15:
    ldy a:$00B2,X
    lda a:$00B0,X
    tax
    lda a:$0004,Y
    sec
    .a16
    sbc #$0028
    cmp a:$0032,X
    bcc pull_spell_target_and_test_lifetime_or_parent_offset_c29e34
    lda a:$0002,Y
    sec
    .a16
    sbc #$0050
    cmp a:$002B,X
    bcc pull_spell_target_and_test_lifetime_or_parent_offset_c29e42
pull_spell_target_and_test_lifetime_or_parent_offset_c29e34:
    ldx $87
    .a16
    lda #$0124
    jsr select_boss_animation_and_reset_frame_cursor
    inc a:$0094,X
    jsr release_eligible_pull_target_control24
pull_spell_target_and_test_lifetime_or_parent_offset_c29e42:
    clc
    rts
