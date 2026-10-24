; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-composition.md.
.setcpu "65816"
.smart
.a8
.i16

blank_display_disable_interrupts_and_clear_windows_for_map_entry = $87C4
construct_and_save_both_world_map_survey_vram_pages = $AFAE
initialize_complete_world_map_survey_background_and_color_planes = $AD17
install_relocated_scene_row_rle_decoder = $9985
install_world_map_survey_temporary_nmi_vector = $AC14
routine_02adee = $2ADEE
run_world_map_survey_input_cancel_and_reentry_loop = $AC5E
switch_world_map_survey_visible_vram_page_and_scroll = $ADE3

.segment "CODE"
.org $ABB3
initialize_and_run_confirmed_world_map_survey_scene:
    jsr blank_display_disable_interrupts_and_clear_windows_for_map_entry
    sep #$30
    lda a:$0100
    pha
    lda a:$0101
    pha
    lda a:$0102
    pha
    jsr initialize_complete_world_map_survey_background_and_color_planes
    jsl f:routine_02adee
    jsr install_relocated_scene_row_rle_decoder
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
    jsr install_world_map_survey_temporary_nmi_vector
    rep #$20
    .a16
    lda #$0F00
    sta $0C
    stz $0E
    sep #$20
initialize_and_run_confirmed_world_map_survey_scene_c0abf0:
    lda a:$4210
    bpl initialize_and_run_confirmed_world_map_survey_scene_c0abf0
initialize_and_run_confirmed_world_map_survey_scene_c0abf5:
    lda a:$4210
    bmi initialize_and_run_confirmed_world_map_survey_scene_c0abf5
    .a8
    lda #$81
    sta a:$4200
    jsr construct_and_save_both_world_map_survey_vram_pages
    rep #$20
    lda $0A
    .a16
    and #$01FE
    .a16
    cmp #$0180
    bcc initialize_and_run_confirmed_world_map_survey_scene_c0ac11
    jsr switch_world_map_survey_visible_vram_page_and_scroll
initialize_and_run_confirmed_world_map_survey_scene_c0ac11:
    jmp run_world_map_survey_input_cancel_and_reentry_loop
