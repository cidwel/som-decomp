; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1470
.include "src/rom/event_command_macros.inc"
event_42D_command_1470:
    event_wait 32
event_42D_command_1472:
    event_actor_walk 2, 0, 0
event_42D_command_1475:
    event_wait_idle 
