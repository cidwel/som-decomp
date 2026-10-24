; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0A9D
.include "src/rom/event_command_macros.inc"
event_023_command_0A9D:
    event_call 30
