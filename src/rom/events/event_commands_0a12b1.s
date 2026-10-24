; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $12B1
.include "src/rom/event_command_macros.inc"
event_429_command_12B1:
    event_actor_walk 2, 1, 0
event_429_command_12B4:
    event_wait_idle 
