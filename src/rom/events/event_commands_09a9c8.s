; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A9C8
.include "src/rom/event_command_macros.inc"
event_28A_command_A9C8:
    event_actor_walk 2, 0, 0
event_28A_command_A9CB:
    event_wait_idle 
