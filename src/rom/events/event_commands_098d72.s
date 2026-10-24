; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8D72
.include "src/rom/event_command_macros.inc"
event_201_command_8D72:
    event_wait 0
