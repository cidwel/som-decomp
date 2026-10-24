; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $11C7
.include "src/rom/event_command_macros.inc"
event_429_command_11C7:
    event_wait 0
