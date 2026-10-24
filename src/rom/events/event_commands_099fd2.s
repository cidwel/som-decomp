; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9FD2
.include "src/rom/event_command_macros.inc"
event_250_command_9FD2:
    event_actor_walk 3, 0, 32
event_250_command_9FD5:
    event_wait_idle 
event_250_command_9FD6:
    event_call 1854
event_250_command_9FD8:
    event_wait 16
