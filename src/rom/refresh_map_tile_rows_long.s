; Recovered Secret of Mana USA routine; behaviour documented in docs/map-tile-refresh.md.
.setcpu "65816"
.smart
.a8
.i16

refresh_sixteen_map_tile_rows_across_real_frames = $CB43

.segment "CODE"
.org $CB8C
refresh_map_tile_rows_long:
    jsr refresh_sixteen_map_tile_rows_across_real_frames
    rtl
