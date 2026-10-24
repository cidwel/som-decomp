; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6F8C
.include "src/rom/event_command_macros.inc"
event_583_command_6F8C:
    event_wait 16
event_583_command_6F8E:
    event_wait 0
