; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B392
rotate_map_graphics_odd_rows_right:
    rep #$20
    lda $06
    clc
    .a16
    adc #$0020
    sta $08
    sep #$30
    .i8
    ldy #$00
rotate_map_graphics_odd_rows_right_c1b3a0:
    rep #$20
    lda ($06),Y
    sta ($08),Y
    sep #$20
    iny
    iny
    lda ($06),Y
    pha
    lsr
    pla
    ror
    sta ($08),Y
    iny
    lda ($06),Y
    pha
    lsr
    pla
    ror
    sta ($08),Y
    iny
    .i8
    cpy #$20
    bcc rotate_map_graphics_odd_rows_right_c1b3a0
    rep #$20
    lda $08
    sta $06
    rts
