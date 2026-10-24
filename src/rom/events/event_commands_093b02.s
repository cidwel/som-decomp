; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3B02
.include "src/rom/event_command_macros.inc"
event_127_command_3B02:
    event_actor_walk 5, 1, 4
