; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6D1C
.include "src/rom/event_command_macros.inc"
event_581_command_6D1C:
    event_wait 0
