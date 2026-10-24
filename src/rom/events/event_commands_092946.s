; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2946
.include "src/rom/event_command_macros.inc"
event_106_command_2946:
    event_wait 0
