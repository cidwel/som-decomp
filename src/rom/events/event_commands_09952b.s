; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $952B
.include "src/rom/event_command_macros.inc"
event_212_command_952B:
    event_wait 0
