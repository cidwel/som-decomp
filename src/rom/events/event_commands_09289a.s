; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $289A
.include "src/rom/event_command_macros.inc"
event_105_command_289A:
    event_wait 0
