; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9BC5
.include "src/rom/event_command_macros.inc"
event_236_command_9BC5:
    event_actor_walk 3, 0, 8
event_236_command_9BC8:
    event_wait_idle 
