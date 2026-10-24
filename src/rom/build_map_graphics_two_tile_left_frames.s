; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

advance_map_graphics_two_tile_frame_pointer = $C486
rotate_map_graphics_two_tiles_left = $C327

.segment "CODE"
.org $C188
build_map_graphics_two_tile_left_frames:
    sep #$30
    .i8
    ldx #$0F
build_map_graphics_two_tile_left_frames_c1c18c:
    jsr rotate_map_graphics_two_tiles_left
    dex
    bne build_map_graphics_two_tile_left_frames_c1c18c
    jmp advance_map_graphics_two_tile_frame_pointer
