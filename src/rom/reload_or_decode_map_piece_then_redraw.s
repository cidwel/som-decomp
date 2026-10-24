; Recovered Secret of Mana USA routine; behaviour documented in docs/map-tile-redraw.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_map_trigger_tiles = $D037
clear_map_piece_work_cache = $CBC2
decode_complete_individual_map_piece = $CC72
load_map_piece_list = $CB90
refresh_sixteen_map_tile_rows_across_real_frames = $CB43

.segment "CODE"
.org $CB27
reload_or_decode_map_piece_then_redraw:
    sep #$20
    bcc reload_or_decode_map_piece_then_redraw_c0cb33
    jsr load_map_piece_list
    jsr allocate_map_trigger_tiles
    bra refresh_sixteen_map_tile_rows_across_real_frames
reload_or_decode_map_piece_then_redraw_c0cb33:
    phb
    .a8
    lda #$7F
    pha
    plb
    jsr clear_map_piece_work_cache
    rep #$20
    stz $16
    jsr decode_complete_individual_map_piece
    plb
