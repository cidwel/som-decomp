; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $353D
.include "src/rom/event_command_macros.inc"
event_4E2_command_353D:
    event_wait 0
