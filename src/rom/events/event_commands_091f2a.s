; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1F2A
.include "src/rom/event_command_macros.inc"
event_0E3_command_1F2A:
    event_wait 0
