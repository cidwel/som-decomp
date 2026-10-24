; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C491
shift_map_graphics_two_tiles_up:
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
    ldy #$00
    lda ($06),Y
    sta $02
shift_map_graphics_two_tiles_up_c1c4ab:
    iny
    iny
    lda ($06),Y
    dey
    dey
    sta ($08),Y
    iny
    iny
    .i8
    cpy #$0E
    bcc shift_map_graphics_two_tiles_up_c1c4ab
    .i8
    ldy #$00
    lda ($0A),Y
    .i8
    ldy #$0E
    sta ($08),Y
    .i8
    ldy #$00
shift_map_graphics_two_tiles_up_c1c4c3:
    iny
    iny
    lda ($0A),Y
    dey
    dey
    sta ($0C),Y
    iny
    iny
    .i8
    cpy #$0E
    bcc shift_map_graphics_two_tiles_up_c1c4c3
    lda $02
    sta ($0C),Y
    iny
    iny
    lda ($06),Y
    sta $02
shift_map_graphics_two_tiles_up_c1c4db:
    iny
    iny
    lda ($06),Y
    dey
    dey
    sta ($08),Y
    iny
    iny
    .i8
    cpy #$1E
    bcc shift_map_graphics_two_tiles_up_c1c4db
    .i8
    ldy #$10
    lda ($0A),Y
    .i8
    ldy #$1E
    sta ($08),Y
    .i8
    ldy #$10
shift_map_graphics_two_tiles_up_c1c4f3:
    iny
    iny
    lda ($0A),Y
    dey
    dey
    sta ($0C),Y
    iny
    iny
    .i8
    cpy #$1E
    bcc shift_map_graphics_two_tiles_up_c1c4f3
    lda $02
    sta ($0C),Y
    lda $08
    sta $06
    rts
