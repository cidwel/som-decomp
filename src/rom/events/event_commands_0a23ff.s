; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $23FF
.include "src/rom/event_command_macros.inc"
event_4B6_command_23FF:
    event_actor_walk 2, 1, 4
event_4B6_command_2402:
    event_wait_idle 
