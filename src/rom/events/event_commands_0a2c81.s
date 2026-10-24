; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2C81
.include "src/rom/event_command_macros.inc"
event_4E1_command_2C81:
    event_wait 0
