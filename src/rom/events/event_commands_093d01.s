; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3D01
.include "src/rom/event_command_macros.inc"
event_134_command_3D01:
    event_wait 0
