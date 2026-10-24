; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3D61
.include "src/rom/event_command_macros.inc"
event_135_command_3D61:
    event_wait 0
