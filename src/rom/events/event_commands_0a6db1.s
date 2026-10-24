; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6DB1
.include "src/rom/event_command_macros.inc"
event_581_command_6DB1:
    event_wait 0
