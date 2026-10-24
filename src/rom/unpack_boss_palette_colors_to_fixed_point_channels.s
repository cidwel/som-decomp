; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $28C6
unpack_boss_palette_colors_to_fixed_point_channels:
    sep #$10
    ldy $C5
unpack_boss_palette_colors_to_fixed_point_channels_c228ca:
    .a16
    lda #$7C00
    and ($76),Y
    lsr
    lsr
    sta ($79)
    inc $79
    inc $79
    .a16
    lda #$03E0
    and ($76),Y
    asl
    asl
    asl
    sta ($79)
    inc $79
    inc $79
    .a16
    lda #$001F
    and ($76),Y
    xba
    sta ($79)
    inc $79
    inc $79
    iny
    iny
    cpy $66
    bne unpack_boss_palette_colors_to_fixed_point_channels_c228ca
    rep #$10
    rts
