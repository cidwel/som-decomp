; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3099
.include "src/rom/event_command_macros.inc"
event_10C_command_3099:
    event_actor_walk 0, 3, 24
event_10C_command_309C:
    event_actor_walk 4, 1, 22
event_10C_command_309F:
    event_wait_idle 
event_10C_command_30A0:
    event_actor_walk 0, 2, 0
event_10C_command_30A3:
    event_actor_walk 4, 3, 0
event_10C_command_30A6:
    event_wait_idle 
