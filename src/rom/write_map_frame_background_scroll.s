; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C170
write_map_frame_background_scroll:
    sep #$20
    lda $5E
    .a8
    and #$02
    eor $B0
    sta a:$210D
    lda $B1
    sta a:$210D
    lda $5F
    .a8
    and #$02
    eor $B2
    sta a:$210E
    lda $B3
    sta a:$210E
    lda $B9
    bne write_map_frame_background_scroll_c0c1a0
    lda $B4
    sta a:$210F
    lda $B5
    sta a:$210F
    lda $B6
    bra write_map_frame_background_scroll_c0c1b6
write_map_frame_background_scroll_c0c1a0:
    lda $5E
    .a8
    and #$04
    lsr
    eor $B4
    sta a:$210F
    lda $B5
    sta a:$210F
    lda $5F
    .a8
    and #$04
    lsr
    eor $B6
write_map_frame_background_scroll_c0c1b6:
    sta a:$2110
    stz a:$2110
    lda $3E
    sta a:$2111
    lda $3F
    sta a:$2111
    lda $40
    sta a:$2112
    stz a:$2112
    rts
