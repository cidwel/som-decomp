; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1150
.include "src/rom/event_command_macros.inc"
event_429_command_1150:
    event_actor_walk 3, 0, 0
event_429_command_1153:
    event_wait 0
