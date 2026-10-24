; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-motion-division.md.
.setcpu "65816"
.smart
.a8
.i16

select_scene_color_targets_from_cursor_and_fade_flags = $9D78

.segment "CODE"
.org $869B
compute_ui_motion_from_native_hardware_division:
    sep #$30
    lda $43
    .a8
    and #$0C
    bne compute_ui_motion_from_native_hardware_division_c086c3
    lda $5E
    .a8
    cmp #$FF
    bne compute_ui_motion_from_native_hardware_division_c086b4
compute_ui_motion_from_native_hardware_division_c086a9:
    .a8
    lda #$00
    sta $66
    sta $67
    sta $68
    sta $69
    rts
compute_ui_motion_from_native_hardware_division_c086b4:
    clc
    .a8
    adc #$04
    bcc compute_ui_motion_from_native_hardware_division_c086bf
    .a8
    lda #$FF
    sta $5E
    bra compute_ui_motion_from_native_hardware_division_c086a9
compute_ui_motion_from_native_hardware_division_c086bf:
    sta $5E
    bra compute_ui_motion_from_native_hardware_division_c08700
compute_ui_motion_from_native_hardware_division_c086c3:
    cmp $5F
    beq compute_ui_motion_from_native_hardware_division_c086e1
    ldx $5E
    .i8
    cpx #$FF
    beq compute_ui_motion_from_native_hardware_division_c086da
    lda $5E
    clc
    .a8
    adc #$08
    bcc compute_ui_motion_from_native_hardware_division_c086d6
    .a8
    lda #$FF
compute_ui_motion_from_native_hardware_division_c086d6:
    sta $5E
    bra compute_ui_motion_from_native_hardware_division_c08700
compute_ui_motion_from_native_hardware_division_c086da:
    sta $5F
    pha
    jsr select_scene_color_targets_from_cursor_and_fade_flags
    pla
compute_ui_motion_from_native_hardware_division_c086e1:
    sep #$30
    ldx $5D
    .a8
    and #$04
    bne compute_ui_motion_from_native_hardware_division_c086eb
    ldx $5C
compute_ui_motion_from_native_hardware_division_c086eb:
    stx $00
    lda $5E
    cmp $00
    beq compute_ui_motion_from_native_hardware_division_c08700
    lda $5E
    sec
    .a8
    sbc #$03
    cmp $00
    bcs compute_ui_motion_from_native_hardware_division_c086fe
    lda $00
compute_ui_motion_from_native_hardware_division_c086fe:
    sta $5E
compute_ui_motion_from_native_hardware_division_c08700:
    rep #$20
    lda $64
    clc
    adc $32
    sta a:$4204
    ldx $5E
    stx a:$4206
    nop
    nop
    lda $62
    clc
    adc $30
    pha
    ldy a:$4214
    lda a:$4216
    sta $64
    pla
    sta a:$4204
    ldx $5E
    stx a:$4206
    rep #$10
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    ldx a:$4214
    lda a:$4216
    sta $62
    .a16
    lda #$0200
    bit $F6
    beq compute_ui_motion_from_native_hardware_division_c0874a
    .a16
    lda #$0100
    bit $F6
    beq compute_ui_motion_from_native_hardware_division_c08760
    bne compute_ui_motion_from_native_hardware_division_c0876f
compute_ui_motion_from_native_hardware_division_c0874a:
    .a16
    lda #$0100
    bit $F6
    bne compute_ui_motion_from_native_hardware_division_c08756
    sty $68
    stx $66
    rts
compute_ui_motion_from_native_hardware_division_c08756:
    tya
    .a16
    eor #$FFFF
    inc
    sta $68
    stx $66
    rts
compute_ui_motion_from_native_hardware_division_c08760:
    tya
    .a16
    eor #$FFFF
    inc
    sta $68
    txa
    .a16
    eor #$FFFF
    inc
    sta $66
    rts
compute_ui_motion_from_native_hardware_division_c0876f:
    sty $68
    txa
    .a16
    eor #$FFFF
    inc
    sta $66
    rts
