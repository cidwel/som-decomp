; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B48A
.include "src/rom/event_command_macros.inc"
event_2A3_command_B48A:
    event_wait 0
