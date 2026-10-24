; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5715
.include "src/rom/event_command_macros.inc"
event_4FD_command_5715:
    event_change_map 65
event_4FD_command_5717:
    event_actor_walk 1, 2, 63
event_4FD_command_571A:
    event_wait_idle 
event_4FD_command_571B:
    event_actor_walk 1, 2, 8
event_4FD_command_571E:
    event_actor_walk 4, 3, 16
event_4FD_command_5721:
    event_actor_walk 5, 3, 16
event_4FD_command_5724:
    event_actor_walk 6, 3, 16
event_4FD_command_5727:
    event_actor_walk 7, 3, 16
event_4FD_command_572A:
    event_wait_idle 
