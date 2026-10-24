; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4150
.include "src/rom/event_command_macros.inc"
event_4E7_command_4150:
    event_wait 0
