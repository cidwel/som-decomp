; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

advance_map_graphics_frame_pointer = $B406
shift_map_graphics_even_columns_up = $B478
shift_map_graphics_odd_columns_up = $B411

.segment "CODE"
.org $B2D1
build_map_graphics_alternating_up_frames:
    sep #$30
    .i8
    ldx #$07
build_map_graphics_alternating_up_frames_c1b2d5:
    jsr shift_map_graphics_odd_columns_up
    jsr shift_map_graphics_even_columns_up
    dex
    bne build_map_graphics_alternating_up_frames_c1b2d5
    jsr shift_map_graphics_odd_columns_up
    jmp advance_map_graphics_frame_pointer
