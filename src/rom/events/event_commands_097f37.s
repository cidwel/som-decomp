; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7F37
.include "src/rom/event_command_macros.inc"
event_1DC_command_7F37:
    event_actor_walk 1, 3, 0
event_1DC_command_7F3A:
    event_wait_idle 
