; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A9AD
.include "src/rom/event_command_macros.inc"
event_28A_command_A9AD:
    event_actor_walk 1, 1, 0
event_28A_command_A9B0:
    event_wait_idle 
