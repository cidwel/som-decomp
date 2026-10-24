; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-scene.md.
.setcpu "65816"
.smart
.a8
.i16

derive_world_map_ui_curve_coefficients_and_fraction_bytes = $9368
derive_world_map_ui_quadrant_offsets = $9332
multiply_world_map_ui_direction_by_native_byte_scale = $92E8

.segment "CODE"
.org $A9E1
prepare_world_map_picker_scaled_matrix_coefficients:
    rep #$30
    lda $F6
    jsr derive_world_map_ui_curve_coefficients_and_fraction_bytes
    jsr derive_world_map_ui_quadrant_offsets
    sep #$30
    sep #$30
    stz $00
    stz $01
    .a8
    lda #$00
    xba
    .a8
    lda #$FF
    jsr multiply_world_map_ui_direction_by_native_byte_scale
    rep #$20
    lda $36
    asl
    ror $36
    asl
    sec
    sbc $36
    sta $36
    lda $38
    asl
    ror $38
    asl
    sec
    sbc $38
    sta $38
    rts
