; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-glyph-tiles.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $162C
merge_shifted_dialogue_glyph_bitmaps:
    .i16
    ldx #$0000
    .i16
    ldy #$0000
    .a8
    lda #$20
    sta a:$A176
merge_shifted_dialogue_glyph_bitmaps_c01637:
    .a8
    lda #$0C
merge_shifted_dialogue_glyph_bitmaps_c01639:
    xba
    lda a:$9000,Y
    rol
    ora a:$9404,X
    sta a:$9404,X
    lda a:$9000,Y
    lsr
    ora a:$9404,X
    sta a:$9404,X
    inx
    inx
    iny
    xba
    dec
    bne merge_shifted_dialogue_glyph_bitmaps_c01639
    inx
    inx
    inx
    inx
    inx
    inx
    inx
    inx
    dec a:$A176
    bne merge_shifted_dialogue_glyph_bitmaps_c01637
    rts
