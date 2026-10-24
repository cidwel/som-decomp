; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $719A
.include "src/rom/event_command_macros.inc"
event_1C6_command_719A:
    event_wait 0
