; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CA53
.include "src/rom/event_command_macros.inc"
event_2F9_command_CA53:
    event_wait 0
