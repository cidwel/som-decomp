; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $34AE
.include "src/rom/event_command_macros.inc"
event_112_command_34AE:
    event_wait 0
