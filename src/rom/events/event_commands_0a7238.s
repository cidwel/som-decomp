; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7238
.include "src/rom/event_command_macros.inc"
event_587_command_7238:
    event_call 1990
