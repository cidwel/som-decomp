; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5DFF
.include "src/rom/event_command_macros.inc"
event_526_command_5DFF:
    event_actor_walk 0, 1, 8
event_526_command_5E02:
    event_wait_idle 
event_526_command_5E03:
    event_gather 
event_526_command_5E04:
    event_actor_walk 128, 1, 63
event_526_command_5E07:
    event_actor_walk 1, 1, 16
event_526_command_5E0A:
    event_actor_walk 2, 1, 16
event_526_command_5E0D:
    event_actor_walk 3, 1, 16
event_526_command_5E10:
    event_wait_idle 
event_526_command_5E11:
    event_actor_walk 128, 1, 63
event_526_command_5E14:
    event_actor_animation 1, 174
event_526_command_5E17:
    event_actor_animation 2, 174
event_526_command_5E1A:
    event_actor_animation 3, 174
event_526_command_5E1D:
    event_wait_idle 
event_526_command_5E1E:
    event_toggle_visibility_04 
event_526_command_5E1F:
    event_set_flag 52, 3
event_526_command_5E22:
    event_change_map 837
event_526_command_5E24:
    event_call 247
event_526_command_5E26:
    event_jump 1796
event_526_command_5E28:
    event_end 
event_527_command_5E29:
    event_call 1280
event_527_command_5E2B:
    event_increment_flag 52
event_527_command_5E2D:
    event_redraw_pieces 
event_527_command_5E2E:
    event_jump 1830
event_527_command_5E30:
    event_end 
event_528_command_5E31:
    event_test_flag_range 53, 2, 15
event_528_command_5E34:
    event_jump 0
event_528_command_5E36:
    event_set_flag 53, 2
event_528_command_5E39:
    event_redraw_pieces 
event_528_command_5E3A:
    event_end 
event_529_command_5E3B:
    event_test_flag_range 53, 3, 15
event_529_command_5E3E:
    event_jump 0
event_529_command_5E40:
    event_freeze 
event_529_command_5E41:
    event_call 1040
event_529_command_5E43:
    event_actor_walk 0, 2, 0
event_529_command_5E46:
    event_wait_idle 
event_529_command_5E47:
    event_gather 
event_529_command_5E48:
    event_actor_animation 1, 141
event_529_command_5E4B:
    event_actor_animation 2, 141
event_529_command_5E4E:
    event_actor_animation 3, 141
event_529_command_5E51:
    event_wait_idle 
event_529_command_5E52:
    event_end 
event_52A_command_5E53:
    event_test_flag_range 53, 3, 15
event_52A_command_5E56:
    event_jump 0
event_52A_command_5E58:
    event_call 1939
event_52A_command_5E5A:
    event_change_map 855
event_52A_command_5E5C:
    event_end 
event_52B_command_5E5D:
    event_test_flag_range 53, 3, 15
event_52B_command_5E60:
    event_jump 0
event_52B_command_5E62:
    event_freeze 
event_52B_command_5E63:
    event_call 1040
event_52B_command_5E65:
    event_actor_walk 0, 0, 0
event_52B_command_5E68:
    event_wait_idle 
event_52B_command_5E69:
    event_gather 
event_52B_command_5E6A:
    event_actor_animation 1, 141
event_52B_command_5E6D:
    event_actor_animation 2, 141
event_52B_command_5E70:
    event_actor_animation 3, 141
event_52B_command_5E73:
    event_wait_idle 
event_52B_command_5E74:
    event_end 
event_52C_command_5E75:
    event_test_flag_range 53, 3, 15
event_52C_command_5E78:
    event_jump 0
event_52C_command_5E7A:
    event_call 1939
event_52C_command_5E7C:
    event_change_map 857
event_52C_command_5E7E:
    event_end 
event_52D_command_5E7F:
    event_call 7
event_52D_command_5E81:
    event_test_flag_range 53, 3, 15
event_52D_command_5E84:
    event_jump 0
event_52D_command_5E86:
    event_call 1937
event_52D_command_5E88:
    event_set_flag 53, 3
event_52D_command_5E8B:
    event_end 
event_52E_command_5E8C:
    event_test_flag_range 53, 4, 15
event_52E_command_5E8F:
    event_jump 0
event_52E_command_5E91:
    event_set_flag 53, 4
event_52E_command_5E94:
    event_call 1151
event_52E_command_5E96:
    event_call 1331
event_52E_command_5E98:
    event_call 1331
event_52E_command_5E9A:
    event_actor_walk 1, 0, 16
event_52E_command_5E9D:
    event_actor_walk 2, 0, 16
event_52E_command_5EA0:
    event_actor_walk 3, 0, 16
event_52E_command_5EA3:
    event_wait_idle 
event_52E_command_5EA4:
    event_screen 8
