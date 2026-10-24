; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8309
.include "src/rom/event_command_macros.inc"
event_5F8_command_8309:
    event_actor_walk 1, 1, 8
