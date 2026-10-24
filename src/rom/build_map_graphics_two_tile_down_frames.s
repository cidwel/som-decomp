; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

advance_map_graphics_two_tile_frame_pointer = $C486
shift_map_graphics_two_tiles_down = $C50A

.segment "CODE"
.org $C1E2
build_map_graphics_two_tile_down_frames:
    sep #$30
    .i8
    ldx #$0F
build_map_graphics_two_tile_down_frames_c1c1e6:
    jsr shift_map_graphics_two_tiles_down
    dex
    bne build_map_graphics_two_tile_down_frames_c1c1e6
    jmp advance_map_graphics_two_tile_frame_pointer
