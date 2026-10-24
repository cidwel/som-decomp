; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2992
.include "src/rom/event_command_macros.inc"
event_106_command_2992:
    event_wait 0
