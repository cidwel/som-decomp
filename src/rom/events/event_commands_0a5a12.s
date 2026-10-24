; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5A12
.include "src/rom/event_command_macros.inc"
event_511_command_5A12:
    event_call 89
