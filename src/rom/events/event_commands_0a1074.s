; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1074
.include "src/rom/event_command_macros.inc"
event_429_command_1074:
    event_actor_walk 2, 0, 16
event_429_command_1077:
    event_actor_walk 3, 0, 16
event_429_command_107A:
    event_wait_idle 
event_429_command_107B:
    event_wait 8
event_429_command_107D:
    event_call 83
