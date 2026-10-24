; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $39F1
.include "src/rom/event_command_macros.inc"
event_123_command_39F1:
    event_wait 0
