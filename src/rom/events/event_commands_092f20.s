; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2F20
.include "src/rom/event_command_macros.inc"
event_10C_command_2F20:
    event_actor_walk 4, 2, 0
