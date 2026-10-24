; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

rotate_map_graphics_wave_frame = $B6B4

.segment "CODE"
.org $B687
build_map_graphics_wave_frames:
    rep #$30
    lda $06
    tax
    clc
    .a16
    adc #$0040
    tay
    .a16
    lda #$03C0
    mvn #$7F, #$7F
    sep #$30
    .i8
    ldx #$00
build_map_graphics_wave_frames_c1b69b:
    jsr rotate_map_graphics_wave_frame
    phx
    txa
    clc
    .a8
    adc #$08
    .a8
    cmp #$10
    bcc build_map_graphics_wave_frames_c1b6a9
    .a8
    and #$0F
build_map_graphics_wave_frames_c1b6a9:
    tax
    jsr rotate_map_graphics_wave_frame
    plx
    inx
    .i8
    cpx #$10
    bcc build_map_graphics_wave_frames_c1b69b
    rts
