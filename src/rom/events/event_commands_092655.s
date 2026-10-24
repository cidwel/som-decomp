; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2655
.include "src/rom/event_command_macros.inc"
event_103_command_2655:
    event_wait 12
event_103_command_2657:
    event_actor_walk 0, 1, 0
