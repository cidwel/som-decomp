; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6C3E
.include "src/rom/event_command_macros.inc"
event_581_command_6C3E:
    event_wait 0
