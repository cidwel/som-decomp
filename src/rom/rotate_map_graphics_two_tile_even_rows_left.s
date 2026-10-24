; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C1EF
rotate_map_graphics_two_tile_even_rows_left:
    rep #$20
    lda $06
    clc
    .a16
    adc #$0020
    sta $0A
    .a16
    adc #$0020
    sta $08
    .a16
    adc #$0020
    sta $0C
    sep #$30
    .i8
    ldy #$00
rotate_map_graphics_two_tile_even_rows_left_c1c207:
    lda ($06),Y
    .a8
    cmp #$80
    lda ($0A),Y
    rol
    sta ($0C),Y
    lda ($06),Y
    rol
    sta ($08),Y
    iny
    lda ($06),Y
    .a8
    cmp #$80
    lda ($0A),Y
    rol
    sta ($0C),Y
    lda ($06),Y
    rol
    sta ($08),Y
    iny
    rep #$20
    lda ($06),Y
    sta ($08),Y
    lda ($0A),Y
    sta ($0C),Y
    sep #$20
    iny
    iny
    .i8
    cpy #$20
    bcc rotate_map_graphics_two_tile_even_rows_left_c1c207
    rep #$20
    lda $08
    sta $06
    rts
