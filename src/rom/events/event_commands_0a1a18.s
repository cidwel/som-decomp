; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1A18
.include "src/rom/event_command_macros.inc"
event_4A3_command_1A18:
    event_wait 0
