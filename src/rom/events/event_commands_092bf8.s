; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2BF8
.include "src/rom/event_command_macros.inc"
event_109_command_2BF8:
    event_wait 0
