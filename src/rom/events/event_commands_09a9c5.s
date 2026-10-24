; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A9C5
.include "src/rom/event_command_macros.inc"
event_28A_command_A9C5:
    event_wait 0
