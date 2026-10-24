; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4E0E
.include "src/rom/event_command_macros.inc"
event_4FD_command_4E0E:
    event_actor_walk 2, 0, 4
event_4FD_command_4E11:
    event_wait_idle 
