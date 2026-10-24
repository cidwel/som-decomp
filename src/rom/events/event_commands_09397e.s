; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $397E
.include "src/rom/event_command_macros.inc"
event_121_command_397E:
    event_wait 0
