; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $F817
shift_map_pattern_rows_right:
shift_map_pattern_rows_right_c1f817:
    lda a:$FF00,X
    .a8
    cmp #$80
    ror
    sta a:$FF00,Y
    inx
    iny
    tya
    .a8
    and #$0F
    bne shift_map_pattern_rows_right_c1f817
    rts
