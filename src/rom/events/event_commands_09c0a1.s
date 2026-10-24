; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C0A1
.include "src/rom/event_command_macros.inc"
event_2D4_command_C0A1:
    event_wait 0
