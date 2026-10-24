; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-navigation.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c08455 = $8455

.segment "CODE"
.org $83E7
advance_ui_horizontal_rotation_and_attribute_windows:
    sep #$30
    lda $43
    .a8
    and #$03
    beq advance_ui_horizontal_rotation_and_attribute_windows_c08435
    sta $3C
    .i8
    ldy #$04
    ldx $5F
    .i8
    cpx #$04
    bne advance_ui_horizontal_rotation_and_attribute_windows_c083fb
    .i8
    ldy #$02
advance_ui_horizontal_rotation_and_attribute_windows_c083fb:
    ldx $3D
    bne advance_ui_horizontal_rotation_and_attribute_windows_c08403
    .i8
    ldx #$08
    stx $3D
advance_ui_horizontal_rotation_and_attribute_windows_c08403:
    .a8
    and #$01
    rep #$20
    bne advance_ui_horizontal_rotation_and_attribute_windows_c0841d
    tya
    clc
    adc $F6
    .a16
    and #$03FF
    sta $F6
    .i8
    ldx #$00
    jsr routine_c08455
    .i8
    ldx #$80
    stx $7A
    bra advance_ui_horizontal_rotation_and_attribute_windows_c08434
advance_ui_horizontal_rotation_and_attribute_windows_c0841d:
    tya
    .a16
    eor #$FFFF
    sec
    adc $F6
    .a16
    and #$03FF
    sta $F6
    sty $01
    .i8
    ldx #$20
    jsr routine_c08455
    .i8
    ldx #$01
    stx $7A
advance_ui_horizontal_rotation_and_attribute_windows_c08434:
    rts
advance_ui_horizontal_rotation_and_attribute_windows_c08435:
    .a8
    lda #$00
    sta $7A
    lda $3D
    beq advance_ui_horizontal_rotation_and_attribute_windows_c08454
    lda $3C
    clc
    .a8
    adc #$08
    sta $3C
    and $3D
    beq advance_ui_horizontal_rotation_and_attribute_windows_c08454
    asl $3D
    bit $F2
    bmi advance_ui_horizontal_rotation_and_attribute_windows_c08454
    lda $3C
    .i8
    ldy #$02
    bra advance_ui_horizontal_rotation_and_attribute_windows_c08403
advance_ui_horizontal_rotation_and_attribute_windows_c08454:
    rts
