; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3A9B
.include "src/rom/event_command_macros.inc"
event_127_command_3A9B:
    event_actor_walk 0, 3, 16
event_127_command_3A9E:
    event_actor_walk 5, 2, 0
