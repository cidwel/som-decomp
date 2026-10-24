; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

advance_map_graphics_frame_pointer = $B406
rotate_map_graphics_all_rows_left = $B3C7

.segment "CODE"
.org $B293
build_map_graphics_left_frames:
    sep #$30
    .i8
    ldx #$07
build_map_graphics_left_frames_c1b297:
    jsr rotate_map_graphics_all_rows_left
    dex
    bne build_map_graphics_left_frames_c1b297
    jmp advance_map_graphics_frame_pointer
