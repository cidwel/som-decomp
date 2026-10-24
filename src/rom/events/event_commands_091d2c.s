; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1D2C
.include "src/rom/event_command_macros.inc"
event_0DB_command_1D2C:
    event_call 1152
