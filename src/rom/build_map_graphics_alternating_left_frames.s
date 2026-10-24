; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

rotate_map_graphics_even_rows_left = $B2F7
rotate_map_graphics_odd_rows_left = $B35F

.segment "CODE"
.org $B277
build_map_graphics_alternating_left_frames:
    sep #$30
    .i8
    ldx #$08
build_map_graphics_alternating_left_frames_c1b27b:
    jsr rotate_map_graphics_even_rows_left
    jsr rotate_map_graphics_odd_rows_left
    dex
    bne build_map_graphics_alternating_left_frames_c1b27b
    rts
