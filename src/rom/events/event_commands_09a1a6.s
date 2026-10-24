; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A1A6
.include "src/rom/event_command_macros.inc"
event_259_command_A1A6:
    event_wait 0
