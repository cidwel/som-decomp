; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3FAD
.include "src/rom/event_command_macros.inc"
event_4E6_command_3FAD:
    event_actor_walk 6, 2, 12
