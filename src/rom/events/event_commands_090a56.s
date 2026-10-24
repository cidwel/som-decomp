; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0A56
.include "src/rom/event_command_macros.inc"
event_022_command_0A56:
    event_call 30
