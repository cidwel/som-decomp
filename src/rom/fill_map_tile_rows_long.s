; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

fill_map_tile_rows = $CA71



.segment "CODE"
.org $C9E6
fill_map_tile_rows_long:
    jsr fill_map_tile_rows
    rtl
