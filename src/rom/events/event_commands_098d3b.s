; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8D3B
.include "src/rom/event_command_macros.inc"
event_201_command_8D3B:
    event_wait 0
