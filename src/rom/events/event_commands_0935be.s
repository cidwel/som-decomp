; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $35BE
.include "src/rom/event_command_macros.inc"
event_112_command_35BE:
    event_wait 0
