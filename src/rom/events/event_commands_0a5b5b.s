; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5B5B
.include "src/rom/event_command_macros.inc"
event_511_command_5B5B:
    event_actor_walk 4, 1, 12
event_511_command_5B5E:
    event_wait_idle 
