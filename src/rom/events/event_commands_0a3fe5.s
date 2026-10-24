; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3FE5
.include "src/rom/event_command_macros.inc"
event_4E6_command_3FE5:
    event_actor_walk 8, 1, 0
