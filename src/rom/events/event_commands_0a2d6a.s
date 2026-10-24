; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2D6A
.include "src/rom/event_command_macros.inc"
event_4E1_command_2D6A:
    event_wait 8
