; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

rotate_map_graphics_even_rows_right = $B32A
rotate_map_graphics_odd_rows_right = $B392

.segment "CODE"
.org $B285
build_map_graphics_alternating_right_frames:
    sep #$30
    .i8
    ldx #$08
build_map_graphics_alternating_right_frames_c1b289:
    jsr rotate_map_graphics_even_rows_right
    jsr rotate_map_graphics_odd_rows_right
    dex
    bne build_map_graphics_alternating_right_frames_c1b289
    rts
