; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4F87
.include "src/rom/event_command_macros.inc"
event_4FD_command_4F87:
    event_set_flag 247, 15
event_4FD_command_4F8A:
    event_actor_animation_loop 1, 138
event_4FD_command_4F8D:
    event_actor_animation_loop 2, 138
event_4FD_command_4F90:
    event_wait_idle 
event_4FD_command_4F91:
    event_wait 8
event_4FD_command_4F93:
    event_change_map 1000
event_4FD_command_4F95:
    event_actor_walk 1, 1, 24
event_4FD_command_4F98:
    event_actor_walk 2, 1, 16
event_4FD_command_4F9B:
    event_wait_idle 
event_4FD_command_4F9C:
    event_actor_walk 1, 1, 63
event_4FD_command_4F9F:
    event_actor_walk 2, 1, 63
event_4FD_command_4FA2:
    event_wait_idle 
event_4FD_command_4FA3:
    event_call 84
event_4FD_command_4FA5:
    event_wait 16
event_4FD_command_4FA7:
    event_actor_animation_loop 1, 138
event_4FD_command_4FAA:
    event_actor_animation_loop 2, 138
event_4FD_command_4FAD:
    event_wait_idle 
event_4FD_command_4FAE:
    event_wait 16
event_4FD_command_4FB0:
    event_call 84
event_4FD_command_4FB2:
    event_actor_walk 4, 1, 0
event_4FD_command_4FB5:
    event_actor_walk 5, 1, 0
event_4FD_command_4FB8:
    event_actor_walk 6, 1, 0
event_4FD_command_4FBB:
    event_actor_walk 7, 1, 4
event_4FD_command_4FBE:
    event_wait_idle 
event_4FD_command_4FBF:
    event_wait 16
event_4FD_command_4FC1:
    event_actor_walk 4, 1, 24
event_4FD_command_4FC4:
    event_wait_idle 
event_4FD_command_4FC5:
    event_actor_walk 4, 3, 0
event_4FD_command_4FC8:
    event_wait_idle 
