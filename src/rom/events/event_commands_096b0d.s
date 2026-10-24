; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6B0D
.include "src/rom/event_command_macros.inc"
event_1B6_command_6B0D:
    event_wait 0
