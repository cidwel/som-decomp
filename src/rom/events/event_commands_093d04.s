; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3D04
.include "src/rom/event_command_macros.inc"
event_134_command_3D04:
    event_call 1051
event_134_command_3D06:
    event_restore_hero 132
