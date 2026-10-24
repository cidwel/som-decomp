; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $657C
.include "src/rom/event_command_macros.inc"
event_558_command_657C:
    event_wait 0
