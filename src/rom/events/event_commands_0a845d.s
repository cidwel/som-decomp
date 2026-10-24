; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $845D
.include "src/rom/event_command_macros.inc"
event_5F8_command_845D:
    event_wait 32
event_5F8_command_845F:
    event_actor_walk 2, 2, 0
event_5F8_command_8462:
    event_actor_walk 3, 3, 0
event_5F8_command_8465:
    event_wait_idle 
event_5F8_command_8466:
    event_wait 0
