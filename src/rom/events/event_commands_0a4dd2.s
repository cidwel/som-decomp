; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4DD2
.include "src/rom/event_command_macros.inc"
event_4FD_command_4DD2:
    event_actor_walk 1, 2, 8
event_4FD_command_4DD5:
    event_actor_walk 2, 3, 8
event_4FD_command_4DD8:
    event_wait_idle 
