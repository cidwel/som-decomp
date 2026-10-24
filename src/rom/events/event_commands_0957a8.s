; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $57A8
.include "src/rom/event_command_macros.inc"
event_181_command_57A8:
    event_freeze 
event_181_command_57A9:
    event_gather 
event_181_command_57AA:
    event_actor_walk 0, 1, 32
event_181_command_57AD:
    event_wait_idle 
event_181_command_57AE:
    event_call 1152
event_181_command_57B0:
    event_actor_walk 4, 1, 32
event_181_command_57B3:
    event_actor_walk 5, 1, 32
event_181_command_57B6:
    event_wait_idle 
event_181_command_57B7:
    event_actor_walk 4, 3, 48
event_181_command_57BA:
    event_actor_walk 5, 3, 48
event_181_command_57BD:
    event_wait_idle 
event_181_command_57BE:
    event_actor_walk 4, 3, 48
event_181_command_57C1:
    event_actor_walk 5, 3, 48
event_181_command_57C4:
    event_wait_idle 
event_181_command_57C5:
    event_actor_walk 4, 0, 63
event_181_command_57C8:
    event_actor_walk 5, 3, 32
event_181_command_57CB:
    event_wait_idle 
event_181_command_57CC:
    event_actor_walk 5, 0, 63
event_181_command_57CF:
    event_wait_idle 
event_181_command_57D0:
    event_set_flag 19, 6
event_181_command_57D3:
    event_refresh_objects 
event_181_command_57D4:
    event_end 
