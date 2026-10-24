; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5BBA
.include "src/rom/event_command_macros.inc"
event_511_command_5BBA:
    event_wait 0
