; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6E49
.include "src/rom/event_command_macros.inc"
event_1B9_command_6E49:
    event_actor_walk 5, 2, 0
