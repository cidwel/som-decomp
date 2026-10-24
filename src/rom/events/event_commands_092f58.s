; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2F58
.include "src/rom/event_command_macros.inc"
event_10C_command_2F58:
    event_actor_walk 5, 2, 0
