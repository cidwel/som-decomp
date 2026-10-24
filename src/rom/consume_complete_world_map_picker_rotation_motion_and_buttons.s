; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-composition.md.
.setcpu "65816"
.smart
.a8
.i16

poll_selected_hero_controller_and_restore_ui_input_word = $87E0
prepare_world_map_picker_scaled_matrix_coefficients = $A9E1
routine_c083e7 = $83E7
routine_c08700 = $8700

.segment "CODE"
.org $A7D8
consume_complete_world_map_picker_rotation_motion_and_buttons:
    jsr poll_selected_hero_controller_and_restore_ui_input_word
    sep #$30
    .a8
    lda #$10
    trb $CC
    beq consume_complete_world_map_picker_rotation_motion_and_buttons_c0a7e7
    .a8
    lda #$01
    sec
    rts
consume_complete_world_map_picker_rotation_motion_and_buttons_c0a7e7:
    .a8
    lda #$08
    trb $CC
    beq consume_complete_world_map_picker_rotation_motion_and_buttons_c0a7f1
    .a8
    lda #$00
    sec
    rts
consume_complete_world_map_picker_rotation_motion_and_buttons_c0a7f1:
    lda $43
    .a8
    and #$03
    beq consume_complete_world_map_picker_rotation_motion_and_buttons_c0a803
    lda $1F
    bne consume_complete_world_map_picker_rotation_motion_and_buttons_c0a803
    inc $1F
    jsr routine_c083e7
    jsr prepare_world_map_picker_scaled_matrix_coefficients
consume_complete_world_map_picker_rotation_motion_and_buttons_c0a803:
    sep #$30
    lda $43
    .a8
    and #$0C
    bne consume_complete_world_map_picker_rotation_motion_and_buttons_c0a80d
    clc
    rts
consume_complete_world_map_picker_rotation_motion_and_buttons_c0a80d:
    .i8
    ldx #$0B
    stx $5E
    jsr routine_c08700
    sep #$30
    lda $43
    .a8
    and #$04
    rep #$20
    beq consume_complete_world_map_picker_rotation_motion_and_buttons_c0a82e
    lda $0A
    clc
    adc $68
    sta $0A
    lda $08
    clc
    adc $66
    sta $08
    bra consume_complete_world_map_picker_rotation_motion_and_buttons_c0a83c
consume_complete_world_map_picker_rotation_motion_and_buttons_c0a82e:
    lda $0A
    sec
    sbc $68
    sta $0A
    lda $08
    sec
    sbc $66
    sta $08
consume_complete_world_map_picker_rotation_motion_and_buttons_c0a83c:
    .a16
    lda #$0001
    clc
    rts
