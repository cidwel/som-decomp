; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5B3D
.include "src/rom/event_command_macros.inc"
event_511_command_5B3D:
    event_actor_walk 4, 1, 0
event_511_command_5B40:
    event_wait_idle 
