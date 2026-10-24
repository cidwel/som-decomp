; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $150E
.include "src/rom/event_command_macros.inc"
event_42D_command_150E:
    event_actor_walk 3, 1, 0
event_42D_command_1511:
    event_wait_idle 
