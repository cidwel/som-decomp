; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $137F
.include "src/rom/event_command_macros.inc"
event_429_command_137F:
    event_actor_walk 3, 3, 0
event_429_command_1382:
    event_wait_idle 
