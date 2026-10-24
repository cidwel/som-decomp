; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-glyph-tiles.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $15B9
expand_dialogue_glyph_bitmaps_and_merge_tile_borders:
    .i16
    ldx #$0000
    .i16
    ldy #$0000
    .a8
    lda #$20
    sta a:$A176
expand_dialogue_glyph_bitmaps_and_merge_tile_borders_c015c4:
    .a8
    lda #$0C
expand_dialogue_glyph_bitmaps_and_merge_tile_borders_c015c6:
    xba
    lda a:$9000,Y
    sta a:$9404,X
    sta a:$9405,X
    inx
    inx
    iny
    xba
    dec
    bne expand_dialogue_glyph_bitmaps_and_merge_tile_borders_c015c6
    inx
    inx
    inx
    inx
    inx
    inx
    inx
    inx
    dec a:$A176
    bne expand_dialogue_glyph_bitmaps_and_merge_tile_borders_c015c4
    .i16
    ldx #$0000
    .i16
    ldy #$0000
    .a8
    lda #$20
    sta a:$A176
expand_dialogue_glyph_bitmaps_and_merge_tile_borders_c015ef:
    rep #$20
    .a16
    lda #$0000
    sta a:$9400,X
    sta a:$9402,X
    sta a:$941C,X
    sta a:$941E,X
    sep #$20
    .a8
    lda #$0C
expand_dialogue_glyph_bitmaps_and_merge_tile_borders_c01604:
    xba
    lda a:$9000,Y
    ora a:$9402,X
    sta a:$9402,X
    lda a:$9000,Y
    ora a:$9406,X
    sta a:$9406,X
    inx
    inx
    iny
    xba
    dec
    bne expand_dialogue_glyph_bitmaps_and_merge_tile_borders_c01604
    inx
    inx
    inx
    inx
    inx
    inx
    inx
    inx
    dec a:$A176
    bne expand_dialogue_glyph_bitmaps_and_merge_tile_borders_c015ef
    rts
