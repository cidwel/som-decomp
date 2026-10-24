; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0E83
.include "src/rom/event_command_macros.inc"
event_030_command_0E83:
    event_wait 0
