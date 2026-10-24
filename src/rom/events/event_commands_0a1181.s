; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1181
.include "src/rom/event_command_macros.inc"
event_429_command_1181:
    event_actor_walk 1, 0, 8
event_429_command_1184:
    event_wait_idle 
event_429_command_1185:
    event_wait 0
