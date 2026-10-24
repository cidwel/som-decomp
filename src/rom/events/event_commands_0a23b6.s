; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $23B6
.include "src/rom/event_command_macros.inc"
event_4B6_command_23B6:
    event_wait 0
