; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-hdma.md.
.setcpu "65816"
.smart
.a8
.i16

build_first_ui_hdma_matrix_record_bank = $90FA
build_second_ui_hdma_matrix_record_bank_and_select_it = $91C7
derive_ui_affine_or_automatic_motion_scale_coefficients = $929C
derive_world_map_ui_curve_coefficients_and_fraction_bytes = $9368
derive_world_map_ui_quadrant_offsets = $9332

.segment "CODE"
.org $908B
derive_ui_frame_matrix_and_select_hdma_record_bank:
    rep #$20
    lda $F6
    jsr derive_world_map_ui_curve_coefficients_and_fraction_bytes
    jsr derive_world_map_ui_quadrant_offsets
    sep #$30
    bit $F2
    bpl derive_ui_frame_matrix_and_select_hdma_record_bank_c0909e
    jmp derive_ui_affine_or_automatic_motion_scale_coefficients
derive_ui_frame_matrix_and_select_hdma_record_bank_c0909e:
    .a8
    lda #$00
    sta a:$4204
    .a8
    lda #$0F
    sta a:$4205
    lda $F8
    lsr
    lsr
    sta a:$4206
    stz $06
    lda $FC
    sec
    .a8
    sbc #$28
    sta $07
    lda $FD
    .a8
    and #$03
    .a8
    sbc #$01
    sta $08
    lda a:$4214
    sta $04
    lda a:$4215
    sta $05
    lda $F8
    lsr
    lsr
    stz a:$4204
    sta a:$4205
    inc
    sta $00
    sta a:$4206
    sec
    .a8
    sbc #$18
    bcs derive_ui_frame_matrix_and_select_hdma_record_bank_c090e1
    .a8
    lda #$00
derive_ui_frame_matrix_and_select_hdma_record_bank_c090e1:
    sta $10
    .i8
    ldy #$00
    .i8
    ldx #$02
    .a8
    lda #$04
    bit $60
    rep #$20
    bne derive_ui_frame_matrix_and_select_hdma_record_bank_c090f2
    jmp build_second_ui_hdma_matrix_record_bank_and_select_it
derive_ui_frame_matrix_and_select_hdma_record_bank_c090f2:
    jsr build_first_ui_hdma_matrix_record_bank
    .i8
    ldx #$80
    stx $60
    rts
