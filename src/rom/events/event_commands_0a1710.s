; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1710
.include "src/rom/event_command_macros.inc"
event_485_command_1710:
    event_wait 8
