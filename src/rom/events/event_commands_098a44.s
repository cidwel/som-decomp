; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8A44
.include "src/rom/event_command_macros.inc"
event_1F6_command_8A44:
    event_actor_walk 1, 2, 0
event_1F6_command_8A47:
    event_wait_idle 
event_1F6_command_8A48:
    event_wait 0
