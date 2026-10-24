; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B478
shift_map_graphics_even_columns_up:
    rep #$20
    lda $06
    clc
    .a16
    adc #$0020
    sta $08
    .i8
    ldy #$00
    lda ($06),Y
    .a16
    and #$AAAA
    sta $0A
shift_map_graphics_even_columns_up_c1b48b:
    iny
    iny
    lda ($06),Y
    .a16
    and #$AAAA
    sta $0C
    dey
    dey
    lda ($06),Y
    .a16
    and #$5555
    ora $0C
    sta ($08),Y
    iny
    iny
    .i8
    cpy #$0E
    bcc shift_map_graphics_even_columns_up_c1b48b
    lda ($06),Y
    .a16
    and #$5555
    ora $0A
    sta ($08),Y
    iny
    iny
    lda ($06),Y
    .a16
    and #$AAAA
    sta $0A
shift_map_graphics_even_columns_up_c1b4b7:
    iny
    iny
    lda ($06),Y
    .a16
    and #$AAAA
    sta $0C
    dey
    dey
    lda ($06),Y
    .a16
    and #$5555
    ora $0C
    sta ($08),Y
    iny
    iny
    .i8
    cpy #$1E
    bcc shift_map_graphics_even_columns_up_c1b4b7
    lda ($06),Y
    .a16
    and #$5555
    ora $0A
    sta ($08),Y
    lda $08
    sta $06
    rts
