; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $136F
.include "src/rom/event_command_macros.inc"
event_429_command_136F:
    event_call 90
