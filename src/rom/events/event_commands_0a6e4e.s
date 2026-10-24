; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6E4E
.include "src/rom/event_command_macros.inc"
event_581_command_6E4E:
    event_call 1990
