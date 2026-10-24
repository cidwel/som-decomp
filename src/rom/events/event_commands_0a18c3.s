; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $18C3
.include "src/rom/event_command_macros.inc"
event_4A1_command_18C3:
    event_wait 0
