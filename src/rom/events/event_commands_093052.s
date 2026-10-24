; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3052
.include "src/rom/event_command_macros.inc"
event_10C_command_3052:
    event_wait 0
