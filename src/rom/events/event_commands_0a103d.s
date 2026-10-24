; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $103D
.include "src/rom/event_command_macros.inc"
event_429_command_103D:
    event_wait 0
