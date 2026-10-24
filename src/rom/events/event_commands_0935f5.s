; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $35F5
.include "src/rom/event_command_macros.inc"
event_112_command_35F5:
    event_actor_walk 0, 3, 0
event_112_command_35F8:
    event_wait_idle 
