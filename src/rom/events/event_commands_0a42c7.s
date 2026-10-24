; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $42C7
.include "src/rom/event_command_macros.inc"
event_4E8_command_42C7:
    event_actor_walk 5, 0, 8
