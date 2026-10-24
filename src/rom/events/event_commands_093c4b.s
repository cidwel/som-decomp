; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3C4B
.include "src/rom/event_command_macros.inc"
event_130_command_3C4B:
    event_end 
event_131_command_3C4C:
    event_test_flag_range 17, 9, 15
event_131_command_3C4F:
    event_jump 309
event_131_command_3C51:
    event_actor_walk 128, 0, 0
event_131_command_3C54:
    event_actor_walk 0, 2, 8
event_131_command_3C57:
    event_wait_idle 
event_131_command_3C58:
    event_actor_walk 0, 0, 0
event_131_command_3C5B:
    event_screen 8
event_131_command_3C5D:
    event_jump 1257
event_131_command_3C5F:
    event_end 
event_132_command_3C60:
    event_actor_walk 5, 0, 16
event_132_command_3C63:
    event_actor_walk 6, 0, 0
event_132_command_3C66:
    event_actor_walk 7, 0, 0
event_132_command_3C69:
    event_actor_walk 8, 0, 0
event_132_command_3C6C:
    event_actor_walk 9, 0, 0
event_132_command_3C6F:
    event_actor_walk 10, 0, 0
event_132_command_3C72:
    event_actor_walk 11, 0, 0
event_132_command_3C75:
    event_actor_walk 12, 0, 0
event_132_command_3C78:
    event_actor_walk 0, 0, 0
event_132_command_3C7B:
    event_wait_idle 
event_132_command_3C7C:
    event_actor_walk 5, 1, 0
event_132_command_3C7F:
    event_screen 8
event_132_command_3C81:
    event_jump 1258
event_132_command_3C83:
    event_end 
event_133_command_3C84:
    event_actor_walk 0, 0, 0
event_133_command_3C87:
    event_screen 8
event_133_command_3C89:
    event_actor_animation 0, 140
event_133_command_3C8C:
    event_set_flag 10, 0
