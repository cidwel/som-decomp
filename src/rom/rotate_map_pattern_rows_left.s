; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $F804
rotate_map_pattern_rows_left:
rotate_map_pattern_rows_left_c1f804:
    lda a:$FF00,X
    sta $00
    lsr $00
    rol
    sta a:$FF00,Y
    inx
    iny
    tya
    .a8
    and #$0F
    bne rotate_map_pattern_rows_left_c1f804
    rts
