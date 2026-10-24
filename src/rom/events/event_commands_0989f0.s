; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $89F0
.include "src/rom/event_command_macros.inc"
event_1F6_command_89F0:
    event_wait 0
