; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3F38
.include "src/rom/event_command_macros.inc"
event_4E6_command_3F38:
    event_wait 0
