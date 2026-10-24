; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $49CE
.include "src/rom/event_command_macros.inc"
event_4EA_command_49CE:
    event_actor_walk 0, 3, 0
