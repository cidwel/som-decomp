; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CA6E
.include "src/rom/event_command_macros.inc"
event_2F9_command_CA6E:
    event_call 1984
event_2F9_command_CA70:
    event_wait 0
