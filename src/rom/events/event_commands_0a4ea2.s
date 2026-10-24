; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4EA2
.include "src/rom/event_command_macros.inc"
event_4FD_command_4EA2:
    event_actor_walk 1, 1, 0
event_4FD_command_4EA5:
    event_actor_walk 2, 0, 0
event_4FD_command_4EA8:
    event_wait_idle 
event_4FD_command_4EA9:
    event_wait 32
event_4FD_command_4EAB:
    event_call 86
event_4FD_command_4EAD:
    event_wait 32
event_4FD_command_4EAF:
    event_call 82
