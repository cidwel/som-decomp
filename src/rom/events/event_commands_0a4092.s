; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4092
.include "src/rom/event_command_macros.inc"
event_4E6_command_4092:
    event_actor_walk 8, 3, 0
