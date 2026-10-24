; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A028
.include "src/rom/event_command_macros.inc"
event_250_command_A028:
    event_wait 0
