; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E9EA
.include "src/rom/event_command_macros.inc"
event_3D0_command_E9EA:
    event_wait 0
