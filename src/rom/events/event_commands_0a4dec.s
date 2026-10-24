; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4DEC
.include "src/rom/event_command_macros.inc"
event_4FD_command_4DEC:
    event_actor_walk 1, 1, 0
event_4FD_command_4DEF:
    event_wait_idle 
