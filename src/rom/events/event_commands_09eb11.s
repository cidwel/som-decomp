; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EB11
.include "src/rom/event_command_macros.inc"
event_3D4_command_EB11:
    event_wait 0
