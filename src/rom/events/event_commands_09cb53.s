; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CB53
.include "src/rom/event_command_macros.inc"
event_2FD_command_CB53:
    event_actor_walk 128, 0, 0
event_2FD_command_CB56:
    event_wait_idle 
