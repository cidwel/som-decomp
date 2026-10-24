; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $118E
.include "src/rom/event_command_macros.inc"
event_429_command_118E:
    event_wait 32
