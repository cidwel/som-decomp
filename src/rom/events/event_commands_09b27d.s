; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B27D
.include "src/rom/event_command_macros.inc"
event_29C_command_B27D:
    event_actor_walk 12, 1, 0
event_29C_command_B280:
    event_wait_idle 
