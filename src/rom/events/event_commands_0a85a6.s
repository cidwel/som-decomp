; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $85A6
.include "src/rom/event_command_macros.inc"
event_600_command_85A6:
    event_call 1546
