; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $145D
.include "src/rom/event_command_macros.inc"
event_084_command_145D:
    event_actor_walk 5, 1, 0
