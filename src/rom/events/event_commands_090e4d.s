; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0E4D
.include "src/rom/event_command_macros.inc"
event_030_command_0E4D:
    event_actor_walk 128, 0, 0
event_030_command_0E50:
    event_wait 0
