; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

advance_map_graphics_two_tile_frame_pointer = $C486
rotate_map_graphics_two_tile_even_rows_right = $C23E
rotate_map_graphics_two_tile_odd_rows_right = $C2DA

.segment "CODE"
.org $C175
build_map_graphics_two_tile_alternating_right_frames:
    sep #$30
    .i8
    ldx #$0F
build_map_graphics_two_tile_alternating_right_frames_c1c179:
    jsr rotate_map_graphics_two_tile_even_rows_right
    jsr rotate_map_graphics_two_tile_odd_rows_right
    dex
    bne build_map_graphics_two_tile_alternating_right_frames_c1c179
    jsr rotate_map_graphics_two_tile_even_rows_right
    jmp advance_map_graphics_two_tile_frame_pointer
