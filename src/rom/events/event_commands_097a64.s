; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7A64
.include "src/rom/event_command_macros.inc"
event_1D4_command_7A64:
    event_wait 0
