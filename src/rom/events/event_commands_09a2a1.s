; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A2A1
.include "src/rom/event_command_macros.inc"
event_262_command_A2A1:
    event_wait 0
