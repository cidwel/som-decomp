; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8BAC
.include "src/rom/event_command_macros.inc"
event_66D_command_8BAC:
    event_call 82
