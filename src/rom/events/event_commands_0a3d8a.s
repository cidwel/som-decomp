; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3D8A
.include "src/rom/event_command_macros.inc"
event_4E5_command_3D8A:
    event_wait 0
