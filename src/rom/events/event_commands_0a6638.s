; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6638
.include "src/rom/event_command_macros.inc"
event_558_command_6638:
    event_actor_walk 1, 0, 16
event_558_command_663B:
    event_actor_walk 2, 0, 16
event_558_command_663E:
    event_actor_walk 3, 0, 16
event_558_command_6641:
    event_wait_idle 
event_558_command_6642:
    event_screen 8
event_558_command_6644:
    event_call 81
