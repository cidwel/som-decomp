; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9C39
.include "src/rom/event_command_macros.inc"
event_236_command_9C39:
    event_call 1927
event_236_command_9C3B:
    event_wait 0
