; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2420
.include "src/rom/event_command_macros.inc"
event_4B6_command_2420:
    event_call 88
