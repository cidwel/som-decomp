; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3A73
.include "src/rom/event_command_macros.inc"
event_4E4_command_3A73:
    event_actor_walk 5, 2, 8
