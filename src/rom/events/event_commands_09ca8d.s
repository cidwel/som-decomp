; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CA8D
.include "src/rom/event_command_macros.inc"
event_2F9_command_CA8D:
    event_wait 0
