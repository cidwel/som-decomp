; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1FB5
.include "src/rom/event_command_macros.inc"
event_4B3_command_1FB5:
    event_wait 0
