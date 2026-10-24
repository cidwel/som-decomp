; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2C90
.include "src/rom/event_command_macros.inc"
event_10B_command_2C90:
    event_wait 0
