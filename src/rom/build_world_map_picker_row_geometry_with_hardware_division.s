; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-scene.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $AAD2
build_world_map_picker_row_geometry_with_hardware_division:
    sep #$10
    rep #$20
    stz $04
    .a16
    lda #$5100
    sta $08
build_world_map_picker_row_geometry_with_hardware_division_c0aadd:
    sep #$30
    lda $05
    .a8
    eor #$7E
    lsr
    tax
    lda a:$AB73,X
    rep #$30
    .a16
    and #$00FF
    asl
    .a16
    eor #$01FE
    tax
    lda a:$FD22,X
    sta $32
    sep #$30
    lda $33
    beq build_world_map_picker_row_geometry_with_hardware_division_c0ab01
    .a8
    lda #$40
    bra build_world_map_picker_row_geometry_with_hardware_division_c0ab05
build_world_map_picker_row_geometry_with_hardware_division_c0ab01:
    lda $32
    lsr
    lsr
build_world_map_picker_row_geometry_with_hardware_division_c0ab05:
    sta $07
    ldx $05
    stz $06
    .i8
    ldy #$00
    rep #$20
    lda $08
    sta f:$7F5000,X
    lda $07
    .a16
    and #$00FF
    sta f:$7F5080,X
    lda $08
    sta a:$2181
    .i8
    ldx #$01
    stx a:$2183
build_world_map_picker_row_geometry_with_hardware_division_c0ab28:
    rep #$20
    tya
    xba
    lsr
    lsr
    sta a:$4204
    ldx $07
    stx a:$4206
    sep #$20
    iny
    cpy $07
    bcs build_world_map_picker_row_geometry_with_hardware_division_c0ab4f
    nop
    nop
    nop
    nop
    ldx a:$4214
    lda a:$A798,X
    sta a:$2180
    stz a:$2180
    bra build_world_map_picker_row_geometry_with_hardware_division_c0ab28
build_world_map_picker_row_geometry_with_hardware_division_c0ab4f:
    .i8
    ldx #$3F
    lda a:$A798,X
    sta a:$2180
    stz a:$2180
    rep #$20
    lda $07
    .a16
    and #$00FF
    asl
    clc
    adc $08
    sta $08
    sep #$20
    inc $05
    inc $05
    bmi build_world_map_picker_row_geometry_with_hardware_division_c0ab72
    jmp build_world_map_picker_row_geometry_with_hardware_division_c0aadd
build_world_map_picker_row_geometry_with_hardware_division_c0ab72:
    rts
