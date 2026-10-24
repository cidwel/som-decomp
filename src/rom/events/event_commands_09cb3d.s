; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CB3D
.include "src/rom/event_command_macros.inc"
event_2FC_command_CB3D:
    event_wait 0
