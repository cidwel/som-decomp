; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-exit.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_and_run_complete_world_map_picker_scene = $A5CC
request_native_ui_scene_window_or_confirm_transition = $87A2
return_after_ui_scene_button_dispatch = $87A1
routine_02b091 = $2B091
routine_c0803c = $803C

.segment "CODE"
.org $8779
consume_ui_scene_buttons_and_restart_after_world_map_picker:
    sep #$30
    .a8
    lda #$10
    .a8
    ora #$20
    trb $CC
    beq consume_ui_scene_buttons_and_restart_after_world_map_picker_c0878a
    bit $BE
    bmi consume_ui_scene_buttons_and_restart_after_world_map_picker_c0878a
    jsr request_native_ui_scene_window_or_confirm_transition
consume_ui_scene_buttons_and_restart_after_world_map_picker_c0878a:
    .a8
    lda #$02
    trb $CC
    beq consume_ui_scene_buttons_and_restart_after_world_map_picker_c08790
consume_ui_scene_buttons_and_restart_after_world_map_picker_c08790:
    .a8
    lda #$01
    trb $CC
    beq return_after_ui_scene_button_dispatch
    jsr initialize_and_run_complete_world_map_picker_scene
    jsl f:routine_02b091
    jmp routine_c0803c
