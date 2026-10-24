; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7CE6
.include "src/rom/event_command_macros.inc"
event_1D8_command_7CE6:
    event_wait 2
