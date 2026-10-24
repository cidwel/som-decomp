; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4E67
.include "src/rom/event_command_macros.inc"
event_4FD_command_4E67:
    event_actor_walk 2, 1, 0
event_4FD_command_4E6A:
    event_wait_idle 
