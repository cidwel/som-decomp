; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-hdma.md.
.setcpu "65816"
.smart
.a8
.i16

multiply_world_map_ui_direction_by_native_byte_scale = $92E8

.segment "CODE"
.org $929C
derive_ui_affine_or_automatic_motion_scale_coefficients:
    sep #$30
    .a8
    lda #$00
    xba
    stz $00
    stz $01
    lda $8C
    beq derive_ui_affine_or_automatic_motion_scale_coefficients_c092cb
    lda $E3
    .a8
    bit #$06
    bne derive_ui_affine_or_automatic_motion_scale_coefficients_c092cb
    lda $90
    jsr multiply_world_map_ui_direction_by_native_byte_scale
    rep #$20
    lda $36
    .a16
    cmp #$8000
    ror
    adc $36
    sta $36
    lda $38
    .a16
    cmp #$8000
    ror
    adc $38
    sta $38
    rts
derive_ui_affine_or_automatic_motion_scale_coefficients_c092cb:
    lda $FE
    .a8
    and #$3F
    bne derive_ui_affine_or_automatic_motion_scale_coefficients_c092d8
    lda $F8
    clc
    .a8
    adc #$04
    bra multiply_world_map_ui_direction_by_native_byte_scale
derive_ui_affine_or_automatic_motion_scale_coefficients_c092d8:
    .a8
    eor #$3F
    bit $FE
    bvs multiply_world_map_ui_direction_by_native_byte_scale
    lsr
    lsr
    sta $02
    lsr
    sec
    adc $02
    bra multiply_world_map_ui_direction_by_native_byte_scale
