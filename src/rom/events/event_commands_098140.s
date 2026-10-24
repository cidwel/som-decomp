; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8140
.include "src/rom/event_command_macros.inc"
event_1DF_command_8140:
    event_call 1152
