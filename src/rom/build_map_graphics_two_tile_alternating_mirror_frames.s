; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

advance_map_graphics_two_tile_frame_pointer = $C486
mirror_map_graphics_two_tile_even_rows = $C386
mirror_map_graphics_two_tile_odd_rows = $C3D3

.segment "CODE"
.org $C1BF
build_map_graphics_two_tile_alternating_mirror_frames:
    sep #$30
    jsr mirror_map_graphics_two_tile_even_rows
    jsr mirror_map_graphics_two_tile_odd_rows
    jsr mirror_map_graphics_two_tile_even_rows
    jmp advance_map_graphics_two_tile_frame_pointer
