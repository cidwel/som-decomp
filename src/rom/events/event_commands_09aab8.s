; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AAB8
.include "src/rom/event_command_macros.inc"
event_28B_command_AAB8:
    event_actor_walk 5, 2, 0
event_28B_command_AABB:
    event_actor_walk 6, 2, 0
event_28B_command_AABE:
    event_wait_idle 
