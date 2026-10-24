; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

rotate_map_graphics_byte_by_wave_phase = $B6E9

.segment "CODE"
.org $B6BF
rotate_map_graphics_wave_plane:
    .i8
    ldy #$00
rotate_map_graphics_wave_plane_c1b6c1:
    lda ($06),Y
    jsr rotate_map_graphics_byte_by_wave_phase
    sta ($06),Y
    iny
    lda ($06),Y
    jsr rotate_map_graphics_byte_by_wave_phase
    sta ($06),Y
    inx
    .i8
    cpx #$10
    bcc rotate_map_graphics_wave_plane_c1b6d7
    .i8
    ldx #$00
rotate_map_graphics_wave_plane_c1b6d7:
    iny
    .i8
    cpy #$10
    bcc rotate_map_graphics_wave_plane_c1b6c1
    rep #$20
    lda $06
    clc
    .a16
    adc #$0010
    sta $06
    sep #$20
    rts
