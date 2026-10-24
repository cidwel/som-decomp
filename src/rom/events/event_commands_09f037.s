; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $F037
.include "src/rom/event_command_macros.inc"
event_3E9_command_F037:
    event_call 1951
