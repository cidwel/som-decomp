; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $38C9
.include "src/rom/event_command_macros.inc"
event_120_command_38C9:
    event_actor_walk 5, 3, 0
event_120_command_38CC:
    event_wait_idle 
event_120_command_38CD:
    event_actor_walk 5, 1, 0
event_120_command_38D0:
    event_wait_idle 
event_120_command_38D1:
    event_actor_walk 5, 2, 0
event_120_command_38D4:
    event_wait_idle 
event_120_command_38D5:
    event_actor_walk 5, 0, 0
event_120_command_38D8:
    event_wait_idle 
