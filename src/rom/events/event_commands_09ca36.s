; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CA36
.include "src/rom/event_command_macros.inc"
event_2F9_command_CA36:
    event_wait 0
