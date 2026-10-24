; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $467B
.include "src/rom/event_command_macros.inc"
event_147_command_467B:
    event_wait 0
