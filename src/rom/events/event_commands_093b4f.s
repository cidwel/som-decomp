; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3B4F
.include "src/rom/event_command_macros.inc"
event_127_command_3B4F:
    event_set_flag 166, 0
event_127_command_3B52:
    event_redraw_pieces 
event_127_command_3B53:
    event_set_flag 17, 8
event_127_command_3B56:
    event_refresh_objects 
event_127_command_3B57:
    event_jump 1535
event_127_command_3B59:
    event_end 
event_128_command_3B5A:
    event_test_flag_range 17, 7, 15
event_128_command_3B5D:
    event_jump 1821
event_128_command_3B5F:
    event_set_flag 17, 7
event_128_command_3B62:
    event_end 
event_129_command_3B63:
    event_end 
event_12A_command_3B64:
    event_end 
event_12B_command_3B65:
    event_actor_walk 8, 1, 16
event_12B_command_3B68:
    event_actor_walk 9, 1, 16
event_12B_command_3B6B:
    event_actor_walk 10, 2, 16
event_12B_command_3B6E:
    event_actor_walk 11, 3, 16
event_12B_command_3B71:
    event_actor_walk 12, 0, 16
event_12B_command_3B74:
    event_return 
event_12B_command_3B75:
    event_end 
event_12C_command_3B76:
    event_actor_walk 8, 0, 16
event_12C_command_3B79:
    event_actor_walk 9, 0, 16
event_12C_command_3B7C:
    event_actor_walk 10, 3, 16
event_12C_command_3B7F:
    event_actor_walk 11, 2, 16
event_12C_command_3B82:
    event_actor_walk 12, 1, 16
event_12C_command_3B85:
    event_return 
event_12C_command_3B86:
    event_end 
event_12D_command_3B87:
    event_actor_walk 0, 2, 0
event_12D_command_3B8A:
    event_wait 4
event_12D_command_3B8C:
    event_actor_walk 0, 3, 0
event_12D_command_3B8F:
    event_wait 4
event_12D_command_3B91:
    event_actor_walk 0, 2, 0
event_12D_command_3B94:
    event_wait 8
event_12D_command_3B96:
    event_actor_walk 0, 1, 0
event_12D_command_3B99:
    event_wait 4
event_12D_command_3B9B:
    event_return 
event_12D_command_3B9C:
    event_end 
event_12E_command_3B9D:
    event_jump 1416
event_12E_command_3B9F:
    event_end 
