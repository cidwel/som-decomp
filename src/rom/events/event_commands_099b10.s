; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9B10
.include "src/rom/event_command_macros.inc"
event_22E_command_9B10:
    event_wait 0
