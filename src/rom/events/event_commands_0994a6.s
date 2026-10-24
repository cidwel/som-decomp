; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $94A6
.include "src/rom/event_command_macros.inc"
event_212_command_94A6:
    event_wait 0
