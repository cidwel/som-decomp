; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C327
rotate_map_graphics_two_tiles_left:
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
    ldy #$1F
rotate_map_graphics_two_tiles_left_c1c33f:
    lda ($06),Y
    .a8
    cmp #$80
    lda ($0A),Y
    rol
    sta ($0C),Y
    lda ($06),Y
    rol
    sta ($08),Y
    dey
    bpl rotate_map_graphics_two_tiles_left_c1c33f
    rep #$20
    lda $08
    sta $06
    rts
