; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A139
.include "src/rom/event_command_macros.inc"
event_258_command_A139:
    event_wait 0
