; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9448
.include "src/rom/event_command_macros.inc"
event_212_command_9448:
    event_wait 8
event_212_command_944A:
    event_call 1284
event_212_command_944C:
    event_wait 8
