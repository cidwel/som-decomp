; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $40E3
.include "src/rom/event_command_macros.inc"
event_4E6_command_40E3:
    event_wait 0
