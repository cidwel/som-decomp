; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4743
.include "src/rom/event_command_macros.inc"
event_4E9_command_4743:
    event_wait 0
