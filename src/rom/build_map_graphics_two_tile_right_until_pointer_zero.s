; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

advance_map_graphics_two_tile_frame_pointer = $C486
rotate_map_graphics_two_tiles_right = $C357

.segment "CODE"
.org $C195
build_map_graphics_two_tile_right_until_pointer_zero:
    sep #$30
    .i8
    ldx #$0F
build_map_graphics_two_tile_right_until_pointer_zero_c1c199:
    jsr rotate_map_graphics_two_tiles_right
    bne build_map_graphics_two_tile_right_until_pointer_zero_c1c199
    jmp advance_map_graphics_two_tile_frame_pointer
