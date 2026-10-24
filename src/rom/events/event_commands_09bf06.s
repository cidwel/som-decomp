; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BF06
.include "src/rom/event_command_macros.inc"
event_2D1_command_BF06:
    event_wait 0
