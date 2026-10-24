; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

build_map_graphics_two_tile_alternating_left_frames = $C162
build_map_graphics_two_tile_alternating_mirror_frames = $C1BF
build_map_graphics_two_tile_alternating_right_frames = $C175
build_map_graphics_two_tile_down_frames = $C1E2
build_map_graphics_two_tile_left_frames = $C188
build_map_graphics_two_tile_mirror_frame = $C1CD
build_map_graphics_two_tile_right_until_pointer_zero = $C195
build_map_graphics_two_tile_up_frames = $C1D5

.segment "CODE"
.org $C1A1
dispatch_map_graphics_two_tile_motion_type:
    .a8
    cmp #$0C
    bcs dispatch_map_graphics_two_tile_motion_type_c1c1b3
    .a8
    cmp #$08
    beq build_map_graphics_two_tile_alternating_left_frames
    .a8
    cmp #$09
    beq build_map_graphics_two_tile_alternating_right_frames
    .a8
    cmp #$0A
    beq build_map_graphics_two_tile_left_frames
    bra build_map_graphics_two_tile_right_until_pointer_zero
dispatch_map_graphics_two_tile_motion_type_c1c1b3:
    beq build_map_graphics_two_tile_alternating_mirror_frames
    .a8
    cmp #$0D
    beq build_map_graphics_two_tile_mirror_frame
    .a8
    cmp #$0E
    beq build_map_graphics_two_tile_up_frames
    bra build_map_graphics_two_tile_down_frames
