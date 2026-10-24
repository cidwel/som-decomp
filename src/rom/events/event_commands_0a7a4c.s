; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7A4C
.include "src/rom/event_command_macros.inc"
event_5F8_command_7A4C:
    event_actor_walk 4, 0, 0
event_5F8_command_7A4F:
    event_actor_walk 5, 0, 0
event_5F8_command_7A52:
    event_actor_walk 6, 0, 0
event_5F8_command_7A55:
    event_wait_idle 
event_5F8_command_7A56:
    event_wait 32
