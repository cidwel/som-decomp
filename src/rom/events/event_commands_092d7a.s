; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2D7A
.include "src/rom/event_command_macros.inc"
event_10C_command_2D7A:
    event_actor_walk 5, 3, 0
event_10C_command_2D7D:
    event_wait 0
