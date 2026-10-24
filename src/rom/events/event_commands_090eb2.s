; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0EB2
.include "src/rom/event_command_macros.inc"
event_030_command_0EB2:
    event_wait 0
