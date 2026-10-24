; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-hdma.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $90FA
build_first_ui_hdma_matrix_record_bank:
    lda $07
    sta a:$1300
build_first_ui_hdma_matrix_record_bank_c090ff:
    lda $04
    adc $06
    sta $06
    bcc build_first_ui_hdma_matrix_record_bank_c09109
    inc $08
build_first_ui_hdma_matrix_record_bank_c09109:
    lda $07
    sta a:$1300,X
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
    bpl build_first_ui_hdma_matrix_record_bank_c09130
    .a16
    eor #$FFFF
build_first_ui_hdma_matrix_record_bank_c09130:
    sta a:$1000,X
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
    bvc build_first_ui_hdma_matrix_record_bank_c09154
    sta a:$1100,X
    .a16
    eor #$FFFF
    sta a:$1200,X
    inx
    inx
    bne build_first_ui_hdma_matrix_record_bank_c090ff
    beq build_first_ui_hdma_matrix_record_bank_c09161
build_first_ui_hdma_matrix_record_bank_c09154:
    sta a:$1200,X
    .a16
    eor #$FFFF
    sta a:$1100,X
    inx
    inx
    bne build_first_ui_hdma_matrix_record_bank_c090ff
build_first_ui_hdma_matrix_record_bank_c09161:
    lda $04
    adc $06
    sta $06
    bcc build_first_ui_hdma_matrix_record_bank_c0916b
    inc $08
build_first_ui_hdma_matrix_record_bank_c0916b:
    lda $07
    sta a:$0CC0,X
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
    bpl build_first_ui_hdma_matrix_record_bank_c09192
    .a16
    eor #$FFFF
build_first_ui_hdma_matrix_record_bank_c09192:
    sta a:$0C00,X
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
    bvc build_first_ui_hdma_matrix_record_bank_c091b7
    sta a:$0C40,X
    .a16
    eor #$FFFF
    sta a:$0C80,X
    inx
    inx
    cpx $10
    bcc build_first_ui_hdma_matrix_record_bank_c09161
    rts
build_first_ui_hdma_matrix_record_bank_c091b7:
    sta a:$0C80,X
    .a16
    eor #$FFFF
    sta a:$0C40,X
    inx
    inx
    cpx $10
    bcc build_first_ui_hdma_matrix_record_bank_c09161
    rts
