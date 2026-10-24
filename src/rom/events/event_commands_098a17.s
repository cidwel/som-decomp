; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8A17
.include "src/rom/event_command_macros.inc"
event_1F6_command_8A17:
    event_actor_walk 1, 3, 0
event_1F6_command_8A1A:
    event_wait_idle 
