; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-composition.md.
.setcpu "65816"
.smart
.a8
.i16

construct_all_world_map_picker_image_rows = $AA14
consume_complete_world_map_picker_rotation_motion_and_buttons = $A7D8
initialize_and_run_confirmed_world_map_survey_scene = $ABB3

.segment "CODE"
.org $A733
run_world_map_picker_vblank_input_and_redraw_loop:
    sep #$20
run_world_map_picker_vblank_input_and_redraw_loop_c0a735:
    lda a:$4210
    bpl run_world_map_picker_vblank_input_and_redraw_loop_c0a735
run_world_map_picker_vblank_input_and_redraw_loop_c0a73a:
    lda a:$4210
    bmi run_world_map_picker_vblank_input_and_redraw_loop_c0a73a
    .a8
    lda #$81
    sta a:$4200
run_world_map_picker_vblank_input_and_redraw_loop_c0a744:
    rep #$20
    sep #$30
run_world_map_picker_vblank_input_and_redraw_loop_c0a748:
    lda $0E
    bne run_world_map_picker_vblank_input_and_redraw_loop_c0a748
    lda $0C
    bne run_world_map_picker_vblank_input_and_redraw_loop_c0a748
run_world_map_picker_vblank_input_and_redraw_loop_c0a750:
    jsr consume_complete_world_map_picker_rotation_motion_and_buttons
    bcs run_world_map_picker_vblank_input_and_redraw_loop_c0a772
    sep #$20
    .a8
    cmp #$01
    bcs run_world_map_picker_vblank_input_and_redraw_loop_c0a76d
    .a8
    lda #$01
    bit $F4
    beq run_world_map_picker_vblank_input_and_redraw_loop_c0a767
run_world_map_picker_vblank_input_and_redraw_loop_c0a761:
    bit $F4
    bne run_world_map_picker_vblank_input_and_redraw_loop_c0a761
    bra run_world_map_picker_vblank_input_and_redraw_loop_c0a750
run_world_map_picker_vblank_input_and_redraw_loop_c0a767:
    bit $F4
    beq run_world_map_picker_vblank_input_and_redraw_loop_c0a767
    bra run_world_map_picker_vblank_input_and_redraw_loop_c0a750
run_world_map_picker_vblank_input_and_redraw_loop_c0a76d:
    jsr construct_all_world_map_picker_image_rows
    bra run_world_map_picker_vblank_input_and_redraw_loop_c0a744
run_world_map_picker_vblank_input_and_redraw_loop_c0a772:
    sep #$20
    .a8
    cmp #$01
    bcc run_world_map_picker_vblank_input_and_redraw_loop_c0a789
    sep #$20
    pla
    sta a:$0102
    pla
    sta a:$0101
    pla
    sta a:$0100
    jmp initialize_and_run_confirmed_world_map_survey_scene
run_world_map_picker_vblank_input_and_redraw_loop_c0a789:
    sep #$20
    pla
    sta a:$0102
    pla
    sta a:$0101
    pla
    sta a:$0100
    rts
