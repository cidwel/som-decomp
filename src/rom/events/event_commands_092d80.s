; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2D80
.include "src/rom/event_command_macros.inc"
event_10C_command_2D80:
    event_actor_walk 6, 3, 0
