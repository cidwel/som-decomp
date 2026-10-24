; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BFE9
.include "src/rom/event_command_macros.inc"
event_2D4_command_BFE9:
    event_call 96
