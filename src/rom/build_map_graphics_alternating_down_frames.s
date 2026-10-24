; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

advance_map_graphics_frame_pointer = $B406
shift_map_graphics_even_columns_down = $B546
shift_map_graphics_odd_columns_down = $B4DF

.segment "CODE"
.org $B2E4
build_map_graphics_alternating_down_frames:
    sep #$30
    .i8
    ldx #$07
build_map_graphics_alternating_down_frames_c1b2e8:
    jsr shift_map_graphics_odd_columns_down
    jsr shift_map_graphics_even_columns_down
    dex
    bne build_map_graphics_alternating_down_frames_c1b2e8
    jsr shift_map_graphics_odd_columns_down
    jmp advance_map_graphics_frame_pointer
