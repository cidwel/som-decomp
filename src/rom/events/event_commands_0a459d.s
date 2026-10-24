; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $459D
.include "src/rom/event_command_macros.inc"
event_4E8_command_459D:
    event_wait 0
