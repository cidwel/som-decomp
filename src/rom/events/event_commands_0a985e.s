; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $985E
.include "src/rom/event_command_macros.inc"
event_7FE_command_985E:
    event_wait 8
