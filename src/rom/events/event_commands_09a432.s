; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A432
.include "src/rom/event_command_macros.inc"
event_265_command_A432:
    event_wait 0
