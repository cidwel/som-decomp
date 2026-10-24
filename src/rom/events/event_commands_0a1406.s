; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1406
.include "src/rom/event_command_macros.inc"
event_429_command_1406:
    event_wait 32
