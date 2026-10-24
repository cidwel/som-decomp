; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $38E5
.include "src/rom/event_command_macros.inc"
event_120_command_38E5:
    event_actor_walk 4, 1, 0
