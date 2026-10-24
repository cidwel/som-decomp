; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-hdma.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $91CF
build_second_ui_hdma_matrix_record_bank:
    lda $07
    sta a:$1700
build_second_ui_hdma_matrix_record_bank_c091d4:
    lda $04
    adc $06
    sta $06
    bcc build_second_ui_hdma_matrix_record_bank_c091de
    inc $08
build_second_ui_hdma_matrix_record_bank_c091de:
    lda $07
    sta a:$1700,X
    ldy a:$4214
    sty a:$4202
    ldy $35
    sty a:$4203
    inc $00
    ldy $34
    lda a:$4216
    sty a:$4203
    lsr
    lsr
    lsr
    lsr
    lsr
    lsr
    bit $4B
    bpl build_second_ui_hdma_matrix_record_bank_c09205
    .a16
    eor #$FFFF
build_second_ui_hdma_matrix_record_bank_c09205:
    sta a:$1400,X
    lda a:$4216
    ldy $00
    sty a:$4206
    lsr
    lsr
    lsr
    lsr
    lsr
    lsr
    bit $4B
    bvc build_second_ui_hdma_matrix_record_bank_c09229
    sta a:$1500,X
    .a16
    eor #$FFFF
    sta a:$1600,X
    inx
    inx
    bne build_second_ui_hdma_matrix_record_bank_c091d4
    beq build_second_ui_hdma_matrix_record_bank_c09236
build_second_ui_hdma_matrix_record_bank_c09229:
    sta a:$1600,X
    .a16
    eor #$FFFF
    sta a:$1500,X
    inx
    inx
    bne build_second_ui_hdma_matrix_record_bank_c091d4
build_second_ui_hdma_matrix_record_bank_c09236:
    lda $04
    adc $06
    sta $06
    bcc build_second_ui_hdma_matrix_record_bank_c09240
    inc $08
build_second_ui_hdma_matrix_record_bank_c09240:
    lda $07
    sta a:$0DC0,X
    ldy a:$4214
    sty a:$4202
    ldy $35
    sty a:$4203
    inc $00
    ldy $34
    lda a:$4216
    sty a:$4203
    lsr
    lsr
    lsr
    lsr
    lsr
    lsr
    bit $4B
    bpl build_second_ui_hdma_matrix_record_bank_c09267
    .a16
    eor #$FFFF
build_second_ui_hdma_matrix_record_bank_c09267:
    sta a:$0D00,X
    lda a:$4216
    ldy $00
    sty a:$4206
    lsr
    lsr
    lsr
    lsr
    lsr
    lsr
    bit $4B
    bvc build_second_ui_hdma_matrix_record_bank_c0928c
    sta a:$0D40,X
    .a16
    eor #$FFFF
    sta a:$0D80,X
    inx
    inx
    cpx $10
    bcc build_second_ui_hdma_matrix_record_bank_c09236
    rts
build_second_ui_hdma_matrix_record_bank_c0928c:
    sta a:$0D80,X
    .a16
    eor #$FFFF
    sta a:$0D40,X
    inx
    inx
    cpx $10
    bcc build_second_ui_hdma_matrix_record_bank_c09236
    rts
