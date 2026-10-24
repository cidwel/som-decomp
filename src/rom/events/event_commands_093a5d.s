; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3A5D
.include "src/rom/event_command_macros.inc"
event_126_command_3A5D:
    event_increment_flag 16
event_126_command_3A5F:
    event_jump 1535
event_126_command_3A61:
    event_end 
event_127_command_3A62:
    event_increment_flag 166
event_127_command_3A64:
    event_call 1937
event_127_command_3A66:
    event_call 1932
event_127_command_3A68:
    event_redraw_pieces 
event_127_command_3A69:
    event_increment_flag 1
event_127_command_3A6B:
    event_actor_walk 0, 0, 56
event_127_command_3A6E:
    event_wait_idle 
event_127_command_3A6F:
    event_actor_walk 0, 0, 56
event_127_command_3A72:
    event_wait_idle 
event_127_command_3A73:
    event_screen 8
event_127_command_3A75:
    event_actor_walk 0, 3, 0
event_127_command_3A78:
    event_wait 8
event_127_command_3A7A:
    event_actor_walk 0, 2, 0
event_127_command_3A7D:
    event_wait 8
event_127_command_3A7F:
    event_actor_walk 6, 0, 60
event_127_command_3A82:
    event_actor_walk 0, 3, 0
event_127_command_3A85:
    event_wait 8
event_127_command_3A87:
    event_decrement_flag 1
