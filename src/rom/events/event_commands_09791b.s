; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $791B
.include "src/rom/event_command_macros.inc"
event_1D0_command_791B:
    event_wait 0
