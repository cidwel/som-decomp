; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $65A4
.include "src/rom/event_command_macros.inc"
event_558_command_65A4:
    event_wait 16
