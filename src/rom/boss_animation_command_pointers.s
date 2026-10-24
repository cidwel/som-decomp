; Numeric command destinations, derived from the26 recovered handlers.
.setcpu "65816"

toggle_boss_animation_horizontal_orientation = $1462
toggle_boss_animation_vertical_orientation = $146E
clear_boss_animation_horizontal_orientation = $147A
set_boss_animation_horizontal_orientation = $1492
clear_boss_animation_vertical_orientation = $1486
set_boss_animation_vertical_orientation = $149E
move_boss_from_animation_signed_offsets_with_collision_sliding = $14AA
restore_animation_selected_actor = $17E4
jump_animation_stream_absolute = $17E7
set_animation_relative_actor_parent = $17F0
replace_animation_and_restart_stream = $1802
request_animation_sound_parameter = $181A
set_animation_actor_byte_a2 = $1827
rewind_animation_stream = $1834
set_animation_target_control_if_eligible = $183A
place_animation_target_at_mirrored_signed_offsets = $186C
set_animation_target_motion_pair_and_rate = $18D6
set_animation_target_motion_triplet = $1906
create_animation_object_inheriting_orientation = $1933
clear_animation_work_buffer_with_fixed_source_dma = $19CE
enable_animation_actor_mode_bit_four = $1A06
clear_animation_actor_mode_bits_two_and_four = $1A12
dispatch_animation_selected_actor_command = $1A1E
set_animation_actor_field_22 = $1A2A
set_animation_actor_field_88 = $1A34
create_animation_object_with_explicit_flags = $1A3E

.segment "CODE"
.org $142E
boss_animation_command_pointers:
    .word toggle_boss_animation_horizontal_orientation
    .word toggle_boss_animation_vertical_orientation
    .word clear_boss_animation_horizontal_orientation
    .word set_boss_animation_horizontal_orientation
    .word clear_boss_animation_vertical_orientation
    .word set_boss_animation_vertical_orientation
    .word move_boss_from_animation_signed_offsets_with_collision_sliding
    .word restore_animation_selected_actor
    .word jump_animation_stream_absolute
    .word set_animation_relative_actor_parent
    .word replace_animation_and_restart_stream
    .word request_animation_sound_parameter
    .word set_animation_actor_byte_a2
    .word rewind_animation_stream
    .word set_animation_target_control_if_eligible
    .word place_animation_target_at_mirrored_signed_offsets
    .word set_animation_target_motion_pair_and_rate
    .word set_animation_target_motion_triplet
    .word create_animation_object_inheriting_orientation
    .word clear_animation_work_buffer_with_fixed_source_dma
    .word enable_animation_actor_mode_bit_four
    .word clear_animation_actor_mode_bits_two_and_four
    .word dispatch_animation_selected_actor_command
    .word set_animation_actor_field_22
    .word set_animation_actor_field_88
    .word create_animation_object_with_explicit_flags
