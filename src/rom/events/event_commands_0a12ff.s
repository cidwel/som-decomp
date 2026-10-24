; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $12FF
.include "src/rom/event_command_macros.inc"
event_429_command_12FF:
    event_wait 0
