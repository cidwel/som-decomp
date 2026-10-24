; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1488
.include "src/rom/event_command_macros.inc"
event_084_command_1488:
    event_wait 0
