; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-effect-scripts.md.
.setcpu "65816"
.smart
.a8
.i16

consume_native_visual_frame_script_pose_or_terminator = $8276
restore_actor_weapon_after_cast = $8DAB
restore_target_state_after_previous_cast = $81F2
routine_01e76d = $1E76D

.segment "CODE"
.org $81AF
advance_and_finish_native_motion_effect_frame_script:
    lda a:$E110,X
    .a8
    cmp #$05
    bne advance_and_finish_native_motion_effect_frame_script_c181bc
    lda a:$E114,X
    beq advance_and_finish_native_motion_effect_frame_script_c181bc
    rts
advance_and_finish_native_motion_effect_frame_script_c181bc:
    jsr consume_native_visual_frame_script_pose_or_terminator
    bcs advance_and_finish_native_motion_effect_frame_script_c181c2
    rts
advance_and_finish_native_motion_effect_frame_script_c181c2:
    sep #$20
    lda a:$E121,X
    pha
    stz a:$E060,X
    stz a:$E00C,X
    stz a:$E084,X
    txy
    jsr restore_target_state_after_previous_cast
    jsr restore_actor_weapon_after_cast
    sep #$20
    pla
    .a8
    cmp #$06
    bne advance_and_finish_native_motion_effect_frame_script_c181f1
    rep #$20
    lda a:$0108
    beq advance_and_finish_native_motion_effect_frame_script_c181ed
    .a16
    ora #$0800
    jsl f:routine_01e76d
advance_and_finish_native_motion_effect_frame_script_c181ed:
    sep #$20
    stz $E0
advance_and_finish_native_motion_effect_frame_script_c181f1:
    rts
