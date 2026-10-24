; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3573
.include "src/rom/event_command_macros.inc"
event_112_command_3573:
    event_wait 0
