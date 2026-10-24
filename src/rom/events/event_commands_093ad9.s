; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3AD9
.include "src/rom/event_command_macros.inc"
event_127_command_3AD9:
    event_actor_walk 6, 0, 0
