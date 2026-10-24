; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $09B7
.include "src/rom/event_command_macros.inc"
event_020_command_09B7:
    event_call 30
