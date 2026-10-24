; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1144
.include "src/rom/event_command_macros.inc"
event_429_command_1144:
    event_actor_walk 2, 2, 0
