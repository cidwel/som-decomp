; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $20D1
.include "src/rom/event_command_macros.inc"
event_4B3_command_20D1:
    event_wait 0
