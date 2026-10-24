; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B3C7
rotate_map_graphics_all_rows_left:
    rep #$20
    lda $06
    clc
    .a16
    adc #$0020
    sta $08
    sep #$30
    .i8
    ldy #$1F
rotate_map_graphics_all_rows_left_c1b3d5:
    lda ($06),Y
    .a8
    cmp #$80
    rol
    sta ($08),Y
    dey
    bpl rotate_map_graphics_all_rows_left_c1b3d5
    rep #$20
    lda $08
    sta $06
    rts
