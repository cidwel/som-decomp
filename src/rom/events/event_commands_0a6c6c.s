; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6C6C
.include "src/rom/event_command_macros.inc"
event_581_command_6C6C:
    event_wait 0
