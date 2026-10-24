; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-effect-scripts.md.
.setcpu "65816"
.smart
.a8
.i16

advance_native_homing_cast_cell_and_deliver_target = $894D
advance_native_homing_cell_phase_history_and_shared_delivery_tail = $8B26
consume_native_visual_frame_script_pose_or_terminator = $8276

.segment "CODE"
.org $824E
advance_native_cell_cast_frame_script_and_homing_cell:
advance_native_cell_cast_frame_script_and_homing_cell_c1824e:
    jsr consume_native_visual_frame_script_pose_or_terminator
    bcs advance_native_cell_cast_frame_script_and_homing_cell_c1825e
    lda a:$E110,X
    .a8
    cmp #$04
    bne advance_native_cell_cast_frame_script_and_homing_cell_c1825d
    brl advance_native_homing_cell_phase_history_and_shared_delivery_tail
advance_native_cell_cast_frame_script_and_homing_cell_c1825d:
    rts
advance_native_cell_cast_frame_script_and_homing_cell_c1825e:
    rep #$20
    lda a:$E0FE,X
    sta a:$E0FC,X
    sep #$20
    lda a:$E110,X
    .a8
    cmp #$04
    bne advance_native_cell_cast_frame_script_and_homing_cell_c1824e
    jsr advance_native_homing_cast_cell_and_deliver_target
    sep #$20
    bra advance_native_cell_cast_frame_script_and_homing_cell_c1824e
