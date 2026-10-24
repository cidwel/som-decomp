; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1448
.include "src/rom/event_command_macros.inc"
event_084_command_1448:
    event_wait 0
