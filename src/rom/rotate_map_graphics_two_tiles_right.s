; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C357
rotate_map_graphics_two_tiles_right:
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
rotate_map_graphics_two_tiles_right_c1c36f:
    lda ($0A),Y
    pha
    lsr
    lda ($06),Y
    ror
    sta ($08),Y
    pla
    ror
    sta ($0C),Y
    dey
    bpl rotate_map_graphics_two_tiles_right_c1c36f
    rep #$20
    lda $08
    sta $06
    rts
