; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-composition.md.
.setcpu "65816"
.smart
.a8
.i16

poll_selected_hero_controller_and_restore_ui_input_word = $87E0
routine_c0adf0 = $ADF0
switch_world_map_survey_visible_vram_page_and_scroll = $ADE3

.segment "CODE"
.org $AC95
consume_world_map_survey_motion_and_page_boundaries:
    jsr poll_selected_hero_controller_and_restore_ui_input_word
    sep #$30
    .a8
    lda #$20
    trb $CC
    beq consume_world_map_survey_motion_and_page_boundaries_c0aca4
    .a8
    lda #$01
    sec
    rts
consume_world_map_survey_motion_and_page_boundaries_c0aca4:
    .a8
    lda #$08
    trb $CC
    beq consume_world_map_survey_motion_and_page_boundaries_c0acae
    .a8
    lda #$00
    sec
    rts
consume_world_map_survey_motion_and_page_boundaries_c0acae:
    lda $43
    .a8
    and #$03
    beq consume_world_map_survey_motion_and_page_boundaries_c0accc
    lsr
    rep #$20
    bcc consume_world_map_survey_motion_and_page_boundaries_c0acc1
    lda $08
    clc
    .a16
    adc #$0004
    bra consume_world_map_survey_motion_and_page_boundaries_c0acc7
consume_world_map_survey_motion_and_page_boundaries_c0acc1:
    lda $08
    sec
    .a16
    sbc #$0004
consume_world_map_survey_motion_and_page_boundaries_c0acc7:
    .a16
    and #$01FC
    sta $08
consume_world_map_survey_motion_and_page_boundaries_c0accc:
    sep #$30
    lda $43
    .a8
    and #$0C
    bne consume_world_map_survey_motion_and_page_boundaries_c0acd6
    clc
    rts
consume_world_map_survey_motion_and_page_boundaries_c0acd6:
    .a8
    bit #$04
    rep #$20
    bne consume_world_map_survey_motion_and_page_boundaries_c0acfb
    lda $0A
    sec
    .a16
    sbc #$0004
    .a16
    and #$01FC
    sta $0A
    .a16
    cmp #$01FC
    beq consume_world_map_survey_motion_and_page_boundaries_c0ad12
    .a16
    cmp #$0080
    bne consume_world_map_survey_motion_and_page_boundaries_c0acf9
    lda $15
    lsr
    bcc consume_world_map_survey_motion_and_page_boundaries_c0acf9
consume_world_map_survey_motion_and_page_boundaries_c0acf6:
    jsr routine_c0adf0
consume_world_map_survey_motion_and_page_boundaries_c0acf9:
    clc
    rts
consume_world_map_survey_motion_and_page_boundaries_c0acfb:
    lda $0A
    clc
    .a16
    adc #$0004
    .a16
    and #$01FC
    sta $0A
    beq consume_world_map_survey_motion_and_page_boundaries_c0acf6
    .a16
    cmp #$0180
    bne consume_world_map_survey_motion_and_page_boundaries_c0ad15
    lda $15
    lsr
    bcs consume_world_map_survey_motion_and_page_boundaries_c0acf9
consume_world_map_survey_motion_and_page_boundaries_c0ad12:
    jsr switch_world_map_survey_visible_vram_page_and_scroll
consume_world_map_survey_motion_and_page_boundaries_c0ad15:
    clc
    rts
