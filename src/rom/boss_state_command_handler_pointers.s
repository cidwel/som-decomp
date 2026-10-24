; State opcodes00..15:22 handler pointers; all handler sources recovered; native target inventory and VM composition remain open.
.setcpu "65816"
boss_state_select_animation_operand = $37F8
boss_state_set_six_motion_words = $3802
boss_state_set_motion_callback_operand = $382F
boss_state_set_field_48_operand = $3839
boss_state_set_field_4a_operand = $3843
boss_state_set_duration_operand = $384D
boss_state_set_horizontal_orientation = $3857
boss_state_set_vertical_orientation = $3866
boss_state_toggle_horizontal_orientation = $3875
boss_state_toggle_vertical_orientation = $3881
boss_state_clear_horizontal_orientation = $388D
boss_state_clear_vertical_orientation = $3899
boss_state_set_field_1e3_operand = $38A5
boss_state_set_field_a7_operand = $38AF
boss_state_prepare_spell_operand = $38B9
boss_state_create_projectile_operand = $38CB
boss_state_call_native_operand = $390F
boss_state_store_actor_relative_word = $3922
boss_state_external_actor_command_operand = $3934
boss_state_prepare_attack_row_operand = $3940
boss_state_request_sound_operand = $394F
boss_state_jump_to_operand_pointer = $395C
.segment "CODE"
.org $37CC
boss_state_command_handler_pointers:
    .word boss_state_select_animation_operand, boss_state_set_six_motion_words, boss_state_set_motion_callback_operand, boss_state_set_field_48_operand
    .word boss_state_set_field_4a_operand, boss_state_set_duration_operand, boss_state_set_horizontal_orientation, boss_state_set_vertical_orientation
    .word boss_state_toggle_horizontal_orientation, boss_state_toggle_vertical_orientation, boss_state_clear_horizontal_orientation, boss_state_clear_vertical_orientation
    .word boss_state_set_field_1e3_operand, boss_state_set_field_a7_operand, boss_state_prepare_spell_operand, boss_state_create_projectile_operand
    .word boss_state_call_native_operand, boss_state_store_actor_relative_word, boss_state_external_actor_command_operand, boss_state_prepare_attack_row_operand
    .word boss_state_request_sound_operand, boss_state_jump_to_operand_pointer
