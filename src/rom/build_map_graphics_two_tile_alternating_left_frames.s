; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

advance_map_graphics_two_tile_frame_pointer = $C486
rotate_map_graphics_two_tile_even_rows_left = $C1EF
rotate_map_graphics_two_tile_odd_rows_left = $C28B

.segment "CODE"
.org $C162
build_map_graphics_two_tile_alternating_left_frames:
    sep #$30
    .i8
    ldx #$0F
build_map_graphics_two_tile_alternating_left_frames_c1c166:
    jsr rotate_map_graphics_two_tile_even_rows_left
    jsr rotate_map_graphics_two_tile_odd_rows_left
    dex
    bne build_map_graphics_two_tile_alternating_left_frames_c1c166
    jsr rotate_map_graphics_two_tile_even_rows_left
    jmp advance_map_graphics_two_tile_frame_pointer
