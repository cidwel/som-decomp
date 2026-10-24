; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3D1A
.include "src/rom/event_command_macros.inc"
event_4E5_command_3D1A:
    event_wait 0
