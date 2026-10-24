; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C05A
.include "src/rom/event_command_macros.inc"
event_2D4_command_C05A:
    event_wait 0
