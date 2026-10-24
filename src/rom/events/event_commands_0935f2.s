; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $35F2
.include "src/rom/event_command_macros.inc"
event_112_command_35F2:
    event_wait 0
