; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $F27A
.include "src/rom/event_command_macros.inc"
event_3EF_command_F27A:
    event_wait 0
