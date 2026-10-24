; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5B0A
.include "src/rom/event_command_macros.inc"
event_511_command_5B0A:
    event_actor_walk 4, 2, 0
event_511_command_5B0D:
    event_actor_walk 6, 3, 0
event_511_command_5B10:
    event_wait_idle 
