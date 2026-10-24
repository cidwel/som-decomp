; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4A6C
.include "src/rom/event_command_macros.inc"
event_4EA_command_4A6C:
    event_actor_walk 0, 0, 0
