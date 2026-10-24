; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C50A
shift_map_graphics_two_tiles_down:
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
    .i8
    ldy #$1E
    lda ($0A),Y
    sta $02
shift_map_graphics_two_tiles_down_c1c524:
    dey
    dey
    lda ($0A),Y
    iny
    iny
    sta ($0C),Y
    dey
    dey
    .i8
    cpy #$12
    bcs shift_map_graphics_two_tiles_down_c1c524
    .i8
    ldy #$1E
    lda ($06),Y
    .i8
    ldy #$10
    sta ($0C),Y
    .i8
    ldy #$1E
shift_map_graphics_two_tiles_down_c1c53c:
    dey
    dey
    lda ($06),Y
    iny
    iny
    sta ($08),Y
    dey
    dey
    .i8
    cpy #$12
    bcs shift_map_graphics_two_tiles_down_c1c53c
    lda $02
    sta ($08),Y
    dey
    dey
    lda ($0A),Y
    sta $02
shift_map_graphics_two_tiles_down_c1c554:
    dey
    dey
    lda ($0A),Y
    iny
    iny
    sta ($0C),Y
    dey
    dey
    .i8
    cpy #$02
    bcs shift_map_graphics_two_tiles_down_c1c554
    .i8
    ldy #$0E
    lda ($06),Y
    .i8
    ldy #$00
    sta ($0C),Y
    .i8
    ldy #$0E
shift_map_graphics_two_tiles_down_c1c56c:
    dey
    dey
    lda ($06),Y
    iny
    iny
    sta ($08),Y
    dey
    dey
    .i8
    cpy #$02
    bcs shift_map_graphics_two_tiles_down_c1c56c
    lda $02
    sta ($08),Y
    lda $08
    sta $06
    rts
