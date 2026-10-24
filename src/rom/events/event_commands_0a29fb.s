; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $29FB
.include "src/rom/event_command_macros.inc"
event_4E0_command_29FB:
    event_wait 0
