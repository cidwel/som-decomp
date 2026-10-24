; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $63B0
.include "src/rom/event_command_macros.inc"
event_555_command_63B0:
    event_actor_walk 1, 0, 8
event_555_command_63B3:
    event_actor_walk 3, 0, 8
event_555_command_63B6:
    event_wait_idle 
event_555_command_63B7:
    event_screen 8
