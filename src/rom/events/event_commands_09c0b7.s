; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C0B7
.include "src/rom/event_command_macros.inc"
event_2D4_command_C0B7:
    event_wait 16
