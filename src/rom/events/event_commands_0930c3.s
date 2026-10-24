; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $30C3
.include "src/rom/event_command_macros.inc"
event_10C_command_30C3:
    event_actor_walk 0, 3, 24
event_10C_command_30C6:
    event_actor_walk 4, 3, 24
event_10C_command_30C9:
    event_wait_idle 
event_10C_command_30CA:
    event_actor_walk 0, 2, 0
event_10C_command_30CD:
    event_actor_walk 4, 3, 24
event_10C_command_30D0:
    event_wait_idle 
event_10C_command_30D1:
    event_actor_walk 0, 1, 24
event_10C_command_30D4:
    event_actor_walk 4, 3, 24
event_10C_command_30D7:
    event_wait_idle 
event_10C_command_30D8:
    event_actor_walk 0, 0, 0
event_10C_command_30DB:
    event_actor_walk 4, 3, 8
event_10C_command_30DE:
    event_wait_idle 
event_10C_command_30DF:
    event_actor_walk 0, 1, 18
event_10C_command_30E2:
    event_actor_walk 4, 1, 24
event_10C_command_30E5:
    event_wait_idle 
event_10C_command_30E6:
    event_actor_walk 0, 0, 0
event_10C_command_30E9:
    event_actor_walk 4, 1, 32
event_10C_command_30EC:
    event_wait_idle 
event_10C_command_30ED:
    event_actor_walk 0, 0, 0
event_10C_command_30F0:
    event_actor_walk 4, 1, 4
event_10C_command_30F3:
    event_wait_idle 
