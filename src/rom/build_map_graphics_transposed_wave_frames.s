; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

build_map_graphics_wave_frames = $B687
transpose_map_graphics_four_plane_block = $B5D4

.segment "CODE"
.org $B5AD
build_map_graphics_transposed_wave_frames:
    rep #$20
    lda $06
    pha
    jsr transpose_map_graphics_four_plane_block
    jsr build_map_graphics_wave_frames
    rep #$20
    pla
    sta $06
    sep #$30
    .i8
    ldx #$10
build_map_graphics_transposed_wave_frames_c1b5c1:
    jsr transpose_map_graphics_four_plane_block
    rep #$20
    lda $06
    clc
    .a16
    adc #$0040
    sta $06
    sep #$20
    dex
    bne build_map_graphics_transposed_wave_frames_c1b5c1
    rts
