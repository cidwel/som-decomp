; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $136C
.include "src/rom/event_command_macros.inc"
event_429_command_136C:
    event_wait 0
