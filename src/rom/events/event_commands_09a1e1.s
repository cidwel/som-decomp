; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A1E1
.include "src/rom/event_command_macros.inc"
event_259_command_A1E1:
    event_wait 0
