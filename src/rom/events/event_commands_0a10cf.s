; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $10CF
.include "src/rom/event_command_macros.inc"
event_429_command_10CF:
    event_wait 0
