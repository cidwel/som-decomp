; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $85AB
.include "src/rom/event_command_macros.inc"
event_600_command_85AB:
    event_call 1548
