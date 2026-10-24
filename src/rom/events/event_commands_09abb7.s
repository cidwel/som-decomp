; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $ABB7
.include "src/rom/event_command_macros.inc"
event_28B_command_ABB7:
    event_actor_walk 5, 2, 0
event_28B_command_ABBA:
    event_actor_walk 6, 3, 0
event_28B_command_ABBD:
    event_wait_idle 
