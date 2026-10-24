; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

reverse_map_graphics_pixel_span_bits = $C44F

.segment "CODE"
.org $C386
mirror_map_graphics_two_tile_even_rows:
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
mirror_map_graphics_two_tile_even_rows_c1c39e:
    lda ($06),Y
    xba
    lda ($0A),Y
    jsr reverse_map_graphics_pixel_span_bits
    sta ($0C),Y
    xba
    sta ($08),Y
    iny
    lda ($06),Y
    xba
    lda ($0A),Y
    jsr reverse_map_graphics_pixel_span_bits
    sta ($0C),Y
    xba
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
    bcc mirror_map_graphics_two_tile_even_rows_c1c39e
    rep #$20
    lda $08
    sta $06
    rts
