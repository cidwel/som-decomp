; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $12E7
.include "src/rom/event_command_macros.inc"
event_081_command_12E7:
    event_wait 0
