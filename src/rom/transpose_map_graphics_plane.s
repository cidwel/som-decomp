; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

append_map_graphics_transpose_bits = $B66E

.segment "CODE"
.org $B609
transpose_map_graphics_plane:
    lda ($06),Y
    jsr append_map_graphics_transpose_bits
    iny
    iny
    lda ($06),Y
    jsr append_map_graphics_transpose_bits
    iny
    iny
    lda ($06),Y
    jsr append_map_graphics_transpose_bits
    iny
    iny
    lda ($06),Y
    jsr append_map_graphics_transpose_bits
    iny
    iny
    lda ($06),Y
    jsr append_map_graphics_transpose_bits
    iny
    iny
    lda ($06),Y
    jsr append_map_graphics_transpose_bits
    iny
    iny
    lda ($06),Y
    jsr append_map_graphics_transpose_bits
    iny
    iny
    lda ($06),Y
    jsr append_map_graphics_transpose_bits
    lda $0F
    sta ($06),Y
    dey
    dey
    lda $0E
    sta ($06),Y
    dey
    dey
    lda $0D
    sta ($06),Y
    dey
    dey
    lda $0C
    sta ($06),Y
    dey
    dey
    lda $0B
    sta ($06),Y
    dey
    dey
    lda $0A
    sta ($06),Y
    dey
    dey
    lda $09
    sta ($06),Y
    dey
    dey
    lda $08
    sta ($06),Y
    rts
