; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0E4A
.include "src/rom/event_command_macros.inc"
event_030_command_0E4A:
    event_wait 0
