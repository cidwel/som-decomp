; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9C1A
.include "src/rom/event_command_macros.inc"
event_236_command_9C1A:
    event_actor_animation 3, 0
event_236_command_9C1D:
    event_wait_idle 
event_236_command_9C1E:
    event_call 1927
