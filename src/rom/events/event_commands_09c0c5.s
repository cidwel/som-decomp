; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C0C5
.include "src/rom/event_command_macros.inc"
event_2D4_command_C0C5:
    event_wait 4
