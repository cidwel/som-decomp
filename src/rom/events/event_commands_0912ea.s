; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $12EA
.include "src/rom/event_command_macros.inc"
event_081_command_12EA:
    event_actor_walk 5, 1, 8
event_081_command_12ED:
    event_wait_idle 
