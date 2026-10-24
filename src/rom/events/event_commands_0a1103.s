; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1103
.include "src/rom/event_command_macros.inc"
event_429_command_1103:
    event_wait 16
