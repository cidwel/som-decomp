; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1D7A
.include "src/rom/event_command_macros.inc"
event_0DC_command_1D7A:
    event_wait 0
