; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A6AF
.include "src/rom/event_command_macros.inc"
event_277_command_A6AF:
    event_actor_walk 4, 1, 0
event_277_command_A6B2:
    event_wait_idle 
