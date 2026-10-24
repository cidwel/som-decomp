; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

transpose_map_graphics_plane = $B609

.segment "CODE"
.org $B5D4
transpose_map_graphics_four_plane_block:
    sep #$30
    .i8
    ldy #$00
    jsr transpose_map_graphics_plane
    iny
    jsr transpose_map_graphics_plane
    tya
    clc
    .a8
    adc #$0F
    tay
    jsr transpose_map_graphics_plane
    iny
    jsr transpose_map_graphics_plane
    tya
    clc
    .a8
    adc #$0F
    tay
    jsr transpose_map_graphics_plane
    iny
    jsr transpose_map_graphics_plane
    tya
    clc
    .a8
    adc #$0F
    tay
    jsr transpose_map_graphics_plane
    iny
    jsr transpose_map_graphics_plane
    tya
    sec
    .a8
    sbc #$31
    tay
    rts
