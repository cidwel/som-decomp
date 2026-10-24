.setcpu "65816"
.segment "CODE"
.org $0882
native_map_palette_control_records_007:
palette_animation_command_007:
    .byte (4 << 5) | (1 << 3) | 2
    .byte 33 ; palette identity
palette_animation_command_009:
    .byte (6 << 5) | (2 << 3) | 7
    .byte 0 ; palette identity
palette_animation_command_011:
    .byte (6 << 5) | (3 << 3) | 1
    .byte 7 ; palette identity
palette_animation_command_013:
    .byte (4 << 5) | (0 << 3) | 4
    .byte 21 ; palette identity
palette_animation_command_015:
    .byte (4 << 5) | (0 << 3) | 1
    .byte 23 ; palette identity
palette_animation_command_017:
    .byte (4 << 5) | (0 << 3) | 2
    .byte 24 ; palette identity
