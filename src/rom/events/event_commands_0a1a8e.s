; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1A8E
.include "src/rom/event_command_macros.inc"
event_4A3_command_1A8E:
    event_wait 0
