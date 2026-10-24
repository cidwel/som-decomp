; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A6F6
.include "src/rom/event_command_macros.inc"
event_278_command_A6F6:
    event_wait 0
