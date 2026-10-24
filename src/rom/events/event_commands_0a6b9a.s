; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6B9A
.include "src/rom/event_command_macros.inc"
event_580_command_6B9A:
    event_call 1990
