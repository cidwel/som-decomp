; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

advance_map_graphics_two_tile_frame_pointer = $C486
mirror_map_graphics_two_tile_all_rows = $C420

.segment "CODE"
.org $C1CD
build_map_graphics_two_tile_mirror_frame:
    sep #$30
    jsr mirror_map_graphics_two_tile_all_rows
    jmp advance_map_graphics_two_tile_frame_pointer
