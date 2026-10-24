; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-effect-scripts.md.
.setcpu "65816"
.smart
.a8
.i16

consume_native_visual_frame_script_pose_or_terminator = $8276
execute_ordinary_actor_cast_presentation = $8775

.segment "CODE"
.org $8245
advance_and_finish_native_ordinary_cast_frame_script:
    jsr consume_native_visual_frame_script_pose_or_terminator
    bcs advance_and_finish_native_ordinary_cast_frame_script_c1824b
    rts
advance_and_finish_native_ordinary_cast_frame_script_c1824b:
    jmp execute_ordinary_actor_cast_presentation
