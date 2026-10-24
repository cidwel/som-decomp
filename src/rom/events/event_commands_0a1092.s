; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1092
.include "src/rom/event_command_macros.inc"
event_429_command_1092:
    event_wait 0
