; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5A9F
.include "src/rom/event_command_macros.inc"
event_511_command_5A9F:
    event_actor_walk 5, 1, 16
event_511_command_5AA2:
    event_wait_idle 
event_511_command_5AA3:
    event_actor_walk 5, 2, 0
event_511_command_5AA6:
    event_wait_idle 
