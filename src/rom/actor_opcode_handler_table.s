; Original actor bytecode handler pointers; see docs/monster-ai-opcodes.md.
; Unrecovered names explicitly mark handlers without matching sources.
.setcpu "65816"

restart_actor_program_on_script_error = $0100
jump_actor_script_after_1_bytes = $0285
actor_script_call = $02B7
actor_script_return = $02F8
actor_script_increment_variable_0 = $05DA
actor_script_increment_variable_1 = $05E4
actor_script_increment_variable_2 = $05EE
actor_script_increment_variable_3 = $05F8
actor_script_decrement_variable_0 = $0602
actor_script_decrement_variable_1 = $060C
actor_script_decrement_variable_2 = $0616
actor_script_decrement_variable_3 = $0620
actor_script_copy_variable_0_to_1 = $062A
actor_script_copy_variable_0_to_2 = $0633
actor_script_copy_variable_0_to_3 = $063C
actor_script_if_variable_0_nonzero = $0645
actor_script_if_variable_1_nonzero = $0655
actor_script_if_variable_2_nonzero = $0665
actor_script_if_variable_3_nonzero = $0675
actor_script_if_variable_0_zero = $0685
actor_script_if_variable_1_zero = $0695
actor_script_if_variable_2_zero = $06A5
actor_script_if_variable_3_zero = $06B5
actor_script_if_no_lane_hero_vertical = $06FD
actor_script_if_no_lane_hero_horizontal = $0745
actor_script_if_no_lane_raw_e006_vertical = $078D
actor_script_if_no_lane_raw_e006_horizontal = $07D5
actor_script_if_no_lane_monster_vertical = $081D
actor_script_if_no_lane_monster_horizontal = $0865
actor_script_if_no_hero_class_1 = $08AC
actor_script_if_no_hero_class_2 = $08F3
actor_script_if_no_hero_class_4 = $093A
actor_script_if_no_hero_class_8 = $0981
actor_script_if_no_hero_within_class_2 = $0A01
actor_script_if_no_hero_within_class_4 = $0A4A
actor_script_if_no_hero_within_class_8 = $0A93
actor_script_if_no_hero_on_screen = $0ADC
actor_script_if_no_ally_class_1 = $0B23
actor_script_if_no_ally_class_2 = $0B6A
actor_script_if_no_ally_class_4 = $0BB1
actor_script_if_no_ally_class_8 = $0BF8
actor_script_if_no_ally_within_class_2 = $0C41
actor_script_if_no_ally_within_class_4 = $0C8A
actor_script_if_no_ally_within_class_8 = $0CD3
actor_script_if_no_ally_below_class_32_or_select_current = $0D20
actor_script_if_visible_actor_count_above_byte = $0D63
actor_script_if_no_monster_class_1 = $0DB1
actor_script_if_no_monster_class_2 = $0DF8
actor_script_if_no_monster_class_4 = $0E3F
actor_script_if_no_monster_class_8 = $0E86
actor_script_if_no_monster_within_class_2 = $0ECF
actor_script_if_no_monster_within_class_4 = $0F18
actor_script_if_no_monster_within_class_8 = $0F61
actor_script_if_not_current_lane_mask_f3_within_8_op_66 = $0F71
actor_script_if_not_current_lane_mask_f3_within_4_op_68 = $0F90
actor_script_if_not_current_lane_mask_f3_within_48_op_6a = $0FAF
actor_script_if_not_current_lane_mask_fc_within_8_op_6f = $0FCE
actor_script_if_not_current_lane_mask_fc_within_4_op_71 = $0FED
actor_script_if_not_current_lane_mask_fc_within_48_op_73 = $100C
actor_script_if_not_second_lane_mask_f3_within_8_op_67 = $102B
actor_script_if_not_second_lane_mask_f3_within_4_op_69 = $104A
actor_script_if_not_second_lane_mask_f3_within_48_op_6b = $1069
actor_script_if_not_second_lane_mask_fc_within_8_op_70 = $1088
actor_script_if_not_second_lane_mask_fc_within_4_op_72 = $10A7
actor_script_if_not_second_lane_mask_fc_within_48_op_74 = $10C6
actor_script_if_not_current_direction_bits_mask_08_op_75 = $10E5
actor_script_if_not_current_direction_bits_mask_04_op_77 = $10FB
actor_script_if_not_current_direction_bits_mask_02_op_79 = $1111
actor_script_if_not_current_direction_bits_mask_01_op_7b = $1127
actor_script_if_not_second_direction_bits_mask_03_op_76 = $113D
actor_script_if_not_second_direction_bits_mask_03_op_78 = $1153
actor_script_if_not_second_direction_bits_mask_03_op_7a = $1169
actor_script_if_not_second_direction_bits_mask_03_op_7c = $117F
actor_script_if_not_current_equal_class_1_op_34 = $1195
actor_script_if_not_current_equal_class_2_op_3a = $11AA
actor_script_if_not_current_equal_class_4_op_40 = $11BF
actor_script_if_not_current_equal_class_8_op_46 = $11D4
actor_script_if_not_current_within_class_2_op_4c = $11E9
actor_script_if_not_current_within_class_4_op_51 = $1200
actor_script_if_not_current_within_class_8_op_56 = $1217
actor_script_if_not_current_within_class_48_op_59 = $122E
actor_script_if_not_current_distance_bits_class_16_op_5a = $1245
actor_script_if_not_second_within_class_48_op_5b = $125A
actor_script_if_not_second_distance_bits_class_16_op_5c = $1271
actor_script_if_not_second_equal_class_1_op_35 = $1286
actor_script_if_not_second_equal_class_2_op_3b = $129B
actor_script_if_not_second_equal_class_4_op_41 = $12B0
actor_script_if_not_second_equal_class_8_op_47 = $12C5
actor_script_if_not_second_within_class_2_op_4d = $12DA
actor_script_if_not_second_within_class_4_op_52 = $12F1
actor_script_if_not_second_within_class_8_op_57 = $1308
actor_script_set_current_target_hero_class_1 = $131F
actor_script_set_current_target_hero_class_2 = $1331
actor_script_set_current_target_hero_class_4 = $1343
actor_script_set_current_target_hero_class_8 = $1355
actor_script_set_current_target_hero_beyond_class_8 = $1367
actor_script_set_current_target_hero_within_class_2 = $1379
actor_script_set_current_target_hero_within_class_4 = $138B
actor_script_set_current_target_hero_within_class_8 = $139D
actor_script_set_current_target_ally_class_1 = $13AF
actor_script_set_current_target_ally_class_2 = $13C1
actor_script_set_current_target_ally_class_4 = $13D3
actor_script_set_current_target_ally_class_8 = $13E5
actor_script_set_current_target_ally_within_class_2 = $13F7
actor_script_set_current_target_ally_within_class_4 = $1409
actor_script_set_current_target_ally_within_class_8 = $141B
actor_script_set_current_target_monster_class_1 = $142D
actor_script_set_current_target_monster_class_2 = $143F
actor_script_set_current_target_monster_class_4 = $1451
actor_script_set_current_target_monster_class_8 = $1463
actor_script_set_current_target_monster_within_class_2 = $1475
actor_script_set_current_target_monster_within_class_4 = $1487
actor_script_set_current_target_monster_within_class_8 = $1499
actor_script_current_target_self = $14AB
actor_script_current_target_copy_second = $14BC
actor_script_current_target_clear = $14C5
actor_script_set_second_target_hero_class_1 = $14CD
actor_script_set_second_target_hero_class_2 = $14DF
actor_script_set_second_target_hero_class_4 = $14F1
actor_script_set_second_target_hero_class_8 = $1503
actor_script_set_second_target_hero_beyond_class_8 = $1515
actor_script_set_second_target_hero_within_class_2 = $1527
actor_script_set_second_target_hero_within_class_4 = $1539
actor_script_set_second_target_hero_within_class_8 = $154B
actor_script_set_second_target_ally_class_1 = $155D
actor_script_set_second_target_ally_class_2 = $156F
actor_script_set_second_target_ally_class_4 = $1581
actor_script_set_second_target_ally_class_8 = $1593
actor_script_set_second_target_ally_within_class_2 = $15A5
actor_script_set_second_target_ally_within_class_4 = $15B7
actor_script_set_second_target_ally_within_class_8 = $15C9
actor_script_set_second_target_monster_class_1 = $15DB
actor_script_set_second_target_monster_class_2 = $15ED
actor_script_set_second_target_monster_class_4 = $15FF
actor_script_set_second_target_monster_class_8 = $1611
actor_script_set_second_target_monster_within_class_2 = $1623
actor_script_set_second_target_self = $1635
actor_script_copy_current_to_second_target = $1646
actor_script_clear_second_target = $164F
actor_script_copy_variable_zero_to_charge_stage = $1657
actor_script_toggle_flash_and_refresh_appearance = $1673
actor_script_set_variable_0 = $16B8
actor_script_set_variable_1 = $16C7
actor_script_set_variable_2 = $16D6
actor_script_set_variable_3 = $16E5
actor_script_random_variable_0 = $171D
actor_script_random_variable_1 = $1726
actor_script_random_variable_2 = $172F
actor_script_random_variable_3 = $1738
actor_script_if_variable_0_not_equal = $1741
actor_script_if_variable_1_not_equal = $1756
actor_script_if_variable_2_not_equal = $176B
actor_script_if_variable_3_not_equal = $1780
actor_script_if_variable_0_equal = $1795
actor_script_if_variable_1_equal = $17AA
actor_script_if_variable_2_equal = $17BF
actor_script_if_variable_3_equal = $17D4
actor_script_if_variable_0_greater = $17E9
actor_script_if_variable_1_greater = $1800
actor_script_if_variable_2_greater = $1817
actor_script_if_variable_3_greater = $182E
actor_script_if_variable_0_less = $1845
actor_script_if_variable_1_less = $185A
actor_script_if_variable_2_less = $186F
actor_script_if_variable_3_less = $1884
actor_script_explicit_slot_distance_equal_class_1 = $1899
actor_script_explicit_slot_distance_equal_class_2 = $18C4
actor_script_explicit_slot_distance_equal_class_4 = $18EF
actor_script_explicit_slot_distance_equal_class_8 = $191A
actor_script_set_field_19b_from_byte = $19F1
actor_script_command_c1_current_forward_low_nibble = $19FE
actor_script_command_c1_second_forward_low_nibble = $1A40
actor_script_command_c1_current_reverse_low_nibble = $1A82
actor_script_command_c1_second_reverse_low_nibble = $1AC8
actor_script_command_c1_current_forward_high_code = $1B0E
actor_script_command_c1_current_reverse_high_code = $1B51
actor_script_command_c1_current_forward_high_nibble = $1B98
actor_script_command_c1_current_reverse_high_nibble = $1BDC
actor_script_command_c1_from_velocity_and_native_mask = $1C24
actor_script_write_hop_command = $1C8E
actor_script_controller_distance_gate = $1CB0
actor_script_controller_near_distance_gate = $1CFF
actor_script_command_01 = $1D52
actor_script_command_02_copy_field_1c0_if_gauge_zero = $1D5C
actor_script_command_02_clear_flag_if_gauge_zero = $1D74
actor_script_command_02_argument_if_gauge_zero = $1D8E
actor_script_command_03 = $1DAA
actor_script_command_07_clear_flag_if_set = $1DB4
actor_script_command_06_set_flag_if_global_byte = $1DCD
actor_script_write_command_04 = $1DF8
actor_script_write_pose_command = $1E02
actor_script_cast_single_second_target = $1E47
actor_script_cast_group_from_fixed_first_candidate = $1E98
actor_script_write_command_43 = $1F37
actor_script_write_command_81 = $1F4B
actor_script_command_c0_quantized_low_x = $1F66
actor_script_command_82_two_arguments = $1F98
actor_script_apply_selected_effect_to_current_target = $1FC8
actor_script_current_target_from_literal_byte = $1FD1
actor_script_second_target_from_literal_byte = $1FDE
actor_script_if_byte_field_mask_nonzero = $2042
actor_script_if_byte_field_mask_zero = $205A
actor_script_if_byte_field_less = $2072
actor_script_if_byte_field_greater = $208A
actor_script_if_word_field_mask_nonzero = $20A4
actor_script_if_word_field_mask_zero = $20BE
actor_script_if_word_field_less = $20D8
actor_script_if_word_field_greater = $20F2
actor_script_byte_field_or = $210E
actor_script_byte_field_and = $2124
actor_script_byte_field_set = $213A
actor_script_if_saved_position_same = $214D
actor_script_if_saved_position_changed = $2168
actor_script_save_current_position = $2183
actor_script_if_reference_outside_rectangle = $2194
actor_script_if_reference_inside_rectangle = $21DD
actor_script_compare_shared_charge_stage = $2226

.segment "CODE"
.org $2257
actor_opcode_handler_table:
    .word actor_script_return ; opcode $00
    .word jump_actor_script_after_1_bytes ; opcode $01
    .word actor_script_if_variable_0_nonzero ; opcode $02
    .word actor_script_if_variable_1_nonzero ; opcode $03
    .word actor_script_if_variable_2_nonzero ; opcode $04
    .word actor_script_if_variable_3_nonzero ; opcode $05
    .word actor_script_if_variable_0_zero ; opcode $06
    .word actor_script_if_variable_1_zero ; opcode $07
    .word actor_script_if_variable_2_zero ; opcode $08
    .word actor_script_if_variable_3_zero ; opcode $09
    .word actor_script_if_variable_0_not_equal ; opcode $0A
    .word actor_script_if_variable_1_not_equal ; opcode $0B
    .word actor_script_if_variable_2_not_equal ; opcode $0C
    .word actor_script_if_variable_3_not_equal ; opcode $0D
    .word actor_script_if_variable_0_equal ; opcode $0E
    .word actor_script_if_variable_1_equal ; opcode $0F
    .word actor_script_if_variable_2_equal ; opcode $10
    .word actor_script_if_variable_3_equal ; opcode $11
    .word actor_script_if_variable_0_greater ; opcode $12
    .word actor_script_if_variable_1_greater ; opcode $13
    .word actor_script_if_variable_2_greater ; opcode $14
    .word actor_script_if_variable_3_greater ; opcode $15
    .word actor_script_if_variable_0_less ; opcode $16
    .word actor_script_if_variable_1_less ; opcode $17
    .word actor_script_if_variable_2_less ; opcode $18
    .word actor_script_if_variable_3_less ; opcode $19
    .word actor_script_increment_variable_0 ; opcode $1A
    .word actor_script_increment_variable_1 ; opcode $1B
    .word actor_script_increment_variable_2 ; opcode $1C
    .word actor_script_increment_variable_3 ; opcode $1D
    .word actor_script_decrement_variable_0 ; opcode $1E
    .word actor_script_decrement_variable_1 ; opcode $1F
    .word actor_script_decrement_variable_2 ; opcode $20
    .word actor_script_decrement_variable_3 ; opcode $21
    .word actor_script_copy_variable_0_to_1 ; opcode $22
    .word actor_script_copy_variable_0_to_2 ; opcode $23
    .word actor_script_copy_variable_0_to_3 ; opcode $24
    .word actor_script_set_variable_0 ; opcode $25
    .word actor_script_set_variable_1 ; opcode $26
    .word actor_script_set_variable_2 ; opcode $27
    .word actor_script_set_variable_3 ; opcode $28
    .word actor_script_random_variable_0 ; opcode $29
    .word actor_script_random_variable_1 ; opcode $2A
    .word actor_script_random_variable_2 ; opcode $2B
    .word actor_script_random_variable_3 ; opcode $2C
    .word actor_script_if_byte_field_mask_nonzero ; opcode $2D
    .word actor_script_if_byte_field_mask_zero ; opcode $2E
    .word actor_script_if_byte_field_less ; opcode $2F
    .word actor_script_if_byte_field_greater ; opcode $30
    .word actor_script_if_no_hero_class_1 ; opcode $31
    .word actor_script_if_no_ally_class_1 ; opcode $32
    .word actor_script_if_no_monster_class_1 ; opcode $33
    .word actor_script_if_not_current_equal_class_1_op_34 ; opcode $34
    .word actor_script_if_not_second_equal_class_1_op_35 ; opcode $35
    .word actor_script_explicit_slot_distance_equal_class_1 ; opcode $36
    .word actor_script_if_no_hero_class_2 ; opcode $37
    .word actor_script_if_no_ally_class_2 ; opcode $38
    .word actor_script_if_no_monster_class_2 ; opcode $39
    .word actor_script_if_not_current_equal_class_2_op_3a ; opcode $3A
    .word actor_script_if_not_second_equal_class_2_op_3b ; opcode $3B
    .word actor_script_explicit_slot_distance_equal_class_2 ; opcode $3C
    .word actor_script_if_no_hero_class_4 ; opcode $3D
    .word actor_script_if_no_ally_class_4 ; opcode $3E
    .word actor_script_if_no_monster_class_4 ; opcode $3F
    .word actor_script_if_not_current_equal_class_4_op_40 ; opcode $40
    .word actor_script_if_not_second_equal_class_4_op_41 ; opcode $41
    .word actor_script_explicit_slot_distance_equal_class_4 ; opcode $42
    .word actor_script_if_no_hero_class_8 ; opcode $43
    .word actor_script_if_no_ally_class_8 ; opcode $44
    .word actor_script_if_no_monster_class_8 ; opcode $45
    .word actor_script_if_not_current_equal_class_8_op_46 ; opcode $46
    .word actor_script_if_not_second_equal_class_8_op_47 ; opcode $47
    .word actor_script_explicit_slot_distance_equal_class_8 ; opcode $48
    .word actor_script_if_no_hero_within_class_2 ; opcode $49
    .word actor_script_if_no_ally_within_class_2 ; opcode $4A
    .word actor_script_if_no_monster_within_class_2 ; opcode $4B
    .word actor_script_if_not_current_within_class_2_op_4c ; opcode $4C
    .word actor_script_if_not_second_within_class_2_op_4d ; opcode $4D
    .word actor_script_if_no_hero_within_class_4 ; opcode $4E
    .word actor_script_if_no_ally_within_class_4 ; opcode $4F
    .word actor_script_if_no_monster_within_class_4 ; opcode $50
    .word actor_script_if_not_current_within_class_4_op_51 ; opcode $51
    .word actor_script_if_not_second_within_class_4_op_52 ; opcode $52
    .word actor_script_if_no_hero_within_class_8 ; opcode $53
    .word actor_script_if_no_ally_within_class_8 ; opcode $54
    .word actor_script_if_no_monster_within_class_8 ; opcode $55
    .word actor_script_if_not_current_within_class_8_op_56 ; opcode $56
    .word actor_script_if_not_second_within_class_8_op_57 ; opcode $57
    .word actor_script_if_no_hero_on_screen ; opcode $58
    .word actor_script_if_not_current_within_class_48_op_59 ; opcode $59
    .word actor_script_if_not_current_distance_bits_class_16_op_5a ; opcode $5A
    .word actor_script_if_not_second_within_class_48_op_5b ; opcode $5B
    .word actor_script_if_not_second_distance_bits_class_16_op_5c ; opcode $5C
    .word actor_script_set_current_target_hero_beyond_class_8 ; opcode $5D
    .word actor_script_set_second_target_hero_beyond_class_8 ; opcode $5E
    .word actor_script_if_reference_outside_rectangle ; opcode $5F
    .word actor_script_if_reference_inside_rectangle ; opcode $60
    .word actor_script_apply_selected_effect_to_current_target ; opcode $61
    .word actor_script_controller_distance_gate ; opcode $62
    .word actor_script_if_no_lane_hero_vertical ; opcode $63
    .word actor_script_if_no_lane_raw_e006_vertical ; opcode $64
    .word actor_script_if_no_lane_monster_vertical ; opcode $65
    .word actor_script_if_not_current_lane_mask_f3_within_8_op_66 ; opcode $66
    .word actor_script_if_not_second_lane_mask_f3_within_8_op_67 ; opcode $67
    .word actor_script_if_not_current_lane_mask_f3_within_4_op_68 ; opcode $68
    .word actor_script_if_not_second_lane_mask_f3_within_4_op_69 ; opcode $69
    .word actor_script_if_not_current_lane_mask_f3_within_48_op_6a ; opcode $6A
    .word actor_script_if_not_second_lane_mask_f3_within_48_op_6b ; opcode $6B
    .word actor_script_if_no_lane_hero_horizontal ; opcode $6C
    .word actor_script_if_no_lane_raw_e006_horizontal ; opcode $6D
    .word actor_script_if_no_lane_monster_horizontal ; opcode $6E
    .word actor_script_if_not_current_lane_mask_fc_within_8_op_6f ; opcode $6F
    .word actor_script_if_not_second_lane_mask_fc_within_8_op_70 ; opcode $70
    .word actor_script_if_not_current_lane_mask_fc_within_4_op_71 ; opcode $71
    .word actor_script_if_not_second_lane_mask_fc_within_4_op_72 ; opcode $72
    .word actor_script_if_not_current_lane_mask_fc_within_48_op_73 ; opcode $73
    .word actor_script_if_not_second_lane_mask_fc_within_48_op_74 ; opcode $74
    .word actor_script_if_not_current_direction_bits_mask_08_op_75 ; opcode $75
    .word actor_script_if_not_second_direction_bits_mask_03_op_76 ; opcode $76
    .word actor_script_if_not_current_direction_bits_mask_04_op_77 ; opcode $77
    .word actor_script_if_not_second_direction_bits_mask_03_op_78 ; opcode $78
    .word actor_script_if_not_current_direction_bits_mask_02_op_79 ; opcode $79
    .word actor_script_if_not_second_direction_bits_mask_03_op_7a ; opcode $7A
    .word actor_script_if_not_current_direction_bits_mask_01_op_7b ; opcode $7B
    .word actor_script_if_not_second_direction_bits_mask_03_op_7c ; opcode $7C
    .word restart_actor_program_on_script_error ; opcode $7D
    .word restart_actor_program_on_script_error ; opcode $7E
    .word restart_actor_program_on_script_error ; opcode $7F
    .word restart_actor_program_on_script_error ; opcode $80
    .word restart_actor_program_on_script_error ; opcode $81
    .word restart_actor_program_on_script_error ; opcode $82
    .word restart_actor_program_on_script_error ; opcode $83
    .word restart_actor_program_on_script_error ; opcode $84
    .word restart_actor_program_on_script_error ; opcode $85
    .word restart_actor_program_on_script_error ; opcode $86
    .word restart_actor_program_on_script_error ; opcode $87
    .word restart_actor_program_on_script_error ; opcode $88
    .word restart_actor_program_on_script_error ; opcode $89
    .word restart_actor_program_on_script_error ; opcode $8A
    .word restart_actor_program_on_script_error ; opcode $8B
    .word restart_actor_program_on_script_error ; opcode $8C
    .word restart_actor_program_on_script_error ; opcode $8D
    .word restart_actor_program_on_script_error ; opcode $8E
    .word restart_actor_program_on_script_error ; opcode $8F
    .word restart_actor_program_on_script_error ; opcode $90
    .word restart_actor_program_on_script_error ; opcode $91
    .word restart_actor_program_on_script_error ; opcode $92
    .word restart_actor_program_on_script_error ; opcode $93
    .word restart_actor_program_on_script_error ; opcode $94
    .word restart_actor_program_on_script_error ; opcode $95
    .word restart_actor_program_on_script_error ; opcode $96
    .word restart_actor_program_on_script_error ; opcode $97
    .word restart_actor_program_on_script_error ; opcode $98
    .word restart_actor_program_on_script_error ; opcode $99
    .word restart_actor_program_on_script_error ; opcode $9A
    .word restart_actor_program_on_script_error ; opcode $9B
    .word restart_actor_program_on_script_error ; opcode $9C
    .word actor_script_if_saved_position_same ; opcode $9D
    .word actor_script_if_saved_position_changed ; opcode $9E
    .word actor_script_save_current_position ; opcode $9F
    .word actor_script_current_target_clear ; opcode $A0
    .word actor_script_current_target_copy_second ; opcode $A1
    .word restart_actor_program_on_script_error ; opcode $A2
    .word restart_actor_program_on_script_error ; opcode $A3
    .word actor_script_current_target_self ; opcode $A4
    .word actor_script_set_current_target_hero_class_1 ; opcode $A5
    .word actor_script_set_current_target_ally_class_1 ; opcode $A6
    .word actor_script_set_current_target_monster_class_1 ; opcode $A7
    .word actor_script_set_current_target_hero_class_2 ; opcode $A8
    .word actor_script_set_current_target_ally_class_2 ; opcode $A9
    .word actor_script_set_current_target_monster_class_2 ; opcode $AA
    .word actor_script_set_current_target_hero_class_4 ; opcode $AB
    .word actor_script_set_current_target_ally_class_4 ; opcode $AC
    .word actor_script_set_current_target_monster_class_4 ; opcode $AD
    .word actor_script_set_current_target_hero_class_8 ; opcode $AE
    .word actor_script_set_current_target_ally_class_8 ; opcode $AF
    .word actor_script_set_current_target_monster_class_8 ; opcode $B0
    .word actor_script_set_current_target_hero_within_class_2 ; opcode $B1
    .word actor_script_set_current_target_ally_within_class_2 ; opcode $B2
    .word actor_script_set_current_target_monster_within_class_2 ; opcode $B3
    .word actor_script_set_current_target_hero_within_class_4 ; opcode $B4
    .word actor_script_set_current_target_ally_within_class_4 ; opcode $B5
    .word actor_script_set_current_target_monster_within_class_4 ; opcode $B6
    .word actor_script_set_current_target_hero_within_class_8 ; opcode $B7
    .word actor_script_set_current_target_ally_within_class_8 ; opcode $B8
    .word actor_script_set_current_target_monster_within_class_8 ; opcode $B9
    .word actor_script_if_word_field_mask_nonzero ; opcode $BA
    .word actor_script_if_word_field_mask_zero ; opcode $BB
    .word actor_script_if_word_field_less ; opcode $BC
    .word actor_script_if_word_field_greater ; opcode $BD
    .word actor_script_command_c1_current_forward_high_code ; opcode $BE
    .word actor_script_command_c1_current_reverse_high_code ; opcode $BF
    .word actor_script_clear_second_target ; opcode $C0
    .word actor_script_copy_current_to_second_target ; opcode $C1
    .word restart_actor_program_on_script_error ; opcode $C2
    .word restart_actor_program_on_script_error ; opcode $C3
    .word actor_script_set_second_target_self ; opcode $C4
    .word actor_script_set_second_target_hero_class_1 ; opcode $C5
    .word actor_script_set_second_target_ally_class_1 ; opcode $C6
    .word actor_script_set_second_target_monster_class_1 ; opcode $C7
    .word actor_script_set_second_target_hero_class_2 ; opcode $C8
    .word actor_script_set_second_target_ally_class_2 ; opcode $C9
    .word actor_script_set_second_target_monster_class_2 ; opcode $CA
    .word actor_script_set_second_target_hero_class_4 ; opcode $CB
    .word actor_script_set_second_target_ally_class_4 ; opcode $CC
    .word actor_script_set_second_target_monster_class_4 ; opcode $CD
    .word actor_script_set_second_target_hero_class_8 ; opcode $CE
    .word actor_script_set_second_target_ally_class_8 ; opcode $CF
    .word actor_script_set_second_target_monster_class_8 ; opcode $D0
    .word actor_script_set_second_target_hero_within_class_2 ; opcode $D1
    .word actor_script_set_second_target_ally_within_class_2 ; opcode $D2
    .word actor_script_set_second_target_monster_within_class_2 ; opcode $D3
    .word actor_script_set_second_target_hero_within_class_4 ; opcode $D4
    .word actor_script_set_second_target_ally_within_class_4 ; opcode $D5
    .word actor_script_if_no_ally_below_class_32_or_select_current ; opcode $D6
    .word actor_script_set_second_target_hero_within_class_8 ; opcode $D7
    .word actor_script_set_second_target_ally_within_class_8 ; opcode $D8
    .word restart_actor_program_on_script_error ; opcode $D9
    .word actor_script_byte_field_or ; opcode $DA
    .word actor_script_byte_field_and ; opcode $DB
    .word actor_script_byte_field_set ; opcode $DC
    .word restart_actor_program_on_script_error ; opcode $DD
    .word restart_actor_program_on_script_error ; opcode $DE
    .word actor_script_command_02_clear_flag_if_gauge_zero ; opcode $DF
    .word actor_script_write_hop_command ; opcode $E0
    .word actor_script_command_01 ; opcode $E1
    .word actor_script_write_pose_command ; opcode $E2
    .word actor_script_command_c1_from_velocity_and_native_mask ; opcode $E3
    .word actor_script_command_c1_current_forward_low_nibble ; opcode $E4
    .word actor_script_command_c1_second_forward_low_nibble ; opcode $E5
    .word actor_script_command_c1_current_reverse_low_nibble ; opcode $E6
    .word actor_script_command_c1_second_reverse_low_nibble ; opcode $E7
    .word actor_script_command_02_copy_field_1c0_if_gauge_zero ; opcode $E8
    .word actor_script_cast_single_second_target ; opcode $E9
    .word actor_script_cast_group_from_fixed_first_candidate ; opcode $EA
    .word actor_script_command_c0_quantized_low_x ; opcode $EB
    .word actor_script_command_03 ; opcode $EC
    .word actor_script_write_command_43 ; opcode $ED
    .word actor_script_write_command_04 ; opcode $EE
    .word actor_script_write_command_81 ; opcode $EF
    .word actor_script_current_target_from_literal_byte ; opcode $F0
    .word actor_script_second_target_from_literal_byte ; opcode $F1
    .word actor_script_compare_shared_charge_stage ; opcode $F2
    .word actor_script_command_06_set_flag_if_global_byte ; opcode $F3
    .word actor_script_command_07_clear_flag_if_set ; opcode $F4
    .word actor_script_if_visible_actor_count_above_byte ; opcode $F5
    .word actor_script_controller_near_distance_gate ; opcode $F6
    .word actor_script_command_82_two_arguments ; opcode $F7
    .word restart_actor_program_on_script_error ; opcode $F8
    .word actor_script_set_field_19b_from_byte ; opcode $F9
    .word actor_script_command_02_argument_if_gauge_zero ; opcode $FA
    .word actor_script_copy_variable_zero_to_charge_stage ; opcode $FB
    .word actor_script_toggle_flash_and_refresh_appearance ; opcode $FC
    .word actor_script_command_c1_current_forward_high_nibble ; opcode $FD
    .word actor_script_command_c1_current_reverse_high_nibble ; opcode $FE
    .word actor_script_call ; opcode $FF
