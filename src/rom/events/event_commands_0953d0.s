; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $53D0
.include "src/rom/event_command_macros.inc"
event_173_command_53D0:
    event_wait 0
