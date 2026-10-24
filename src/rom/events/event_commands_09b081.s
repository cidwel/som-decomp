; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B081
.include "src/rom/event_command_macros.inc"
event_29B_command_B081:
    event_actor_animation 1, 140
event_29B_command_B084:
    event_actor_animation 3, 140
event_29B_command_B087:
    event_wait_idle 
event_29B_command_B088:
    event_actor_walk 4, 1, 16
event_29B_command_B08B:
    event_actor_walk 5, 1, 16
event_29B_command_B08E:
    event_wait_idle 
event_29B_command_B08F:
    event_actor_walk 4, 2, 63
event_29B_command_B092:
    event_actor_walk 5, 2, 63
event_29B_command_B095:
    event_actor_walk 1, 2, 0
event_29B_command_B098:
    event_actor_walk 3, 2, 0
event_29B_command_B09B:
    event_wait_idle 
event_29B_command_B09C:
    event_actor_walk 4, 2, 16
event_29B_command_B09F:
    event_actor_walk 5, 2, 16
event_29B_command_B0A2:
    event_wait_idle 
event_29B_command_B0A3:
    event_actor_walk 4, 1, 63
event_29B_command_B0A6:
    event_actor_walk 5, 1, 63
event_29B_command_B0A9:
    event_wait_idle 
event_29B_command_B0AA:
    event_actor_walk 4, 1, 16
event_29B_command_B0AD:
    event_actor_walk 5, 1, 16
event_29B_command_B0B0:
    event_wait_idle 
event_29B_command_B0B1:
    event_increment_flag 40
event_29B_command_B0B3:
    event_refresh_objects 
event_29B_command_B0B4:
    event_actor_walk 1, 2, 0
event_29B_command_B0B7:
    event_actor_walk 3, 3, 0
event_29B_command_B0BA:
    event_wait_idle 
