; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9A0D
.include "src/rom/event_command_macros.inc"
event_22E_command_9A0D:
    event_wait 0
