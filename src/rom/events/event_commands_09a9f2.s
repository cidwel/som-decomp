; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A9F2
.include "src/rom/event_command_macros.inc"
event_28A_command_A9F2:
    event_wait 0
