; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B1DC
.include "src/rom/event_command_macros.inc"
event_29C_command_B1DC:
    event_actor_walk 12, 2, 0
event_29C_command_B1DF:
    event_wait_idle 
