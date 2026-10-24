; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-raster.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $95A0
build_scaled_ui_raster_window_records_and_request_native_publication:
    sep #$10
    rep #$20
    ldx $F2
    bpl build_scaled_ui_raster_window_records_and_request_native_publication_c095a9
build_scaled_ui_raster_window_records_and_request_native_publication_c095a8:
    rts
build_scaled_ui_raster_window_records_and_request_native_publication_c095a9:
    lda $8C
    bne build_scaled_ui_raster_window_records_and_request_native_publication_c095a8
    ldx $2D
    bne build_scaled_ui_raster_window_records_and_request_native_publication_c095a8
    .a16
    lda #$1830
    sta a:$1821
    sta a:$1824
    .a16
    lda #$1832
    sta a:$1827
    .a16
    lda #$96E2
    sta $12
    sep #$20
    lda $43
    .a8
    and #$03
    bne build_scaled_ui_raster_window_records_and_request_native_publication_c095e3
    lda $43
    .a8
    and #$0C
    beq build_scaled_ui_raster_window_records_and_request_native_publication_c095e3
    rep #$20
    lda $F4
    asl
    asl
    .a16
    and #$0020
    clc
    adc $12
    sta $12
    sep #$20
build_scaled_ui_raster_window_records_and_request_native_publication_c095e3:
    lda $F8
    .a8
    cmp #$70
    bcs build_scaled_ui_raster_window_records_and_request_native_publication_c095a8
    lsr
    lsr
    sec
    .a8
    sbc #$04
    tax
    .i8
    cpx #$18
    bcc build_scaled_ui_raster_window_records_and_request_native_publication_c095f5
    .i8
    ldx #$17
build_scaled_ui_raster_window_records_and_request_native_publication_c095f5:
    lda a:$9722,X
    sta $4E
    txa
    .a8
    cmp #$10
    bcc build_scaled_ui_raster_window_records_and_request_native_publication_c09602
    .a8
    lda #$0F
    tax
build_scaled_ui_raster_window_records_and_request_native_publication_c09602:
    asl
    asl
    asl
    asl
    rep #$20
    .a16
    and #$00FF
    .a16
    adc #$973A
    sta $0E
    sep #$20
    .a8
    lda #$00
    sta $4F
    .a8
    lda #$00
    sta a:$1829
    .a8
    lda #$91
    sta a:$1826
    .a8
    lda #$7F
    sta a:$1820
    lda $4E
    sec
    .a8
    sbc #$8F
    sta a:$1823
    .a8
    lda #$20
    sta a:$4372
    .a8
    lda #$01
    sta $2D
    sep #$30
    lda $43
    tay
    .a8
    and #$03
    tax
    lda $5F
    .a8
    cmp #$04
    bne build_scaled_ui_raster_window_records_and_request_native_publication_c0964e
    rep #$20
    lda $12
    clc
    .a16
    adc #$0010
    sta $12
build_scaled_ui_raster_window_records_and_request_native_publication_c0964e:
    rep #$20
    .a16
    lda #$96B2
    .i8
    cpx #$00
    beq build_scaled_ui_raster_window_records_and_request_native_publication_c09661
    .a16
    lda #$96C2
    .i8
    cpx #$02
    beq build_scaled_ui_raster_window_records_and_request_native_publication_c09661
    .a16
    lda #$96D2
build_scaled_ui_raster_window_records_and_request_native_publication_c09661:
    sta $10
    .a16
    lda #$1832
    sta $0C
    .a16
    lda #$0001
    .i8
    ldy #$20
build_scaled_ui_raster_window_records_and_request_native_publication_c0966d:
    sta ($0C),Y
    dey
    dey
    bpl build_scaled_ui_raster_window_records_and_request_native_publication_c0966d
    stz $06
    sep #$20
build_scaled_ui_raster_window_records_and_request_native_publication_c09677:
    ldy $06
    lda ($0E),Y
    beq build_scaled_ui_raster_window_records_and_request_native_publication_c096a9
    tax
    lda ($12),Y
    sta a:$4202
    stx a:$4203
    nop
    nop
    nop
    nop
    lda a:$4216
    asl
    lda a:$4217
    rol
    sta $00
    clc
    adc ($10),Y
    xba
    lda ($10),Y
    sec
    sbc $00
    rep #$20
    .i8
    ldy #$00
    sta ($0C),Y
    sep #$20
    inc $0C
    inc $0C
build_scaled_ui_raster_window_records_and_request_native_publication_c096a9:
    inc $06
    lda $06
    .a8
    cmp #$10
    bcc build_scaled_ui_raster_window_records_and_request_native_publication_c09677
    rts
