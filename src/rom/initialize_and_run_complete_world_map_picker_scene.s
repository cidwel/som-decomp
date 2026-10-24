; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-composition.md.
.setcpu "65816"
.smart
.a8
.i16

blank_display_disable_interrupts_and_clear_windows_for_map_entry = $87C4
build_world_map_picker_row_geometry_with_hardware_division = $AAD2
clear_world_map_picker_image_and_prepare_matrix = $A615
construct_all_world_map_picker_image_rows = $AA14
initialize_world_map_picker_background_and_hdma_records = $A841
install_relocated_scene_row_rle_decoder = $9985
install_temporary_world_map_picker_nmi_vector = $A638
routine_02adee = $2ADEE
run_world_map_picker_vblank_input_and_redraw_loop = $A733

.segment "CODE"
.org $A5CC
initialize_and_run_complete_world_map_picker_scene:
    jsr blank_display_disable_interrupts_and_clear_windows_for_map_entry
    sep #$30
    lda a:$0100
    pha
    lda a:$0101
    pha
    lda a:$0102
    pha
    jsr initialize_world_map_picker_background_and_hdma_records
    jsl f:routine_02adee
    jsr install_relocated_scene_row_rle_decoder
    jsr build_world_map_picker_row_geometry_with_hardware_division
    rep #$20
    sep #$10
    lda $FA
    lsr
    lsr
    lsr
    sta $08
    lda $FC
    lsr
    lsr
    lsr
    sta $0A
    stz $1E
    jsr install_temporary_world_map_picker_nmi_vector
    rep #$20
    .a16
    lda #$0001
    stz $0E
    sta $0C
    sep #$20
    jsr clear_world_map_picker_image_and_prepare_matrix
    jsr construct_all_world_map_picker_image_rows
    jmp run_world_map_picker_vblank_input_and_redraw_loop
