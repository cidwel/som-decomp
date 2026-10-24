; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $682D
.include "src/rom/event_command_macros.inc"
event_55E_command_682D:
    event_actor_walk 4, 1, 8
event_55E_command_6830:
    event_wait_idle 
event_55E_command_6831:
    event_call 96
event_55E_command_6833:
    event_wait 0
