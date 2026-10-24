; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6369
.include "src/rom/event_command_macros.inc"
event_555_command_6369:
    event_actor_walk 2, 0, 4
event_555_command_636C:
    event_wait_idle 
event_555_command_636D:
    event_wait 48
