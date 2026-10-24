; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7BB7
.include "src/rom/event_command_macros.inc"
event_1D4_command_7BB7:
    event_call 2004
event_1D4_command_7BB9:
    event_wait 0
