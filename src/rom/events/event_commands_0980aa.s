; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $80AA
.include "src/rom/event_command_macros.inc"
event_1DD_command_80AA:
    event_wait 0
