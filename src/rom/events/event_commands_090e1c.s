; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0E1C
.include "src/rom/event_command_macros.inc"
event_030_command_0E1C:
    event_wait 0
