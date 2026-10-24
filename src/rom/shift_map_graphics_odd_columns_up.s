; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B411
shift_map_graphics_odd_columns_up:
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
    and #$5555
    sta $0A
shift_map_graphics_odd_columns_up_c1b424:
    iny
    iny
    lda ($06),Y
    .a16
    and #$5555
    sta $0C
    dey
    dey
    lda ($06),Y
    .a16
    and #$AAAA
    ora $0C
    sta ($08),Y
    iny
    iny
    .i8
    cpy #$0E
    bcc shift_map_graphics_odd_columns_up_c1b424
    lda ($06),Y
    .a16
    and #$AAAA
    ora $0A
    sta ($08),Y
    iny
    iny
    lda ($06),Y
    .a16
    and #$5555
    sta $0A
shift_map_graphics_odd_columns_up_c1b450:
    iny
    iny
    lda ($06),Y
    .a16
    and #$5555
    sta $0C
    dey
    dey
    lda ($06),Y
    .a16
    and #$AAAA
    ora $0C
    sta ($08),Y
    iny
    iny
    .i8
    cpy #$1E
    bcc shift_map_graphics_odd_columns_up_c1b450
    lda ($06),Y
    .a16
    and #$AAAA
    ora $0A
    sta ($08),Y
    lda $08
    sta $06
    rts
