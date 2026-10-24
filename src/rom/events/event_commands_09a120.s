; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A120
.include "src/rom/event_command_macros.inc"
event_258_command_A120:
    event_wait 16
