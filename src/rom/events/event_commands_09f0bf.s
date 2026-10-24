; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $F0BF
.include "src/rom/event_command_macros.inc"
event_3EB_command_F0BF:
    event_wait 0
