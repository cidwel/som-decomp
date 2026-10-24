; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $53D8
.include "src/rom/event_command_macros.inc"
event_4FD_command_53D8:
    event_change_map 68
event_4FD_command_53DA:
    event_actor_walk 1, 1, 28
event_4FD_command_53DD:
    event_wait_idle 
event_4FD_command_53DE:
    event_actor_walk 1, 2, 12
event_4FD_command_53E1:
    event_actor_walk 2, 1, 28
event_4FD_command_53E4:
    event_wait_idle 
event_4FD_command_53E5:
    event_actor_walk 1, 1, 63
event_4FD_command_53E8:
    event_actor_walk 2, 2, 16
event_4FD_command_53EB:
    event_wait_idle 
event_4FD_command_53EC:
    event_actor_walk 1, 3, 4
event_4FD_command_53EF:
    event_actor_walk 2, 1, 56
event_4FD_command_53F2:
    event_wait_idle 
event_4FD_command_53F3:
    event_actor_walk 2, 3, 0
event_4FD_command_53F6:
    event_wait_idle 
