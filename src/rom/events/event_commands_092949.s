; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2949
.include "src/rom/event_command_macros.inc"
event_106_command_2949:
    event_actor_walk 6, 1, 0
