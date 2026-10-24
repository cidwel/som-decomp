; Recovered Secret of Mana USA routine; behaviour documented in docs/map-tile-redraw.md.
.setcpu "65816"
.smart
.a8
.i16

reload_or_decode_map_piece_then_redraw = $CB27

.segment "CODE"
.org $CAFF
reload_map_pieces_preserving_low_scratch_and_redraw:
    sep #$20
    .a8
    lda #$00
    pha
    plb
    rep #$30
    php
    .i16
    ldx #$000E
reload_map_pieces_preserving_low_scratch_and_redraw_c0cb0b:
    lda $20,X
    sta a:$05F0,X
    dex
    dex
    bpl reload_map_pieces_preserving_low_scratch_and_redraw_c0cb0b
    plp
    jsr reload_or_decode_map_piece_then_redraw
    rep #$30
    .i16
    ldx #$000E
reload_map_pieces_preserving_low_scratch_and_redraw_c0cb1d:
    lda a:$05F0,X
    sta $20,X
    dex
    dex
    bpl reload_map_pieces_preserving_low_scratch_and_redraw_c0cb1d
    rtl
