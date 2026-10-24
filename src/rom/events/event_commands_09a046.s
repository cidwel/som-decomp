; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A046
.include "src/rom/event_command_macros.inc"
event_250_command_A046:
    event_call 1946
event_250_command_A048:
    event_actor_walk 1, 0, 0
event_250_command_A04B:
    event_actor_walk 2, 0, 0
event_250_command_A04E:
    event_actor_walk 3, 0, 0
event_250_command_A051:
    event_wait_idle 
