; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3B5A
.include "src/rom/event_command_macros.inc"
event_4E4_command_3B5A:
    event_wait 0
