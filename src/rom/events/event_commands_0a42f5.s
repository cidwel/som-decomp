; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $42F5
.include "src/rom/event_command_macros.inc"
event_4E8_command_42F5:
    event_wait 0
