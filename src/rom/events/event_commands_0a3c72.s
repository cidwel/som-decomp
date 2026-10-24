; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3C72
.include "src/rom/event_command_macros.inc"
event_4E5_command_3C72:
    event_actor_walk 4, 1, 32
