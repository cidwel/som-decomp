; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

advance_map_graphics_two_tile_frame_pointer = $C486
shift_map_graphics_two_tiles_up = $C491

.segment "CODE"
.org $C1D5
build_map_graphics_two_tile_up_frames:
    sep #$30
    .i8
    ldx #$0F
build_map_graphics_two_tile_up_frames_c1c1d9:
    jsr shift_map_graphics_two_tiles_up
    dex
    bne build_map_graphics_two_tile_up_frames_c1c1d9
    jmp advance_map_graphics_two_tile_frame_pointer
