; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2A27
pack_boss_palette_fixed_point_channels:
    ldy $C5
pack_boss_palette_fixed_point_channels_c22a29:
    lda ($76),Y
    iny
    iny
    .a16
    and #$1F00
    asl
    asl
    sta $68
    lda ($76),Y
    iny
    iny
    .a16
    and #$1F00
    lsr
    lsr
    lsr
    ora $68
    sta $68
    lda ($76),Y
    iny
    iny
    .a16
    and #$1F00
    xba
    ora $68
    sta ($79)
    inc $79
    inc $79
    cpy $66
    bne pack_boss_palette_fixed_point_channels_c22a29
    rts
