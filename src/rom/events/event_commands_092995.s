; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2995
.include "src/rom/event_command_macros.inc"
event_106_command_2995:
    event_actor_walk 5, 3, 0
event_106_command_2998:
    event_actor_walk 6, 2, 0
event_106_command_299B:
    event_wait_idle 
