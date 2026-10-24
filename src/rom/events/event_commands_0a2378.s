; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2378
.include "src/rom/event_command_macros.inc"
event_4B6_command_2378:
    event_actor_walk 3, 1, 4
event_4B6_command_237B:
    event_wait_idle 
