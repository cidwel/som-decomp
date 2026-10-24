; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5AD7
.include "src/rom/event_command_macros.inc"
event_511_command_5AD7:
    event_wait 0
