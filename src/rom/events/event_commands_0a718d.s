; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $718D
.include "src/rom/event_command_macros.inc"
event_587_command_718D:
    event_wait 0
