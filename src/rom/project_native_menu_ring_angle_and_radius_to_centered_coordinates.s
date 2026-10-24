; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-geometry.md.
.setcpu "65816"
.smart
.a8
.i16

accumulate_native_ring_vertical_component = $FC54
negate_native_ring_component_then_accumulate_vertical_center = $FC50
project_native_ring_complementary_quarter_wave_component = $FC5C
select_native_ring_quarter_wave_index_then_fall_through = $FC73

.segment "CODE"
.org $FC00
project_native_menu_ring_angle_and_radius_to_centered_coordinates:
    rep #$30
    lda a:$1868
    .a16
    and #$03FF
    pha
    .a16
    and #$00FF
    tay
    pla
    xba
    .a16
    and #$00FF
    bne project_native_menu_ring_angle_and_radius_to_centered_coordinates_d9fc1f
    jsr select_native_ring_quarter_wave_index_then_fall_through
    jsr accumulate_native_ring_vertical_component
    jsr project_native_ring_complementary_quarter_wave_component
    bra project_native_menu_ring_angle_and_radius_to_centered_coordinates_d9fc44
project_native_menu_ring_angle_and_radius_to_centered_coordinates_d9fc1f:
    dec
    bne project_native_menu_ring_angle_and_radius_to_centered_coordinates_d9fc2d
    jsr project_native_ring_complementary_quarter_wave_component
    jsr accumulate_native_ring_vertical_component
    jsr select_native_ring_quarter_wave_index_then_fall_through
    bra project_native_menu_ring_angle_and_radius_to_centered_coordinates_d9fc48
project_native_menu_ring_angle_and_radius_to_centered_coordinates_d9fc2d:
    dec
    bne project_native_menu_ring_angle_and_radius_to_centered_coordinates_d9fc3b
    jsr select_native_ring_quarter_wave_index_then_fall_through
    jsr negate_native_ring_component_then_accumulate_vertical_center
    jsr project_native_ring_complementary_quarter_wave_component
    bra project_native_menu_ring_angle_and_radius_to_centered_coordinates_d9fc48
project_native_menu_ring_angle_and_radius_to_centered_coordinates_d9fc3b:
    jsr project_native_ring_complementary_quarter_wave_component
    jsr negate_native_ring_component_then_accumulate_vertical_center
    jsr select_native_ring_quarter_wave_index_then_fall_through
project_native_menu_ring_angle_and_radius_to_centered_coordinates_d9fc44:
    .a16
    eor #$FFFF
    inc
project_native_menu_ring_angle_and_radius_to_centered_coordinates_d9fc48:
    clc
    adc a:$186C
    ldy a:$186A
    rtl
