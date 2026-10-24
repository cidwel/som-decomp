; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $F034
.include "src/rom/event_command_macros.inc"
event_3E9_command_F034:
    event_wait 0
