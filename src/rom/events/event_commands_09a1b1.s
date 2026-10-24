; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A1B1
.include "src/rom/event_command_macros.inc"
event_259_command_A1B1:
    event_wait 8
