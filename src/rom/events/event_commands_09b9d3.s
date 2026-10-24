; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B9D3
.include "src/rom/event_command_macros.inc"
event_2B4_command_B9D3:
    event_wait 0
