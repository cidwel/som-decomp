; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-cast.md.
.setcpu "65816"
.smart
.a8
.i16

choose_native54_hp_target_conditioned_spell_and_execute_success = $4812
publish_native54_cast_pose_sine_oscillator_and_auxiliary_control = $4865
test_native54_negative_status_or_begin_hurt_shift = $4965

.segment "CODE"
.org $47D2
advance_native54_cast_pose_and_recover_after_spell_attempt:
    ldx $87
    jsr test_native54_negative_status_or_begin_hurt_shift
    bcs advance_native54_cast_pose_and_recover_after_spell_attempt_c24810
    lda a:$0096,X
    .a16
    cmp #$0018
    bcc advance_native54_cast_pose_and_recover_after_spell_attempt_c2480d
    jsr choose_native54_hp_target_conditioned_spell_and_execute_success
    ldx $87
    .a16
    lda #$000C
    sta a:$0094,X
    stz a:$0096,X
    lda $89
    sec
    .a16
    sbc #$F800
    tay
    sep #$20
    lda a:$007A,X
    sta a:$F811,Y
    lda a:$007B,X
    sta a:$F80D,Y
    .a8
    lda #$40
    sta a:$F813,Y
    rep #$20
    clc
    rts
advance_native54_cast_pose_and_recover_after_spell_attempt_c2480d:
    jsr publish_native54_cast_pose_sine_oscillator_and_auxiliary_control
advance_native54_cast_pose_and_recover_after_spell_attempt_c24810:
    clc
    rts
