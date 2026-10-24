; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $21EF
.include "src/rom/event_command_macros.inc"
event_4B4_command_21EF:
    event_wait 0
