; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D58D
.include "src/rom/event_command_macros.inc"
event_36F_command_D58D:
    event_actor_walk 5, 1, 16
event_36F_command_D590:
    event_wait_idle 
