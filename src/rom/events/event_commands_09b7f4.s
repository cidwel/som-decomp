; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B7F4
.include "src/rom/event_command_macros.inc"
event_2B0_command_B7F4:
    event_wait 0
