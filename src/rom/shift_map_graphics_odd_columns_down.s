; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B4DF
shift_map_graphics_odd_columns_down:
    rep #$20
    lda $06
    clc
    .a16
    adc #$0020
    sta $08
    .i8
    ldy #$1E
    lda ($06),Y
    .a16
    and #$5555
    sta $0A
shift_map_graphics_odd_columns_down_c1b4f2:
    dey
    dey
    lda ($06),Y
    .a16
    and #$5555
    sta $0C
    iny
    iny
    lda ($06),Y
    .a16
    and #$AAAA
    ora $0C
    sta ($08),Y
    dey
    dey
    .i8
    cpy #$12
    bcs shift_map_graphics_odd_columns_down_c1b4f2
    lda ($06),Y
    .a16
    and #$AAAA
    ora $0A
    sta ($08),Y
    dey
    dey
    lda ($06),Y
    .a16
    and #$5555
    sta $0A
shift_map_graphics_odd_columns_down_c1b51e:
    dey
    dey
    lda ($06),Y
    .a16
    and #$5555
    sta $0C
    iny
    iny
    lda ($06),Y
    .a16
    and #$AAAA
    ora $0C
    sta ($08),Y
    dey
    dey
    .i8
    cpy #$02
    bcs shift_map_graphics_odd_columns_down_c1b51e
    lda ($06),Y
    .a16
    and #$AAAA
    ora $0A
    sta ($08),Y
    lda $08
    sta $06
    rts
