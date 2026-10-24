; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7F6F
.include "src/rom/event_command_macros.inc"
event_1DC_command_7F6F:
    event_actor_walk 2, 2, 0
event_1DC_command_7F72:
    event_wait_idle 
