; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6E69
.include "src/rom/event_command_macros.inc"
event_581_command_6E69:
    event_wait 16
event_581_command_6E6B:
    event_wait 0
event_581_command_6E6D:
    event_actor_walk 3, 1, 0
event_581_command_6E70:
    event_actor_walk 1, 2, 0
event_581_command_6E73:
    event_wait_idle 
event_581_command_6E74:
    event_call 1993
