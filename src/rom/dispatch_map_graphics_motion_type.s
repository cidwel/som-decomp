; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

build_map_graphics_alternating_down_frames = $B2E4
build_map_graphics_alternating_left_frames = $B277
build_map_graphics_alternating_right_frames = $B285
build_map_graphics_alternating_up_frames = $B2D1
build_map_graphics_left_frames = $B293
build_map_graphics_right_frames = $B2A0
build_map_graphics_transposed_wave_frames = $B5AD
build_map_graphics_wave_frames = $B687

.segment "CODE"
.org $B2AD
dispatch_map_graphics_motion_type:
    .a8
    cmp #$04
    bcs dispatch_map_graphics_motion_type_c1b2bf
    .a8
    cmp #$00
    beq build_map_graphics_alternating_left_frames
    .a8
    cmp #$01
    beq build_map_graphics_alternating_right_frames
    .a8
    cmp #$02
    beq build_map_graphics_left_frames
    bra build_map_graphics_right_frames
dispatch_map_graphics_motion_type_c1b2bf:
    beq dispatch_map_graphics_motion_type_c1b2cb
    .a8
    cmp #$05
    beq dispatch_map_graphics_motion_type_c1b2ce
    .a8
    cmp #$06
    beq build_map_graphics_alternating_up_frames
    bra build_map_graphics_alternating_down_frames
dispatch_map_graphics_motion_type_c1b2cb:
    jmp build_map_graphics_wave_frames
dispatch_map_graphics_motion_type_c1b2ce:
    jmp build_map_graphics_transposed_wave_frames
