; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $171A
.include "src/rom/event_command_macros.inc"
event_0B3_command_171A:
    event_wait 0
