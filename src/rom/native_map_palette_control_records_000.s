.setcpu "65816"
.segment "CODE"
.org $087B
native_map_palette_control_records_000:
palette_animation_command_000:
    .byte (0 << 5) | (2 << 3) | 7
palette_animation_command_001:
    .byte (0 << 5) | (2 << 3) | 7
palette_animation_command_002:
    .byte (0 << 5) | (2 << 3) | 6
palette_animation_command_003:
    .byte (1 << 5) | (1 << 3) | 7
palette_animation_command_004:
    .byte (1 << 5) | (3 << 3) | 1
palette_animation_command_005:
    .byte (1 << 5) | (0 << 3) | 6
