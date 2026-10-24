; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $46EF
.include "src/rom/event_command_macros.inc"
event_4E9_command_46EF:
    event_actor_walk 5, 1, 0
event_4E9_command_46F2:
    event_actor_walk 0, 0, 0
