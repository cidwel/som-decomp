; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9445
.include "src/rom/event_command_macros.inc"
event_212_command_9445:
    event_wait 0
