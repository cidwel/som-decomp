; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5ADA
.include "src/rom/event_command_macros.inc"
event_511_command_5ADA:
    event_actor_walk 4, 3, 0
event_511_command_5ADD:
    event_wait_idle 
