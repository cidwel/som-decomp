; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-composition.md.
.setcpu "65816"
.smart
.a8
.i16

consume_world_map_survey_motion_and_page_boundaries = $AC95
initialize_and_run_complete_world_map_picker_scene = $A5CC
routine_02a852 = $2A852

.segment "CODE"
.org $AC5E
run_world_map_survey_input_cancel_and_reentry_loop:
run_world_map_survey_input_cancel_and_reentry_loop_c0ac5e:
    sep #$30
    .a8
    lda #$01
    sta $0E
run_world_map_survey_input_cancel_and_reentry_loop_c0ac64:
    bit $0E
    bne run_world_map_survey_input_cancel_and_reentry_loop_c0ac64
    jsl f:routine_02a852
    jsr consume_world_map_survey_motion_and_page_boundaries
    bcc run_world_map_survey_input_cancel_and_reentry_loop_c0ac5e
    .a8
    cmp #$00
    beq run_world_map_survey_input_cancel_and_reentry_loop_c0ac86
    sep #$20
    pla
    sta a:$0102
    pla
    sta a:$0101
    pla
    sta a:$0100
    jmp initialize_and_run_complete_world_map_picker_scene
run_world_map_survey_input_cancel_and_reentry_loop_c0ac86:
    sep #$20
    pla
    sta a:$0102
    pla
    sta a:$0101
    pla
    sta a:$0100
    rts
