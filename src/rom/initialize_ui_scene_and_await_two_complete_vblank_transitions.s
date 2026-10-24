; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-entry-prefix.md.
.setcpu "65816"
.smart
.a8
.i16

blank_display_disable_interrupts_and_clear_windows_for_map_entry = $87C4
initialize_complete_ui_scene_constructor_and_row_publication = $82C4
routine_02b0d7 = $2B0D7

.segment "CODE"
.org $8038
initialize_ui_scene_and_await_two_complete_vblank_transitions:
    jsl f:routine_02b0d7
    rep #$10
    .i16
    ldx #$01FF
    txs
    jsr blank_display_disable_interrupts_and_clear_windows_for_map_entry
    jsr initialize_complete_ui_scene_constructor_and_row_publication
    sep #$30
    .a8
    lda #$07
    sta a:$2105
    .i8
    ldx #$02
initialize_ui_scene_and_await_two_complete_vblank_transitions_c08051:
    bit a:$4210
    bpl initialize_ui_scene_and_await_two_complete_vblank_transitions_c08051
initialize_ui_scene_and_await_two_complete_vblank_transitions_c08056:
    bit a:$4210
    bmi initialize_ui_scene_and_await_two_complete_vblank_transitions_c08056
    dex
    bne initialize_ui_scene_and_await_two_complete_vblank_transitions_c08051
    .i8
    ldx #$B1
    stx a:$4200
    cli
