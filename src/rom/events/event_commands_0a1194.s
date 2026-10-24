; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1194
.include "src/rom/event_command_macros.inc"
event_429_command_1194:
    event_actor_walk 3, 1, 0
event_429_command_1197:
    event_wait_idle 
