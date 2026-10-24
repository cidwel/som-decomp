; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $259E
.include "src/rom/event_command_macros.inc"
event_101_command_259E:
    event_actor_walk 0, 0, 0
