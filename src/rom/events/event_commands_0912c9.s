; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $12C9
.include "src/rom/event_command_macros.inc"
event_081_command_12C9:
    event_actor_walk 4, 1, 2
event_081_command_12CC:
    event_wait_idle 
