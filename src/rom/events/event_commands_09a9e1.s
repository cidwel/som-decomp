; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A9E1
.include "src/rom/event_command_macros.inc"
event_28A_command_A9E1:
    event_actor_walk 1, 0, 16
event_28A_command_A9E4:
    event_actor_walk 2, 0, 32
event_28A_command_A9E7:
    event_actor_walk 3, 0, 16
event_28A_command_A9EA:
    event_wait_idle 
