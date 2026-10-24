; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $242B
.include "src/rom/event_command_macros.inc"
event_4B6_command_242B:
    event_wait 0
