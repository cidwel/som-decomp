; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6D6E
.include "src/rom/event_command_macros.inc"
event_1B9_command_6D6E:
    event_actor_walk 5, 0, 0
