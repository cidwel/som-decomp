; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1135
copy_boss_palette_seven_colors:
    phx
    sta $4E
    .a8
    lda #$C8
    sta $78
    rep #$20
    lda $4E
    .a16
    and #$00FF
    asl
    asl
    asl
    asl
    asl
    tax
    lda $46
    .a16
    and #$00FF
    asl
    sta $4E
    asl
    asl
    asl
    asl
    sbc $4E
    .a16
    adc #$1000
    sta $76
    .i16
    ldy #$0000
copy_boss_palette_seven_colors_c2115f:
    lda [$76],Y
    sta a:$0602,X
    inx
    inx
    iny
    iny
    .i16
    cpy #$000E
    bne copy_boss_palette_seven_colors_c2115f
    sep #$20
    plx
    rts
