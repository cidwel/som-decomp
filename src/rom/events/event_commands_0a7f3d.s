; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7F3D
.include "src/rom/event_command_macros.inc"
event_5F8_command_7F3D:
    event_wait 0
