; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BCB5
.include "src/rom/event_command_macros.inc"
event_2C1_command_BCB5:
    event_wait 0
