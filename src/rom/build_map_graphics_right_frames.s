; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

advance_map_graphics_frame_pointer = $B406
rotate_map_graphics_all_rows_right = $B3E6

.segment "CODE"
.org $B2A0
build_map_graphics_right_frames:
    sep #$30
    .i8
    ldx #$07
build_map_graphics_right_frames_c1b2a4:
    jsr rotate_map_graphics_all_rows_right
    dex
    bne build_map_graphics_right_frames_c1b2a4
    jmp advance_map_graphics_frame_pointer
