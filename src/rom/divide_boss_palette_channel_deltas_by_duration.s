; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

divide_signed_word_by_word_with_remainder = $2D69

.segment "CODE"
.org $2999
divide_boss_palette_channel_deltas_by_duration:
    lda a:$009A,X
    sta $68
    sep #$10
    ldy $C5
divide_boss_palette_channel_deltas_by_duration_c229a2:
    lda ($79),Y
    sec
    sbc ($76),Y
    sta $46
    lda $68
    sta $4E
    jsr divide_signed_word_by_word_with_remainder
    lda $56
    sta ($79),Y
    iny
    iny
    cpy $66
    bne divide_boss_palette_channel_deltas_by_duration_c229a2
    rep #$10
    rts
