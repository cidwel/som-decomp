; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EC12
.include "src/rom/event_command_macros.inc"
event_3D9_command_EC12:
    event_wait 0
