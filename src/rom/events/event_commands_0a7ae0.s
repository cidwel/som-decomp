; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7AE0
.include "src/rom/event_command_macros.inc"
event_5F8_command_7AE0:
    event_actor_walk 5, 2, 0
event_5F8_command_7AE3:
    event_wait_idle 
